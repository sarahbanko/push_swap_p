/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 16:04:17 by adrperei          #+#    #+#             */
/*   Updated: 2026/08/07 16:04:20 by adrperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parser.h"
#include "parser_utils.h"
#include "ft_utils.h"
#include <stdlib.h>

static int	flag_err(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

static int	parse_flags(int argc, char **argv, t_strategy *s, int *b)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (match_flag(argv[i], "--simple"))
				*s = SIMPLE;
			else if (match_flag(argv[i], "--medium"))
				*s = MEDIUM;
			else if (match_flag(argv[i], "--complex"))
				*s = COMPLEX;
			else if (match_flag(argv[i], "--adaptive"))
				*s = ADAPTIVE;
			else if (match_flag(argv[i], "--bench"))
				*b = 1;
			else
				return (flag_err());
		}
		i++;
	}
	return (1);
}

static t_stack	*cleanup(t_stack *a)
{
	stack_free(a);
	ft_putstr_fd("Error\n", 2);
	return (NULL);
}

static int	add_num(t_stack *a, char *arg)
{
	t_node	*n;
	int		v;

	if (!is_valid_int(arg, &v))
		return (0);
	if (has_duplicate(a, v))
		return (0);
	n = new_node(v);
	if (!n)
		return (-1);
	stack_push_top(a, n);
	return (1);
}

t_stack	*parse_args(int argc, char **argv, t_strategy *s, int *b)
{
	t_stack	*a;
	int		i;

	*s = ADAPTIVE;
	*b = 0;
	if (!parse_flags(argc, argv, s, b))
		return (NULL);
	a = stack_init();
	if (!a)
		return (NULL);
	i = argc;
	while (--i >= 1)
		if (argv[i][0] != '-' || argv[i][1] != '-')
			if (!add_num(a, argv[i]))
				return (cleanup(a));
	return (a);
}
