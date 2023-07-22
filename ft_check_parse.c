/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:36:30 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/07/22 21:01:29 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str, int *res)
{
	int		i;
	int		min;
	long	x;

	i = 0;
	x = 0;
	min = 1;
	if (!(*str))
		return (-1);
	if ((str[i] == 45) && str[i + 1] && str[i + 1] != '0')
	{
		min = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58 && str[i])
	{
		x = x * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] || (min * x) > INT_MAX || (min * x) < INT_MIN)
		return (-1);
	*res = (int)(min * x);
	return (1);
}

int	check_dup(t_node **head_a, t_node *cur)
{
	t_node	*temp;
	long	index;

	if (!cur)
		return (1);
	temp = *head_a;
	index = 0;
	while (temp)
	{
		if (cur != temp && cur->data == temp->data)
			return (-1);
		if (cur->data > temp->data)
			index++;
		temp = temp -> next;
	}
	cur -> ind = index;
	return (check_dup(head_a, cur->next));
}

int	arg_check(char **argv, int argc, t_stack *a)
{
	int		res;
	int		i;
	t_node	*head_a;

	i = 1;
	head_a = NULL;
	while (i < argc)
	{
		if (ft_atoi(argv[i++], &res) == -1)
			return (-1);
		head_a = lst_new(a, res);
		if (!head_a)
			return (0);
	}
	if (check_dup(&head_a, head_a) == -1)
		return (-1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		check;

	if (argc < 2)
		return (1);
	check = arg_check(argv, argc, &a);
	if (check == -1)
		return (clean_up(&(a.first), &a, 1));
	if (check == 0)
		return (clean_up(&(a.first), &a, 0));
	push_swap(&a, &b);
	clean_up(&(a.first), &a, 2);
	return (0);
}
