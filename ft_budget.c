/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_budget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:32:56 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/07/22 20:22:38 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	count_price(t_stack *from, t_stack *to, long index, int bol)
{
	long	rfr;
	long	rto;

	rfr = find_pos(from->first, index);
	rto = 0;
	if ((index < find_min_or_max(to->first, -1) || \
			index > find_min_or_max(to->first, 1)) && bol == 2)
		rto = find_pos(to->first, find_min_or_max(to->first, -1));
	else if ((index > find_min_or_max(to->first, 1) || \
			index < find_min_or_max(to->first, -1)) && bol == 1)
		rto = find_pos(to->first, find_min_or_max(to->first, 1));
	else if (bol == 1) 
		rto = find_dest(to->first, index, 1) + 1;
	else if (bol == 2)
		rto = find_dest(to->first, index, 2) + 1;
	if (rto == to -> len)
		rto = 0;
	return (best_price(rfr, (from -> len) - rfr, rto, (to -> len) - rto)); 
}

long	find_dest(t_node *cur, long index, int bol)
{
	long	pos;

	pos = 0;
	if (bol == 1)
	{
		while (cur && cur->next && (cur->ind < index || cur->next->ind > index))
		{
			pos++;
			cur = cur -> next;
		}
	}
	else if (bol == 2)
	{
		while (cur && cur->next && (cur->ind > index || cur->next->ind < index))
		{
			pos++;
			cur = cur -> next;
		}
	}
	return (pos);
}

long	find_min_or_max(t_node *cur, int bol)
{
	long	min_max;

	min_max = cur -> ind;
	if (bol == -1)
	{
		while (cur)
		{
			if (cur->ind < min_max)
				min_max = cur -> ind;
			cur = cur -> next;
		}
	}
	else
	{
		while (cur)
		{
			if (cur->ind > min_max)
				min_max = cur -> ind;
			cur = cur -> next;
		}
	}
	return (min_max);
}

long	best_price(long rfr, long revfr, long rto, long revto)
{
	long	ops;

	ops = rfr + revto;
	if (ops > (revfr + rto))
		ops = revfr + rto;
	if (ops > ft_max(rfr, rto))
		ops = ft_max(rfr, rto);
	if (ops > ft_max(revfr, revto))
		ops = ft_max(revfr, revto);
	return (ops);
}

long	ft_max(long from, long to)
{
	if (from > to)
		return (from);
	return (to);
}
