/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzougari <mzougari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:32:04 by mzougari          #+#    #+#             */
/*   Updated: 2025/12/11 11:22:37 by mzougari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_b	*reverse_rotate_a(t_list_b *stack_a)
{
	t_list_b	*temp;
	t_list_b	*prev;
	t_list_b	*new_node;

	if (!stack_a || !stack_a->next)
		return (stack_a);
	temp = stack_a;
	prev = NULL;
	new_node = malloc(sizeof(t_list_b));
	if (!new_node)
		return (stack_a);
	while (temp->next)
	{
		prev = temp;
		temp = temp->next;
	}
	new_node->data = temp->data;
	new_node->next = NULL;
	ft_lstadd_front_b(&stack_a, new_node);
	prev->next = NULL;
	free(temp);
	write(1, "rra\n", 4);
	return (stack_a);
}
