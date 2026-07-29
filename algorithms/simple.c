/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:17:32 by sbanko            #+#    #+#             */
/*   Updated: 2026/07/29 11:08:00 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

int	insertion_sort(t_stack *a, t_stack *b)
{
	int	count;
	int count_op;
	
	count_op = 0;
	while (a->size > 0)
	{
		if (!b->top)
		{
			pb(b, a);
			count_op++;
		}
		else if (a->top->content > b->top->content)
		{
			pb(b, a);
			count_op++;
		}
		else if (a->top->content < b->top->prev->content)
		{
			pb(b, a);
			count_op++;
			rb(b);
			count_op++;
		}
		else
		{
			count = 0;
			while (b->top->content > a->top->content)
			{
				rb(b);
				count++;
				count_op++;
			}
			pb(b, a);
			count_op++;
			while (count-- > 0)
			{
				rrb(b);
				count_op++;
			}		
		}
	}
	while (b->size > 0)
	{
		pa(a, b);
		count_op++;
	}
	return (count_op);
}