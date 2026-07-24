/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 13:00:12 by sbanko            #+#    #+#             */
/*   Updated: 2026/07/23 11:51:09 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;
	
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack -> top = NULL;
	stack -> size = 0;
	return (stack);
}

void	stack_free(t_stack *s)
{
	t_node	*temp;
	t_node	*current_node; //para fazer a comparação do nó que esta
	t_node	*last_node;
	
	if (!s)
		return ;
	if (!s->top) // tem que ver se a pilha não esta vazia. Se estiver, não tem nó, mas ainda tem liberar a estrutura da pilha
	{
		free(s);
		return ;
	}
	current_node = s->top; // temos que ter a temporaria pq assim que limpamos o primeiro nó, perdemos a referência do top
	last_node = s->top->prev; // temos que ter a temporaria para o ultimo nó pq após limpar o primeiro nó que é o top, perde a referência para o ultimo nó
	while (current_node != last_node) // tem que comparar se o nó atual é o ultimo, quando for sai e libera o ultimo depois do loop
	{
		temp = current_node->next;
		free(current_node);
		current_node = temp;
	}
	free(current_node); //libero uma vez so, pq quando sair do loop 
	// current_node = last_node (apontam para o mesmo endereço)
	free(s);
}