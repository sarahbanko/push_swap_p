/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarahbanko <sarahbanko@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 13:08:39 by sarahbanko        #+#    #+#             */
/*   Updated: 2026/08/05 20:33:54 by sarahbanko       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

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
    while (count_current < s->size)
    {
        smaller = 0; // ver quantos elementos são menores do que o atual
        count = 0; // para garantir que o loop passa por todos os elementos
        next = current->next;
        while (count < s->size)
        {
            if (next->content < current->content)
                smaller++; // se o proximo for menor, aumenta++
            next = next->next; //avança para o proximo
            count++;
        }
        current->index = smaller; // atribui o index
        count_current++;
        current = current->next; 
    }
}

int square_root(int n)
{
    int root;

    if (n <= 0)
        return (0);
    root = 1;
    while (root <= n / root) // colocamos dividindo para evitar overflow de multiplicação (maior q int)
        root++;
    return (root - 1);
}

int chunk_sort(t_stack *a, t_stack *b)
{
    int total_size;
    int chunk_count;
    int base_chunk_size;
    int remainder;
    int chunk_start;
    int chunk_end;
    int chunk_elements;
    int chunk_sent;
    int range;
    int current_chunk;

    t_node *current;
    t_node *next;

    if (!a || !b || a->size < 2)
        return (0);
    total_size = a->size; // guardar o tamanho total, pq ela vai ser alterada a medida q enviamos os elementos
    chunk_count = square_root(a->size); // quantos chunks serão necessários
    base_chunk_size = total_size / chunk_count; // quantos elementos tem dentro de cada chunk
    remainder = total_size % chunk_count; //quanto sobra

    chunk_elements = base_chunk_size;
    if (remainder > 0)
        chunk_elements++;
    
    chunk_start = 0; //inicio do primeiro chunk
    chunk_end = chunk_start + chunk_elements - 1; //final
    current_chunk = 0;

    
    while (current_chunk < chunk_count)
    {
        chunk_sent = 0;
        while (chunk_sent < chunk_elements) // definição do range de cada chunk
        {
            // criar o loop passando por toda a stack procurando o index que se encaixa no range
            current = a->top;
            while (!(current->index >= chunk_start && current->index <= chunk_end))
            {
                 
            }
                    
               
        }
        current_chunk++;
        
    }
}