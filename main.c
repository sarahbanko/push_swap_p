#include "stack/stack.h"
#include <stdio.h>
#include "operations/operations.h"
#include "algorithms/algorithms.h"
#include <time.h>
#include <stdlib.h>


int	main(void)
{
    t_stack *a;
    t_stack *b;
    t_node *node_a1;
    int     operations;
    double disorder;
    int count;
    int random_num;


    count = 5;
    a = stack_init();
    srand((unsigned int)time(NULL));
    while (count >= 0)
    {
        random_num = (rand() % (2147483647 - 1 + 1)) + 1;
        node_a1 = new_node(random_num);
        stack_push_bottom(a, node_a1);
        count--;
    }

    b = stack_init();
    
    disorder = compute_disorder(a);
    operations = insertion_sort(a, b);

    //stack_print(a);
    printf("disorder: %.2f", disorder);
    printf("\n");
    printf("quantidade de operações realizadas: %d\n", operations);
    printf("\n");


    stack_free(a);

    stack_free(b);
    return (0);
}

/* TESTE ALGORITMO SIMPLES:
- msm quando a pilha ja esta ordenada continua fazendo operações; adicionar verificação para caso a pilha esteja ordenada, não fazer nada
*/