/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:17:32 by sbanko            #+#    #+#             */
/*   Updated: 2026/07/24 17:33:59 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

void	insertion_sort(t_stack *a, t_stack *b)
{
	int	count;

	while (a->size > 0)
	{
		if (!b->top)
			pb(a, b);
		else if (a->top->content > b->top->content)
			pb(a, b);
		else if (a->top->content < b->top->prev->content)
		{
			pb(a, b);
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
			pb(a, b);
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