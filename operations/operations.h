#ifndef OPERATIONS_H
# define OPERATIONS_H

#include "../stack/stack.h"

void    swap(t_stack *s);
void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *b, t_stack *a);
void    rotate(t_stack *s);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    rev_rotate(t_stack *s);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);

#endif