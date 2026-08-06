/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 17:15:51 by sbanko            #+#    #+#             */
/*   Updated: 2026/08/06 16:02:09 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void index_stack(t_stack *s)
{
    int smaller;
    int count;
    int count_current;
    t_node *current;
    t_node *next;

    if (!s || !s->top) 
        return ;
    count_current = 0; //contar quantos elementos
    current = s->top;
    while (++count_current <= s->size)
    {
        smaller = 0; // ver quantos elementos são menores do que o atual
        count = 0; // para garantir que o loop passa por todos os elementos
        next = current->next;
        while (++count < s->size)
        {
            if (next->content < current->content)
                smaller++; // se o proximo for menor, aumenta++
            next = next->next; //avança para o proximo
        }
        current->index = smaller; // atribui o index
        current = current->next; 
    }
}