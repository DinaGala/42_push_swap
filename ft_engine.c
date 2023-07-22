/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:01:26 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/07/22 20:26:40 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_rot(t_stack *a, t_stack *b, long ra, long rb)
{
	while (ra && rb)
	{
		ft_rr_rrr(a, b, 2);
		ra--;
		rb--;
	}
	while (ra > 0 || rb > 0)
	{
		if (ra-- > 0)
			ft_ra_rb(a, 1);
		else if (rb-- > 0)
			ft_ra_rb(b, 2);
	}
}

void	case_revrot(t_stack *a, t_stack *b, long rra, long rrb)
{
	while (rra && rrb)
	{
		ft_rr_rrr(a, b, 3);
		rra--;
		rrb--;
	}
	while (rra > 0 || rrb > 0)
	{
		if (rra-- > 0)
			ft_revra_revrb(a, 1);
		else if (rrb-- > 0)
			ft_revra_revrb(b, 2);
	}
}

void	case_rra_rb(t_stack *a, t_stack *b, long rra, long rb)
{
	while (rra--)
		ft_revra_revrb(a, 1);
	while (rb--)
		ft_ra_rb(b, 2);
}

void	case_ra_rrb(t_stack *a, t_stack *b, long ra, long rrb)
{
	while (rrb--)
		ft_revra_revrb(b, 2);
	while (ra--)
		ft_ra_rb(a, 1);
}
