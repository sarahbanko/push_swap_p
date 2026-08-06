/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 13:08:39 by sarahbanko        #+#    #+#             */
/*   Updated: 2026/08/06 17:26:37 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

static void	init_chunk(t_chunk *chunk, int size)
{
	chunk->count = square_root(size);
	chunk->base_size = size / chunk->count;
	chunk->remainder = size % chunk->count;
	chunk->elements = chunk->base_size;
	if (chunk->remainder > 0)
		chunk->elements++;
	chunk->start = 0;
	chunk->end = chunk->elements - 1;
	chunk->current = 0;
}

int	chunk_sort(t_stack *a, t_stack *b)
{
	t_chunk	chunk;
	int		count_op;

	if (!a || !b || a->size < 2)
		return (0);
	init_chunk(&chunk, a->size);
	count_op = 0;
	while (chunk.current < chunk.count)
	{
		count_op += process_chunk(a, b, chunk.start, chunk.end);
		chunk.current++;
		chunk.start = chunk.end + 1;
		chunk.elements = chunk.base_size;
		if (chunk.current < chunk.remainder)
			chunk.elements++;
		chunk.end = chunk.start + chunk.elements - 1;
	}
	return (count_op);
}

int organize_stack_b(t_stack *a, t_stack *b)
{
   t_node *current;
   int dist_top;
   int dist_bottom;
   int current_index;
   int count_op;
   
   if (!a || !b || b->size == 0)
		return (0);
   
    current_index = b->size - 1;
    count_op = 0;
    while (b->size > 0)
    {
        current = b->top;
        dist_top = 0;
        while (current->index != current_index)
        {
            dist_top++;
            current = current->next;
        }
    
        dist_bottom = 1;
        current = b->top->prev;
        while (current->index != current_index)
        {
            dist_bottom++;
            current = current->prev;
        }
    
        if (dist_top < dist_bottom)
        {
            while (b->top->index != current_index)
            {    
                rb(b);
                count_op++;
			}
            pa(a, b);
            count_op++;
            current_index--;
        }
        else
        {
            while(b->top->index != current_index)
            {
                rrb(b);
                count_op++;
            }
            pa(a, b);
            count_op++;
            current_index--;
        }
    }
    return (count_op);
}
