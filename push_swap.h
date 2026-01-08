/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzougari <mzougari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:25:26 by mzougari          #+#    #+#             */
/*   Updated: 2025/12/14 14:12:39 by mzougari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct t_list_b
{
	int				index;
	long			data;
	struct t_list_b	*next;
}					t_list_b;

t_list_b			*push_swap(t_list_b *stack_a, t_list_b *stack_b);

void				ft_lstadd_front_b(t_list_b **lst, t_list_b *new);
void				ft_lstadd_back_b(t_list_b **lst, t_list_b *new);
void				ft_passes(t_list_b **stack_a, t_list_b **stack_b, int pass);
void				free_stack_a(t_list_b *a);
void				free_split(char **str);
int					check_str(char *str);
int					check_errors(char *str);
int					ft_lstsize_b(t_list_b *lst);
int					bit_count(long max);
int					get_max_bits(t_list_b *a);
int					check_order(t_list_b *a);
long				find_max(t_list_b *stack_a);
long				ft_atoi_util(char *str);
t_list_b			*ft_lstnew_b(long value);
t_list_b			*ft_lstback(t_list_b *stack_a);
t_list_b			*ft_parsing(char **str);
t_list_b			*push_a(t_list_b **stack_b, t_list_b *stack_a);
t_list_b			*push_b(t_list_b **stack_a, t_list_b *stack_b);
t_list_b			*reverse_rotate_a(t_list_b *stack_a);
t_list_b			*rotate_a(t_list_b *stack_a);
t_list_b			*swap_a(t_list_b *stack_a);
t_list_b			*small_sort(t_list_b *stack_a, t_list_b *stack_b);

#endif