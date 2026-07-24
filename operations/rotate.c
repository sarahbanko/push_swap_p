#include "operations.h"

void    rotate(t_stack *s)
{
    t_node  *first_node;

    if (!s)
        return ;
    first_node = stack_pop_top(s);
    stack_push_bottom(s, first_node);
}

void    ra(t_stack *a)
{
    if (a->top == a->top->next)
        return ;
    rotate(a);
    write(1, "ra\n", 3);
}

void    rb(t_stack *b)
{
    if (b->top == b->top->next)
        return ;
    rotate(b);
    write(1, "rb\n", 3);
}

void    rr(t_stack *a, t_stack *b)
{
    if (!a && !b)
        return ;
    if (!a->top && !b->top)
        return ;
    if ((a->top == a->top->next) && (b->top == b->top->next))
        return ;
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}