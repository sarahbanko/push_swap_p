/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 13:22:25 by sbanko            #+#    #+#             */
/*   Updated: 2026/07/21 16:58:34 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_node *new_node(int value)
{
	t_node *new_node;
	
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->content = value;
	new_node->prev = new_node;
	new_node->next = new_node;
	return (new_node);
}

void	stack_push_top(t_stack *s, int value)
{
	t_node	*node_top;
	t_node	*last_node;

	node_top = new_node(value);
	if (!s->top)
	{
		s->top = node_top;
		s->size++;
		return ;
	}
	if (s && s->top != NULL)
	{
		last_node = s->top->prev;
		
		node_top->next = s->top;
		node_top->prev = s->top->prev;
		
		s->top->prev = node_top;
		last_node->next = node_top;
		s->top = node_top;
		s->size++;
	}
}

void	stack_push_bottom(t_stack *s, int value)
{
	t_node	*node_bottom;
	t_node	*temp;

	node_bottom = new_node(value);
	if (!s->top)
	{
		s->top = node_bottom;
		s->size++;
		return ;
	}
	if (s && s->top != NULL)
	{
		temp = s->top->prev;

		node_bottom->next = s->top;
		node_bottom->prev = s->top->prev;

		s->top->prev = node_bottom;
		temp->next = node_bottom;
		s->size++;
	}
	
}