#include "stack/stack.h"
#include <stdio.h>
#include "operations/operations.h"
#include "algorithms/algorithms.h"
#include <time.h>
#include <stdlib.h>

static void	print_stack_with_index(t_stack *s)
{
	t_node	*current;
	int		count;

	if (!s || !s->top)
		return ;
	current = s->top;
	count = 0;
	while (count < s->size)
	{
		printf("content: %d | index: %d\n", current->content, current->index);
		current = current->next;
		count++;
	}
}

int main()
{
    t_stack *a;

    a = stack_init();
    if (!a)
        return (1);
    stack_push_bottom(a, new_node(42));
    stack_push_bottom(a, new_node(-10));
    stack_push_bottom(a, new_node(100));
    stack_push_bottom(a, new_node(7));
    stack_push_bottom(a, new_node(25));

    index_stack(a);

    print_stack_with_index(a);

    stack_free(a);

    return (0);
}
