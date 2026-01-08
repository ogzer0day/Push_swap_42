/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzougari <mzougari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:12:41 by mzougari          #+#    #+#             */
/*   Updated: 2025/12/10 18:06:45 by mzougari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_b	*rotate_a(t_list_b *stack_a)
{
	t_list_b	*first;
	t_list_b	*last;

	if (!stack_a || !stack_a->next)
		return (stack_a);
	first = stack_a;
	last = stack_a;
	while (last->next)
		last = last->next;
	stack_a = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
	return (stack_a);
}
