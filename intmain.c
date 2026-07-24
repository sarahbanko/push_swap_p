/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 11:30:22 by sbanko            #+#    #+#             */
/*   Updated: 2026/07/24 15:11:01 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack/stack.h"
#include "operations/operations.h"
#include "algorithms/algorithms.h"

int main()
{

	t_stack *numbers = stack_init(); 
	t_node * t6 = new_node(0);
	t_node * t5 = new_node(5);
	t_node * t4 = new_node(7);
	t_node * t3 = new_node(4);
	t_node * t2 = new_node(54);
	t_node * t1 = new_node(123);
	
	stack_push_top(numbers, t6);
	stack_push_top(numbers, t5);
	stack_push_top(numbers, t4);
	stack_push_top(numbers, t3);
	stack_push_top(numbers, t2);
	stack_push_top(numbers, t1);
	
	//stack_print(numbers);
	insertion_sort(numbers);
	//stack_print(numbers);
}