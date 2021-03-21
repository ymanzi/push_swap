#include "push_swap.h"

int		just_digit_and_space(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
			return (0);
	}
	return (1);
}

void	free_double_tab(char **tab)
{
	int	i;

	i = -1;
	while(tab[++i])
		free(tab[i]);
	free(tab);
}
