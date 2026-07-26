/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarahbanko <sarahbanko@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:17:32 by sbanko            #+#    #+#             */
/*   Updated: 2026/07/25 12:45:52 by sarahbanko       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

void	insertion_sort(t_stack *a, t_stack *b)
{
	int	count;

	while (a->size > 0)
	{
		if (!b->top)
			pb(b, a);
		else if (a->top->content > b->top->content)
			pb(b, a);
		else if (a->top->content < b->top->prev->content)
		{
			pb(b, a);
			rb(b);
		}
		else
		{
			count = 0;
			while (b->top->content > a->top->content)
			{
				rb(b);
				count++;
			}
			pb(b, a);
			while (count-- > 0)
			{
				rrb(b);
			}		
		}
	}
	while (b->size > 0)
	{
		pa(a, b);
	}
}