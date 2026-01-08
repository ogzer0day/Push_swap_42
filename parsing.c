/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzougari <mzougari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:39:59 by mzougari          #+#    #+#             */
/*   Updated: 2025/12/14 15:28:15 by mzougari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_list_b *a)
{
	t_list_b	*temp;

	temp = a;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	check_str(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	if (ft_atoi_util(str) < -2147483648 || ft_atoi_util(str) > 2147483647)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

t_list_b	*help_fun(t_list_b *stack_a, char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (!check_str(str[i]))
		{
			free_stack_a(stack_a);
			return (write(2, "Error\n", 6), NULL);
		}
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi_util(str[i]) == ft_atoi_util(str[j]))
			{
				free_stack_a(stack_a);
				return (write(2, "Error\n", 6), NULL);
			}
			j++;
		}
		ft_lstadd_back_b(&stack_a, ft_lstnew_b(ft_atoi(str[i])));
		i++;
	}
	return (stack_a);
}

t_list_b	*ft_parsing(char **str)
{
	t_list_b	*stack_a;

	if (!*str)
		return (write(2, "Error\n", 6), NULL);
	stack_a = NULL;
	stack_a = help_fun(stack_a, str);
	if (!stack_a)
		return (NULL);
	return (stack_a);
}
