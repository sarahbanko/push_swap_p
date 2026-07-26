/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarahbanko <sarahbanko@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 12:26:15 by sarahbanko        #+#    #+#             */
/*   Updated: 2026/07/26 12:26:16 by sarahbanko       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

double compute_disorder(t_stack *s)
{
    int mistakes;
    int total_pairs;
    t_node  *current;
    t_node  *next;

    if (!s)
        return (0);
    if (s->size == 0 || s->size == 1)
        return (0);
    mistakes = 0;
    total_pairs = 0;
    current = s->top;
    while (current->next != s->top) // como a lista é circular, depois do ultimo é o top
    {
        next = current->next; // recomeça para comparar o next com o novo atual
        while (next != s->top)
        {
            total_pairs += 1;
            if (current->content > next->content)
                mistakes += 1;
            next = next->next; // para andar com o next e mantem o current parado para fazer todas as comparações
        }
        current = current->next;
    }
    return ((double)mistakes/total_pairs);
}

/*double  compute_disorder(int *a, int size) // double - pq o resultado tem casas decimais
{
    int mistakes;
    int total_pairs;
    int i;
    int j;

    mistakes = 0;
    total_pairs = 0;
    i = 0;
    if (size == 0 || size == 1) // temos que fazer, pq total_pairs = 0, daria erro na divisão do return final
        return (0);
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            total_pairs += 1;
            if (a[i] > a[j])
                mistakes += 1;
            j++;
        }
        i++;
    }
    return ((double)mistakes / total_pairs); // converter int p/ double antes da divisao
}


for i from 0 to size(a)-1:
for j from i+1 to size(a)-1:
total_pairs += 1
if a[i] > a[j]:
mistakes += 1
return mistakes / total_pairs

loop externo: i = 0 até (size - 1)
loop interno:  j = (i + 1) até (size - 1) */