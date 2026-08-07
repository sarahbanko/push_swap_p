/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 16:04:47 by adrperei          #+#    #+#             */
/*   Updated: 2026/08/07 16:04:49 by adrperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parsing.h"
#include "ft_utils.h"
#include <stdlib.h>

// imprime "Error" e retorna 0, usada quando uma flag desconhecida aparece
static int	flag_err(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

// escaneia todos os argv procurando flags que comecam com "--"
// reconhece: --simple, --medium, --complex, --adaptive, --bench
// se encontrar uma flag desconhecida, retorna 0 (erro)
static int	parse_flags(int argc, char **argv, t_strategy *strat, int *bench)
{
	int	i; // anda nos argumentos

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-') // eh uma flag
		{
			if (match_flag(argv[i], "--simple"))
				*strat = SIMPLE;
			else if (match_flag(argv[i], "--medium"))
				*strat = MEDIUM;
			else if (match_flag(argv[i], "--complex"))
				*strat = COMPLEX;
			else if (match_flag(argv[i], "--adaptive"))
				*strat = ADAPTIVE;
			else if (match_flag(argv[i], "--bench"))
				*bench = 1;
			else
				return (flag_err()); // flag nao reconhecida
		}
		i++;
	}
	return (1); // todas as flags processadas com sucesso
}

// libera a stack e imprime erro, usada quando a validacao falha
// retorna NULL pra propagar o erro em uma linha so
static t_stack	*cleanup(t_stack *a)
{
	stack_free(a);
	ft_putstr_fd("Error\n", 2);
	return (NULL);
}

// tenta adicionar um argumento na stack
// retorna: 1 = ok, 0 = erro do usuario, -1 = erro de malloc
static int	add_num(t_stack *a, char *arg)
{
	t_node	*node; // o node que vai ser criado
	int		value; // o valor convertido do argumento

	if (!is_valid_int(arg, &value)) // string invalida (letras, overflow, etc)
		return (0);
	if (has_duplicate(a, value)) // numero ja esta na stack
		return (0);
	node = new_node(value); // aloca o node
	if (!node)
		return (-1); // malloc falhou
	stack_push_top(a, node); // insere no topo
	return (1); // sucesso
}

// funcao principal do parser: valida todos os argumentos e monta a stack A
// processa os argumentos de tras pra frente porque cada push vai pro topo
// assim o argv[1] fica no topo da stack (ordem original)
t_stack	*parse_args(int argc, char **argv, t_strategy *strat, int *bench)
{
	t_stack	*a; // a pilha que vamos construir
	int		i; // iterador, comeca no fim e volta

	*strat = ADAPTIVE; // estrategia padrao se nenhuma flag for passada
	*bench = 0; // benchmarking desligado por padrao
	if (!parse_flags(argc, argv, strat, bench)) // processa as flags primeiro
		return (NULL);
	a = stack_init(); // cria a stack vazia
	if (!a)
		return (NULL);
	i = argc;
	while (--i >= 1) // itera de tras pra frente
	{
		if (argv[i][0] != '-' || argv[i][1] != '-') // nao eh flag
			if (!add_num(a, argv[i])) // tenta adicionar
				return (cleanup(a)); // se falhar, limpa tudo e retorna erro
	}
	return (a); // stack pronta
}
