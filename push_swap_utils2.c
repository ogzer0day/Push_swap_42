/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzougari <mzougari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:19:46 by mzougari          #+#    #+#             */
/*   Updated: 2025/12/11 11:21:39 by mzougari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_b	*teeny_algo(t_list_b *stack_a)
{
	long	b;
	long	c;

	b = stack_a->next->data;
	c = stack_a->next->next->data;
	if (stack_a->data < b && b < c)
		return (stack_a);
	if (stack_a->data > b && stack_a->data < c)
		stack_a = swap_a(stack_a);
	else if (stack_a->data > b && b > c)
	{
		stack_a = swap_a(stack_a);
		stack_a = reverse_rotate_a(stack_a);
	}
	else if (stack_a->data > c && b < c)
		stack_a = rotate_a(stack_a);
	else if (stack_a->data < c && b > c)
	{
		stack_a = swap_a(stack_a);
		stack_a = rotate_a(stack_a);
	}
	else if (stack_a->data < b && b > c && stack_a->data > c)
		stack_a = reverse_rotate_a(stack_a);
	return (stack_a);
}

t_list_b	*find_min(t_list_b *stack_a, t_list_b **stack_b)
{
	long		min;
	t_list_b	*temp;

	min = stack_a->data;
	temp = stack_a;
	temp = temp->next;
	while (temp)
	{
		if (min > temp->data)
			min = temp->data;
		temp = temp->next;
	}
	while (stack_a->data != min)
		stack_a = rotate_a(stack_a);
	*stack_b = push_b(&stack_a, *stack_b);
	return (stack_a);
}

t_list_b	*small_sort(t_list_b *stack_a, t_list_b *stack_b)
{
	if (ft_lstsize_b(stack_a) == 2)
		stack_a = swap_a(stack_a);
	else if (ft_lstsize_b(stack_a) == 3)
		stack_a = teeny_algo(stack_a);
	else if (ft_lstsize_b(stack_a) == 4)
	{
		stack_a = find_min(stack_a, &stack_b);
		stack_a = teeny_algo(stack_a);
		stack_a = push_a(&stack_b, stack_a);
	}
	else if (ft_lstsize_b(stack_a) == 5)
	{
		stack_a = find_min(stack_a, &stack_b);
		stack_a = find_min(stack_a, &stack_b);
		stack_a = teeny_algo(stack_a);
		stack_a = push_a(&stack_b, stack_a);
		stack_a = push_a(&stack_b, stack_a);
	}
	return (stack_a);
}
