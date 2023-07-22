/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:47:18 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/07/22 20:20:53 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *a)
{
	t_node	*temp;

	temp = a -> first;
	a -> first = temp -> next;
	temp -> next = a -> first -> next;
	a -> first -> next = temp;
	temp -> prev = a -> first;
	if (temp -> next)
		temp -> next -> prev = temp;
	a -> first -> prev = NULL;
	ft_putstr_fd("sa\n", 1);
}

void	ft_push(t_stack *from, t_stack *to, char *print)
{
	t_node	*node;

	node = from -> first;
	from -> first = node -> next;
	from -> len -= 1;
	lst_add_front(&(to->first), node);
	to -> last = lst_last(to->first);
	to -> len += 1;
	if (from -> first)
		from -> first -> prev = NULL;
	ft_putstr_fd(print, 1);
}

void	ft_ra_rb(t_stack *x, int print)
{
	t_node	*node;

	node = x -> first;
	x -> first = node -> next;
	node -> next = NULL;
	x -> first -> prev = NULL;
	x -> last = node;
	lst_add_back(&(x->first), node);
	if (print == 1)
		ft_putstr_fd("ra\n", 1);
	else if (print == 2)
		ft_putstr_fd("rb\n", 1);
}

void	ft_revra_revrb(t_stack *x, int print)
{
	t_node	*node;

	node = x -> last;
	x -> last = node -> prev;
	x -> last -> next = NULL;
	lst_add_front(&(x->first), node);
	if (print == 1)
		ft_putstr_fd("rra\n", 1);
	else if (print == 2)
		ft_putstr_fd("rrb\n", 1);
}

void	ft_rr_rrr(t_stack *a, t_stack *b, int specifier)
{
	if (specifier == 2)
	{
		ft_ra_rb(a, 0);
		ft_ra_rb(b, 0);
		ft_putstr_fd("rr\n", 1);
	}
	else if (specifier == 3)
	{
		ft_revra_revrb(a, 0);
		ft_revra_revrb(b, 0);
		ft_putstr_fd("rrr\n", 1);
	}
}
