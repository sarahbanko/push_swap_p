/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarahbanko <sarahbanko@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:20:35 by sarahbanko        #+#    #+#             */
/*   Updated: 2026/08/07 12:49:02 by adrperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// apenas (tentar) adicionar na stack a, passamos a char* da argv**
// bem basico, eh valido? eh duplicado? se nao, cria um node e coloca na stack
static	int add_num(t_stack *a, char *arg)
{
	t_node	*node;
	int	value;

	if (!is_valid_int(arg, &value))
		return (0);
	if (has_duplicate(a, value))
		return (0);
	node = new_node(value);
	if (!node)
		return (-1);
	stack_push_top(a, node);
	return (1);
}

static t_stack *cleanup(t_stack *a) // funcao dificil pra sarah entende
{
	stack_free(a);
	write(2, "Error\n", 6);
	return (NULL);
}

t_stack *parse_args(int argc, char **argv)
{
	t_stack	*a;
	int	i;

	a = stack_init();
	if (!a)
		return (NULL);
	i = argc;
	while (--i >= 1)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
			continue ;
		if (!add_num(a, argv[i]))
			return (cleanup(a));
	}
	return (a);
}
