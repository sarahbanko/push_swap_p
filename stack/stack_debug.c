
#include "stack.h"
#include <stdio.h>

void	stack_print(t_stack *s)
{
	t_node	*node_top;
	int		temp_size;

	if (!s)
		return ;
	node_top = s->top;
	temp_size = s->size;
	while (temp_size)
	{
		printf("%d\n", node_top->content);
		node_top = node_top->next;
		temp_size--;
	}
}