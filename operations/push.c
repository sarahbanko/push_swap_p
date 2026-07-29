#include "operations.h"

void    pa(t_stack *a, t_stack *b)
{
    if (!a || !b || b->size == 0)
        return ;
    stack_push_top(a, stack_pop_top(b));
    write(1, "pa\n", 3);
}

void    pb(t_stack *b, t_stack *a)
{
    if (!a || !b || a->size == 0)
        return ;
    stack_push_top(b, stack_pop_top(a));
    write(1, "pb\n", 3);
}
