#include "push_swap.h"

#include <stdio.h>
void show_array(int *tab, int size)
{
    int i;

    i = -1;
    while (++i < size)
        printf("%d ", tab[i]);
    printf("\n");
}

int main(int argc, char **argv)
{
	t_array *ar = argv_to_array(argc, argv);
	show_array(ar->stack_a, ar->size_stack_a);
	show_array(ar->full_sorted, ar->size_stack_a);
	show_array(ar->chunck, ar->nbr_chunck + 1);
    return 0;
}