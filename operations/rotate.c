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
    rotate(a);
    write(1, "ra\n", 3);
}

void    rb(t_stack *b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void    rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
    write(1, "rr\n", 3);
}