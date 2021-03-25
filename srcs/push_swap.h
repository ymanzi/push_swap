#	ifndef PUSH_SWAP_H
#	define PUSH_SWAP_H

#include "../libft/libft.h"
#include "../libft/get_next_line.h"

typedef struct	s_array
{
	int		*stack_a;
	int		*stack_b;
	int		*full_sorted;
	int		*chunck;
	int		indice_chunck;
	int		size_stack_a;
	int		size_stack_b;
	int		nbr_chunck;
}				t_array;

int				ft_is_all_digit(char *str);
void			free_array(t_array *arr);
t_array			*argv_to_array(int argc, char **argv);
int				get_size_argv(char **tab);

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

/*
** Quick_sort.c
*/

void			quick_sort(int *tab, int left, int right);
int				order_pivot(int *tab, int left, int right);

/*
** checker.c
*/
void			make_operation_on_array(t_array *array, char *operation);
int				error_handling(t_array *array, char *line, int ind);
int				check_sorted(t_array *array);
void			show_stack(t_array *array);

/*
** Closest_and_move.c
*/
int				closest_nbr_from_chunk_top(t_array *ar, int i_chunck, char i_stack);
int				closest_nbr_from_chunk_bottom(t_array *ar, int i_chunck, char i_stack);
int				move_from_top(t_array *array, int number, char ind_stack);
int				move_from_bottom(t_array *array, int number, char ind_stack);
void			make_move(int times, char *operation, t_array *array);

/*
**	Get_set.c
*/
void			set_stack_and_size(t_array *ar, int **stack, int *size, char ind_stack);
int				get_chunck_from_number(t_array *ar, int value);
int				get_minmax(t_array *ar, char i_stack, char *kind);
void			bring_num_above(t_array *ar, char *kind, char i_stack);
int				max_or_min(t_array *ar);
/*
** Utils.c
*/
int				just_digit_and_space(char *str);
void			free_double_tab(char **tab);
/*
** sort_3_5.c
*/
void			sort_3(t_array *ar);
void			sort_5(t_array *ar);

#	endif
