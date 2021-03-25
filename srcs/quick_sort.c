#include "push_swap.h"

int		order_pivot(int *tab, int left, int right)
{
	int	low;
	int	high;
	int	pivot;

	low = left - 1;
	high = left - 1;
	pivot = tab[right];
	while (++high < right)
	{
		if (tab[high] < pivot)
			ft_swap(&tab[high], &tab[++low]);
	}
	ft_swap(&tab[low + 1], &tab[right]);
	return (low + 1);
}

void	quick_sort(int *tab, int left, int right)
{
	int	pivot;

	if (left < right)
	{
		pivot = order_pivot(tab, left, right);
		quick_sort(tab, left, pivot - 1);
		quick_sort(tab, pivot + 1, right);
	}
}
