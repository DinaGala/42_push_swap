/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:06:56 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/07/22 20:24:22 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				data;
	long			ind;
	long			ops;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	long			len;
	struct s_node	*first;
	struct s_node	*last;
}	t_stack;

/****** ft_check_parse.c  -- main, check and parse ***************************/
int		arg_check(char **argv, int argc, t_stack *a);
int		check_dup(t_node **head_a, t_node *cur); 
int		ft_atoi(char *str, int *nb);
/*int	main(int argc, char **argv);*/
/*_______________________________________________________*/

/****** ft_sort.c  -- all the sortig algorithms ******************************/
void	push_swap(t_stack *a, t_stack *b); 
void	tiny_sort(t_stack *x);
void	huge_sort(t_stack *a, t_stack *b, t_node *target);
void	back_sort(t_stack *a, t_stack *b, t_node *target);
void	simple_sort(t_stack *a);
/*_______________________________________________________*/

/****** ft_lists.c  -- standart list operations ******************************/
void	lst_add_back(t_node **head_stack, t_node *new_n);
void	lst_add_front(t_node **head_stack, t_node *new_n);
t_node	*lst_last(t_node *head);
t_node	*lst_new(t_stack *a, int res);
/*_______________________________________________________*/

/****** ft_utils.c  -- additional function ***********************************/
int		ft_putstr_fd(char *s, int fd);
int		clean_up(t_node **head, t_stack *a, int print); 
int		check_sort(t_node *head);
long	fill_ops(t_stack *from, t_stack *to, int bol);
long	find_pos(t_node *cur, long index);
/*_______________________________________________________*/

/****** ft_moves.c  -- the push_swap language operations *********************/
void	ft_swap(t_stack *a);
void	ft_push(t_stack *from, t_stack *to, char *print);
void	ft_ra_rb(t_stack *x, int print);
void	ft_revra_revrb(t_stack *x, int print);
void	ft_rr_rrr(t_stack *a, t_stack *b, int specifier); 
/*_______________________________________________________*/

/****** ft_budget.c  -- calculations to find best movements ******************/
long	count_price(t_stack *from, t_stack *to, long index, int bol);
long	find_dest(t_node *cur, long index, int bol);
long	find_min_or_max(t_node *cur, int bol);
long	best_price(long rfr, long revfr, long rto, long revto);
long	ft_max(long from, long to);
/*_______________________________________________________*/

/****** ft_engine.c  -- commands to realize the optimal set of operations ****/
void	case_rot(t_stack *a, t_stack *b, long ra, long rb);
void	case_revrot(t_stack *a, t_stack *b, long rra, long rrb);
void	case_rra_rb(t_stack *a, t_stack *b, long rra, long rb);
void	case_ra_rrb(t_stack *a, t_stack *b, long ra, long rrb);
/*_______________________________________________________*/

#endif
