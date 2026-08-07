/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_wired.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 16:03:49 by adrperei          #+#    #+#             */
/*   Updated: 2026/08/07 16:03:50 by adrperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "args_builder.h"
#include "parsing/parsing.h"
#include "stack/stack.h"
#include "operations/operations.h"
#include "algorithms/algorithms.h"

// verifica se a stack A ja esta ordenada (crescente)
// anda pela lista circular checando se cada content <= proximo->content
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

// escolhe e executa o algoritmo de ordenacao baseado na estrategia
// --simple: insertion_sort (bom pra poucos elementos)
// --medium ou --complex: chunk_sort + organize_stack_b
// --adaptive (padrao): insertion_sort pra <=5, chunk_sort pra >5
static void	sort_stack(t_stack *a, t_stack *b, t_strategy strat)
{
	if (is_sorted(a))
		return ;
	index_stack(a);
	if (strat == SIMPLE)
		insertion_sort(a, b);
	else if (strat == MEDIUM || strat == COMPLEX)
	{
		chunk_sort(a, b);
		organize_stack_b(a, b);
	}
	else // ADAPTIVE: escolhe baseado no tamanho
	{
		if (a->size <= 5)
			insertion_sort(a, b);
		else
		{
			chunk_sort(a, b);
			organize_stack_b(a, b);
		}
	}
}

// fluxo principal:
// 1. build_args: junta tudo e separa por espacos (lida com "1 2" e 1 2)
// 2. parse_args: valida cada argumento e monta a stack A
// 3. sort_stack: escolhe o algoritmo e ordena
// 4. libera tudo
int	main(int argc, char **argv)
{
	t_strategy	strat; // estrategia de ordenacao (--simple, --medium, etc)
	int			bench; // flag de benchmarking (nao usado por enquanto)
	t_stack		*a; // pilha principal
	t_stack		*b; // pilha auxiliar
	char		**new_args; // argumentos processados pelo build_args
	int			new_argc; // quantidade de argumentos depois do build_args

	new_args = build_args(argc, argv, &new_argc);
	if (!new_args)
		return (1);
	a = parse_args(new_argc, new_args, &strat, &bench);
	free_args(new_args, new_argc); // libera os argumentos, a stack ja foi criada
	if (!a)
		return (1);
	b = stack_init();
	if (!b)
	{
		stack_free(a);
		return (1);
	}
	sort_stack(a, b, strat);
	stack_free(a);
	stack_free(b);
	return (0);
}
