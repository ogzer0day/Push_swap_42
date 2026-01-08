/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzougari <mzougari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:31:54 by mzougari          #+#    #+#             */
/*   Updated: 2025/12/11 11:17:55 by mzougari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_b	*swap_a(t_list_b *stack_a)
{
	t_list_b	*curr;
	t_list_b	*nxt;

	if (!stack_a || !stack_a->next)
		return (stack_a);
	curr = stack_a;
	nxt = stack_a->next;
	curr->next = nxt->next;
	nxt->next = curr;
	stack_a = nxt;
	write(1, "sa\n", 3);
	return (stack_a);
}
