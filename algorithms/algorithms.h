
#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "../operations/operations.h"

double compute_disorder(t_stack *s);
int	insertion_sort(t_stack *a, t_stack *b);
int square_root(int n);
int	find_top_distance_a(t_stack *a, int start, int end);
int	find_bottom_distance_a(t_stack *a, int start, int end);
int	move_chunk_to_top_a(t_stack *a, int start, int end);
int	process_chunk(t_stack *a, t_stack *b, int start, int end);
int find_top_distance_b(t_stack *b, int current_index);
int find_bottom_distance_b(t_stack *b, int current_index);
int push_stack_a(t_stack *b, int current_index);
int move_b_to_a(t_stack *a, t_stack *b);
int chunk_sort(t_stack *a, t_stack *b);

typedef struct s_chunk
{
	int	count;
	int	base_size;
	int	remainder;
	int	start;
	int	end;
	int	elements;
	int	current;
}	t_chunk;

#endif