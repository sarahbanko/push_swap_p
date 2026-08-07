/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:50:00 by sbanko            #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args_builder.h"
#include "parsing/parsing.h"
#include "stack/stack.h"
#include "operations/operations.h"
#include "algorithms/algorithms.h"

// verifica se a stack A ja esta ordenada (crescente)
// anda pela lista circular checando se cada content <= proximo->content
// se a pilha tem 0 ou 1 elementos, ja esta ordenada
static int	is_sorted(t_stack *a)
{
	t_node	*node; // bookmark pra andar na lista
	int		pos; // contador de voltas

	if (!a || a->size <= 1)
		return (1);
	node = a->top;
	pos = 0;
	while (pos < a->size - 1)
	{
		if (node->content > node->next->content)
			return (0); // achou um par fora de ordem
		node = node->next;
		pos++;
	}
	return (1); // deu a volta inteira, tudo em ordem
}

// libera o array de argumentos criado pelo build_args
// pula o args[0] porque eh o argv[0] original (nao alocado por nos)
static void	free_args(char **args, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
		free(args[i++]);
	free(args);
}

// fluxo principal:
// 1. build_args: junta tudo e separa por espacos (lida com "1 2" e 1 2)
// 2. parse_args: valida cada argumento e monta a stack A
// 3. is_sorted: se ja ta ordenado, nao faz nada
// 4. index_stack: atribui indices de 0 a n-1 baseado no valor
// 5. escolhe o algoritmo: insertion_sort pra <=5, chunk_sort pra >5
// 6. libera tudo
int	main(int argc, char **argv)
{
	t_stack	*a; // pilha principal
	t_stack	*b; // pilha auxiliar
	char	**new_args; // argumentos processados pelo build_args
	int		new_argc; // quantidade de argumentos depois do build_args

	new_args = build_args(argc, argv, &new_argc);
	if (!new_args)
		return (1);
	a = parse_args(new_argc, new_args);
	free_args(new_args, new_argc); // libera os argumentos, a stack ja foi criada
	if (!a)
		return (1);
	if (is_sorted(a)) // ja esta ordenada, nao precisa fazer nada
	{
		stack_free(a);
		return (0);
	}
	b = stack_init();
	if (!b)
	{
		stack_free(a);
		return (1);
	}
	index_stack(a); // atribui indices pra todos os nodes
	if (a->size <= 5)
		insertion_sort(a, b);
	else
	{
		chunk_sort(a, b);
		organize_stack_b(a, b);
	}
	stack_free(a);
	stack_free(b);
	return (0);
}
