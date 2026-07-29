/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 11:30:22 by sbanko            #+#    #+#             */
/*   Updated: 2026/07/29 14:57:19 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack/stack.h"
#include "operations/operations.h"
#include "algorithms/algorithms.h"

int main()
{

	t_stack *numbers = stack_init(); 
	t_stack *b = stack_init();
	t_node * t5 = new_node(4);
	t_node * t4 = new_node(5);
	t_node * t3 = new_node(3);
	t_node * t2 = new_node(2);
	t_node * t1 = new_node(1);
	double disorder;
	int operations;

	
	stack_push_top(numbers, t5);
	stack_push_top(numbers, t4);
	stack_push_top(numbers, t3);
	stack_push_top(numbers, t2);
	stack_push_top(numbers, t1);
	
	disorder = compute_disorder(numbers);
	printf("disorder: %.2f", disorder);
	printf("\n");
	//stack_print(numbers);
	operations = insertion_sort(numbers, b);
	printf("quantidade de operacoes: %d", operations);
	//stack_print(numbers);
}