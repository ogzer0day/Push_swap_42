/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzougari <mzougari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:12:49 by mzougari          #+#    #+#             */
/*   Updated: 2025/12/10 18:03:58 by mzougari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bit_count(long max)
{
	int	bits;

	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

long	find_max(t_list_b *stack_a)
{
	long	max;

	max = stack_a->data;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (stack_a->data > max)
			max = stack_a->data;
		stack_a = stack_a->next;
	}
	return (bit_count(max));
}

int	get_max_bits(t_list_b *a)
{
	long	max;

	max = a->index;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	return (bit_count(max));
}

void	ft_passes(t_list_b **stack_a, t_list_b **stack_b, int pass)
{
	int	size_node;
	int	i;

	size_node = ft_lstsize_b(*stack_a);
	i = 0;
	while (i < size_node)
	{
		if ((((*stack_a)->index >> pass) & 1) == 0)
			*stack_b = push_b(stack_a, *stack_b);
		else
			*stack_a = rotate_a(*stack_a);
		i++;
	}
	while (*stack_b)
		*stack_a = push_a(stack_b, *stack_a);
}

long	ft_atoi_util(char *str)
{
	int		i;
	long	result;
	int		signe;

	i = 0;
	result = 0;
	signe = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * signe);
}
