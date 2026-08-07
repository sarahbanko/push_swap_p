#include "stack/stack.h"
#include <stdio.h>
#include "operations/operations.h"
#include "algorithms/algorithms.h"
#include <time.h>
#include <stdlib.h>


/*static void	print_stack(t_stack *stack, char name)
{
	t_node	*current;
	int		count;

	printf("\nStack %c — size: %d\n", name, stack->size);
	if (!stack->top)
	{
		printf("(vazia)\n");
		return ;
	}
	current = stack->top;
	count = 0;
	while (count < stack->size)
	{
		printf("content: %d | index: %d\n",
			current->content, current->index);
		current = current->next;
		count++;
	}
}*/

static void	shuffle_numbers(int *numbers, int size)
{
	int	i;
	int	random;
	int	temp;

	i = size - 1;
	while (i > 0)
	{
		random = rand() % (i + 1);
		temp = numbers[i];
		numbers[i] = numbers[random];
		numbers[random] = temp;
		i--;
	}
}

static int	is_sorted(t_stack *stack)
{
	t_node	*current;
	int		count;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	count = 0;
	while (count < stack->size - 1)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
		count++;
	}
	return (1);
}

static void	fill_stack(t_stack *a, int *numbers, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack_push_bottom(a, new_node(numbers[i]));
		i++;
	}
}

int	main(void)
{
	t_stack	*a;
	t_stack	*b;
	int		numbers[500];
	int		count_op;
	int		i;

	a = stack_init();
	b = stack_init();
	if (!a || !b)
		return (1);
	i = 0;
	while (i < 500)
	{
		numbers[i] = i;
		i++;
	}
	srand(time(NULL));
	shuffle_numbers(numbers, 500);
	fill_stack(a, numbers, 500);
	printf("Desordem inicial: %.2f%%\n", compute_disorder(a));
	index_stack(a);
	count_op = chunk_sort(a, b);
	printf("\nTOTAL: %d operações\n", count_op);
	printf("A ordenada: %s\n", is_sorted(a) ? "SIM" : "NAO");
	printf("Tamanho de A: %d\n", a->size);
	printf("Tamanho de B: %d\n", b->size);
	stack_free(a);
	stack_free(b);
	return (0);
}