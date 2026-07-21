/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 13:00:12 by sbanko            #+#    #+#             */
/*   Updated: 2026/07/21 16:59:13 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;
	
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack -> top = NULL;
	stack -> size = 0;
	return (stack);
}

t_stack *stack_free(void)
{
	
}