/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:29:41 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/07/22 20:19:17 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_add_back(t_node **head_stack, t_node *new_n)
{
	if (!(*head_stack))
		*head_stack = new_n;
	else
	{
		new_n -> prev = lst_last(*head_stack);
		lst_last(*head_stack)-> next = new_n;
	}
}

void	lst_add_front(t_node **head_stack, t_node *new_n)
{
	if (*head_stack)
		(*head_stack)->prev = new_n;
	new_n -> prev = NULL;
	new_n -> next = *head_stack;
	*head_stack = new_n;
}

t_node	*lst_last(t_node *head)
{
	while (head && head -> next)
		head = head -> next;
	return (head);
}

t_node	*lst_new(t_stack *a, int res)
{
	t_node	*new;

	if (!a)
	{
		a -> len = 0;
		a -> first = NULL;
		a -> last = NULL;
	}
	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new -> data = res;
	new -> next = NULL;
	new -> prev = NULL;
	lst_add_back(&(a->first), new);
	a -> last = new;
	a -> len += 1;
	return (a -> first);
}
