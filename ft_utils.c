/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:12:09 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/07/22 20:20:09 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putstr_fd(char *s, int fd)
{
	int		len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (write(fd, s, len));
}

int	clean_up(t_node **head, t_stack *a, int print)
{
	t_node	*temp;
	t_node	*cur;

	if (!a)
		return (1);
	cur = *head;
	while (cur)
	{
		temp = cur;
		cur = cur -> next;
		free(temp);
	}
	head = NULL;
	a -> first = NULL;
	a -> last = NULL;
	if (print == 1)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	else if (!print)
		ft_putstr_fd("Malloc allocation failed! Try again\n", STDERR_FILENO);
	return (1);
}

int	check_sort(t_node *node)
{
	while (node -> next) 
	{
		if (node->ind > node->next->ind)
			return (0);
		node = node -> next;
	}
	return (2);
}

long	fill_ops(t_stack *from, t_stack *to, int bol)
{
	long	min;
	t_node	*cur;

	cur = from -> first;
	while (cur)
	{
		cur -> ops = count_price(from, to, cur->ind, bol);
		if (!(cur -> prev) || cur -> ops < min)
			min = cur -> ops;
		cur = cur -> next;
	}
	return (min);
}

long	find_pos(t_node *cur, long index)
{
	long	pos;

	pos = 0;
	while (cur->ind != index)
	{
		cur = cur -> next;
		pos++;
	}
	return (pos);
}
