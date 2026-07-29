#include "operations.h"

void    swap(t_stack *s)
{
    t_node  *temp;
    t_node  *temp_2;

    if (!s || s->size < 2) // se tiver menos q 2 elementos nem acontece
        return ;
    temp = stack_pop_top(s);
    temp_2 = stack_pop_top(s);
    stack_push_top(s, temp);
    stack_push_top(s, temp_2);
}

void    sa(t_stack *a)
{
    if (!a || a->size < 2)
        return ;
    swap(a);
    write(1, "sa\n", 3);
}

void    sb(t_stack *b)
{
    if (!b || b->size < 2) // se caso não tiver pelo menos 02 elementos ja sai
        return ;
    swap(b);
    write(1, "sb\n", 3); 
}

void    ss(t_stack *a, t_stack *b)
{
    if (!a || !b)
        return ;
    if (a->size < 2 && b->size < 2)
	    return ;
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}
