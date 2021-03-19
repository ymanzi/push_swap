#	ifndef PUSH_SWAP_H
#	define PUSH_SWAP_H

#include "libft/libft.h"
#include "libft/get_next_line.h"

typedef struct	s_array
{
	int		*stack_a;
	int		*stack_b;
	size_t	size_stack_a;
	size_t	size_stack_b;
}				t_array;

int				ft_is_all_digit(char *str);
void			free_array(t_array *arr);
t_array			*argv_to_array(int argc, char **argv);

/*
** Swap.c
*/

void			ft_swap(int *a, int *b);
void			sa(t_array *array);
void			sb(t_array *array);
void			ss(t_array *array);

/*
** Push.c
*/

void			pa(t_array *array);
void			pb(t_array *array);

/*
** Rotate.c
*/

void			ra(t_array *array);
void			rb(t_array *array);
void			rr(t_array *array);

/*
** Reverse_Rotate.c
*/

void			rra(t_array *array);
void			rrb(t_array *array);
void			rrr(t_array *array);

/*
**	Check.c
*/
int				check_double(int argc, char **argv);
int				check_int_min_max(char *str);
int				check_argv(int argc, char **argv);
int				check_read(char *operation);

#	endif
