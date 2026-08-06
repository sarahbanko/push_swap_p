/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarahbanko <sarahbanko@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:54:28 by sbanko            #+#    #+#             */
/*   Updated: 2026/08/05 14:23:09 by sarahbanko       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

#include <stddef.h>//olhar
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_node {
	int	content;
	int index; // para receber o index
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
void	stack_print(t_stack *s);

#endif 

