/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzougari <mzougari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:39:23 by mzougari          #+#    #+#             */
/*   Updated: 2025/12/10 18:04:01 by mzougari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_b	*push_b(t_list_b **stack_a, t_list_b *stack_b)
{
	t_list_b	*node_to_move;

	if (!stack_a || !*stack_a)
		return (stack_b);
	node_to_move = *stack_a;
	*stack_a = (*stack_a)->next;
	node_to_move->next = stack_b;
	stack_b = node_to_move;
	write(1, "pb\n", 3);
	return (stack_b);
}
