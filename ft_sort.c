/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:27:29 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/07/22 20:25:37 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_stack *a)
{
	long	pos;

	pos = find_pos(a->first, a->len - 1);
	if (pos < a->len / 2)
	{
		while (!check_sort(a->first))
			ft_ra_rb(a, 1);
	}
	else
	{
		while (!check_sort(a->first))
			ft_revra_revrb(a, 1);
	}
}

void	back_sort(t_stack *a, t_stack *b, t_node *target)
{
	long	min;
	long	ra;
	long	rb;

	min = fill_ops(b, a, 2);
	while (target -> ops > min)
		target = target -> next;
	if (target -> ind < find_min_or_max(a->first, -1) || \
			target -> ind > find_min_or_max(a->first, 1))
		ra = find_pos(a->first, find_min_or_max(a->first, -1));
	else
		ra = find_dest(a->first, target->ind, 2) + 1;
	rb = find_pos(b->first, target->ind);
	if (ra == a -> len)
		ra = 0;
	if (min == ft_max(ra, rb))
		case_rot(a, b, ra, rb);
	else if (min == (a->len - ra + rb))
		case_rra_rb(a, b, a->len - ra, rb);
	else if (min == ra + b -> len - rb)
		case_ra_rrb(a, b, ra, rb);
	else if (min == ft_max(a->len - ra, b->len - rb))
		case_revrot(a, b, a->len - ra, b -> len - rb);
	ft_push(b, a, "pa\n");
}

void	huge_sort(t_stack *a, t_stack *b, t_node *target)
{
	long	min;
	long	ra;
	long	rb;

	min = fill_ops(a, b, 1);
	while (target && target -> ops > min)
		target = target -> next;
	ra = find_pos(a->first, target->ind);
	if (target -> ind < find_min_or_max(b->first, -1) || \
			target -> ind > find_min_or_max(b->first, 1))
		rb = find_pos(b->first, find_min_or_max(b->first, 1));
	else
		rb = find_dest(b->first, target->ind, 1) + 1;
	if (rb == b -> len)
		rb = 0;
	if (min == ft_max(ra, rb))
		case_rot(a, b, ra, rb);
	else if (min == ft_max(a->len - ra, b->len - rb))
		case_revrot(a, b, a->len - ra, b->len - rb);
	else if (min == (a->len - ra + rb))
		case_rra_rb(a, b, a->len - ra, rb);
	else if (min == ra + b->len - rb)
		case_ra_rrb(a, b, ra, b->len - rb);
	ft_push(a, b, "pb\n");
}

void	tiny_sort(t_stack *x)
{
	long	a;
	long	b;
	long	c;

	if (x -> len == 1)
		return ;
	else if (check_sort(x->first))
		return ;
	else if (x->len == 2 && !check_sort(x->first))
		return (ft_swap(x));
	a = x->first->ind;
	b = x->first->next->ind;
	c = x->first->next->next->ind;
	if ((a < b && a < c) || (c > a && c > b) || (a > b && b > c))
		ft_swap(x);
	a = x->first->ind;
	b = x->first->next->ind;
	c = x->first->next->next->ind;
	if (b < a)
		ft_ra_rb(x, 1);
	else if (c < b)
		ft_revra_revrb(x, 1);
}

void	push_swap(t_stack *a, t_stack *b)
{
	b -> first = NULL;
	b -> last = NULL;
	b -> len = 0;
	if (a -> len < 4)
		return (tiny_sort(a));
	if (!check_sort(a->first))
		ft_push(a, b, "pb\n");
	if (!check_sort(a->first) && a->len > 3)
		ft_push(a, b, "pb\n");
	while (!check_sort(a->first) && a->len > 3)
		huge_sort(a, b, a -> first);
	if (!check_sort(a->first) && a->len == 3)
		tiny_sort(a);
	while (b -> len > 0)
		back_sort(a, b, b -> first);
	if (!check_sort(a->first))
		return (simple_sort(a));
}
