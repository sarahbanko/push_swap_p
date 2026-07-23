/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarahbanko <sarahbanko@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:54:28 by sbanko            #+#    #+#             */
/*   Updated: 2026/07/22 19:49:39 by sarahbanko       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

#include <stddef.h>//olhar

typedef struct s_node {
	int	content;
	struct s_node *next;
	struct s_node *prev;
} t_node;

typedef struct s_stack {
	t_node *top;
	int size;
} t_stack;

t_node *new_node(int value);
void	stack_push_top(t_stack *s, t_node *node);
void	stack_push_bottom(t_stack *s, t_node *node);
t_node	*stack_pop_top(t_stack *s);
t_node	*stack_pop_bottom(t_stack *s);
t_stack	*stack_init(void);
void	stack_free(t_stack *s);

#endif 

