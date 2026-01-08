/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzougari <mzougari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:12:12 by mzougari          #+#    #+#             */
/*   Updated: 2025/12/14 14:37:41 by mzougari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_b	*ft_lstnew_b(long value)
{
	t_list_b	*new_node;

	new_node = malloc(sizeof(t_list_b));
	if (!new_node)
		return (NULL);
	new_node->data = value;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_front_b(t_list_b **lst, t_list_b *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back_b(t_list_b **lst, t_list_b *new)
{
	t_list_b	*temp;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

t_list_b	*ft_lstback(t_list_b *stack_a)
{
	t_list_b	*temp;

	temp = stack_a;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

int	ft_lstsize_b(t_list_b *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
