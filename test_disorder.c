#include "stack/stack.h"
#include "algorithms/algorithms.h"
#include <stdio.h>

static void	fill_stack(t_stack *stack, int *values, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack_push_bottom(stack, new_node(values[i]));
		i++;
	}
}

static void	run_test(int *values, int size, double expected)
{
	t_stack	*stack;
	double	result;

	stack = stack_init();
	if (!stack)
		return ;
	fill_stack(stack, values, size);
	result = compute_disorder(stack);
	printf("Resultado: %.6f | Esperado: %.6f\n", result, expected);
	stack_free(stack);
}

int	main(void)
{
	int	ordered[] = {1, 2, 3};
	int	reversed[] = {3, 2, 1};
	int	partial[] = {3, 1, 2};
	int	single[] = {42};

	printf("Ordenada:\n");
	run_test(ordered, 3, 0.0);

	printf("\nInvertida:\n");
	run_test(reversed, 3, 1.0);

	printf("\nParcialmente desordenada:\n");
	run_test(partial, 3, 2.0 / 3.0);

	printf("\nUm elemento:\n");
	run_test(single, 1, 0.0);

	printf("\nStack vazia:\n");
	run_test(NULL, 0, 0.0);
	return (0);
}