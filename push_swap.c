/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzougari <mzougari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:12:27 by mzougari          #+#    #+#             */
/*   Updated: 2025/12/14 15:32:06 by mzougari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_b	*ft_lstcopy(t_list_b *stack_a)
{
	t_list_b	*lstcopy;
	long		new_content;

	lstcopy = NULL;
	while (stack_a)
	{
		new_content = stack_a->data;
		ft_lstadd_back_b(&lstcopy, ft_lstnew_b(new_content));
		stack_a = stack_a->next;
	}
	return (lstcopy);
}

t_list_b	*babble_sort(t_list_b *lstcopy)
{
	t_list_b	*last;
	t_list_b	*temp_lst;
	int			sorted;
	long		temp;

	last = NULL;
	sorted = 1;
	while (sorted)
	{
		temp_lst = lstcopy;
		sorted = 0;
		while (temp_lst->next != last)
		{
			if (temp_lst->data > temp_lst->next->data)
			{
				temp = temp_lst->data;
				temp_lst->data = temp_lst->next->data;
				temp_lst->next->data = temp;
				sorted = 1;
			}
			temp_lst = temp_lst->next;
		}
		last = temp_lst;
	}
	return (lstcopy);
}

void	get_index(t_list_b *stack_a, t_list_b *sorted)
{
	int			index;
	t_list_b	*tmp;

	index = 0;
	while (sorted)
	{
		tmp = stack_a;
		while (tmp)
		{
			if (tmp->data == sorted->data)
				tmp->index = index;
			tmp = tmp->next;
		}
		sorted = sorted->next;
		index++;
	}
}

t_list_b	*push_swap(t_list_b *stack_a, t_list_b *stack_b)
{
	t_list_b	*copy;
	int			bits;
	int			i;

	if (!check_order(stack_a))
		return (stack_a);
	if (ft_lstsize_b(stack_a) <= 5)
		return (small_sort(stack_a, stack_b));
	copy = ft_lstcopy(stack_a);
	copy = babble_sort(copy);
	get_index(stack_a, copy);
	free_stack_a(copy);
	bits = get_max_bits(stack_a);
	i = 0;
	while (i < bits)
	{
		ft_passes(&stack_a, &stack_b, i);
		i++;
	}
	return (stack_a);
}

int	main(int ac, char *av[])
{
	int			i;
	t_list_b	*stack_a;
	t_list_b	*stack_b;
	char		**str;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (1);
	i = 1;
	if (ac == 2)
	{
		str = ft_split(av[i], ' ');
		stack_a = ft_parsing(str);
		free_split(str);
	}
	else
		stack_a = ft_parsing(av + 1);
	if (!stack_a)
		return (1);
	stack_a = push_swap(stack_a, stack_b);
	free_stack_a(stack_a);
}
