#include "stack.h"

t_node	*stack_pop_top(t_stack *s)
{
    t_node  *last_node;
    t_node  *new_top;
    t_node  *pop_top;

    if (!s || !s->top)
        return (NULL);
    pop_top = s->top; // temp para o endereço do nó a ser retirado
    last_node = s->top->prev; // temp para a referencia do top prev após tirar o elemento do top
    new_top = s->top->next;
    if (s->size > 1) // caso a pilha tenha mais de um nó
    {
        s->top = new_top;
        new_top->prev = last_node;
        last_node->next = new_top;
        s->size--;
    }
    else if (s->size == 1) // caso a pilha tenha apenas um nó
    {
        s->top = NULL;
        s->size--;
    }
    pop_top->prev = NULL; // precisamos desconectar o nó que vamos retornar
    pop_top->next = NULL; // perguntar na 42 se é melhor deixá-lo isolado mesmo
    return (pop_top);
}

t_node	*stack_pop_bottom(t_stack *s)
{
    t_node  *pop_bottom;
    t_node  *last_node;

    if (!s || !s->top)
        return (NULL);
    pop_bottom = s->top->prev; // nó que vai ser retirado
    if (s->size > 1)
    {
        s->top->prev = pop_bottom->prev; //conectando o nó do top ao novo ultimo nó 
        last_node = pop_bottom->prev; // endereço do novo ultimo nó
        last_node->next = s->top; // conectando o novo ultimo ao top
        s->size--;
    }
    else if (s->size == 1)
    {
        s->top = NULL;
        s->size--;
    }
    pop_bottom->prev = NULL; // desconectando os nós 
    pop_bottom->next = NULL;
    return (pop_bottom);
}

