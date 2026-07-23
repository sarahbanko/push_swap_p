/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarahbanko <sarahbanko@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 13:22:25 by sbanko            #+#    #+#             */
/*   Updated: 2026/07/22 19:49:21 by sarahbanko       ###   ########.fr       */
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

void	stack_push_top(t_stack *s, t_node *node)
{
	t_node	*last_node;

	if (!s) // faltou ver se s existe
		return ;
	if (!s->top)
	{
		s->top = node;
		s->size++;
		return ;
	}
	// tirei o if, pois como ja sabemos q existe um nó e a lista tb existe, ele fica redundante. No primeiro if, quando ele cria, ja sai da função
	last_node = s->top->prev;
		
	node->next = s->top;
	node->prev = s->top->prev;
	
	s->top->prev = node;
	last_node->next = node;
	s->top = node;
	s->size++;

}

void	stack_push_bottom(t_stack *s, t_node *node)
{
	t_node	*temp;

	if (!s)
		return ;
	if (!s->top)
	{
		s->top = node;
		s->size++;
		return ;
	}
	temp = s->top->prev;

	node->next = s->top;
	node->prev = s->top->prev;

	s->top->prev = node;
	temp->next = node;
	s->size++;
}