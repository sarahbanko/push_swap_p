#include "operations.h"

void    rev_rotate(t_stack *s)
{
    t_node  *last_node;

    if (!s)
        return ;
    last_node = stack_pop_bottom(s);
    stack_push_top(s, last_node);
}

void    rra(t_stack *a)
{
    rev_rotate(a);
    write(1, "rra\n", 4);
}

void    rrb(t_stack *b)
{
    rev_rotate(b);
    write(1, "rrb\n", 4);
}

void    rrr(t_stack *a, t_stack *b)
{
    rra(a);
    rrb(b);
    write(1, "rrr\n", 4);
}