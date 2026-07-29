#include "stack/stack.h"
#include <stdio.h>
#include "operations/operations.h"
#include "algorithms/algorithms.h"

int	main(void)
{
	t_stack *a;
    /*t_node *node_a1;
    t_node *node_a2;
    t_node *node_a3;
    t_node *node_a4;
    t_node *node_a5; */

    t_stack *b;
    /*t_node *node_1;
    t_node *node_2;
    t_node *node_3; */

    a = stack_init();
    /*node_a2 = new_node(-1);
    node_a1 = new_node(3);
    node_a3 = new_node(5);
    node_a4 = new_node(0);
    node_a5 = new_node(2); 
    stack_push_bottom(a, node_a1);
    stack_push_bottom(a, node_a2);
    stack_push_bottom(a, node_a3);
    stack_push_bottom(a, node_a4);
    stack_push_bottom(a, node_a5); */


    b = stack_init();
    /*
    node_1 = new_node(5);
    node_2 = new_node(7);
    node_3 = new_node(4);
    stack_push_bottom(b, node_1);
    stack_push_bottom(b, node_2);
    stack_push_bottom(b, node_3); */

    
    insertion_sort(a, b);

    stack_print(a);
    printf("\n");
    printf("size a: %d\n", a->size);
    printf("size b: %d\n", b->size);

    stack_free(a);

    stack_free(b);
    return (0);
}

/* TESTE ALGORITMO SIMPLES:
- msm quando a pilha ja esta ordenada continua fazendo operações; adicionar verificação para caso a pilha esteja ordenada, não fazer nada
*/