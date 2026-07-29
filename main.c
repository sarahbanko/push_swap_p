#include "stack/stack.h"
#include <stdio.h>

int	main(void)
{
	t_stack	*s;
	t_node	*top;
	t_node	*bottom;

	s = stack_init();
	if (!s)
		return (1);
	top = stack_pop_top(s);
	bottom = stack_pop_bottom(s);
	printf("pop top == NULL: %d\n", top == NULL);
	printf("pop bottom == NULL: %d\n", bottom == NULL);
	printf("size: %d\n", s->size);
	printf("stack top == NULL: %d\n", s->top == NULL);
	stack_free(s);
	return (0);
}