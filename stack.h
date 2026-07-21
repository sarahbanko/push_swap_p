/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:54:28 by sbanko            #+#    #+#             */
/*   Updated: 2026/07/21 16:32:52 by sbanko           ###   ########.fr       */
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


#endif 

