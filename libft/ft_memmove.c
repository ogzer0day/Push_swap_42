/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzougari <mzougari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:20:36 by mzougari          #+#    #+#             */
/*   Updated: 2025/10/25 19:50:32 by mzougari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src1;
	unsigned char	*dest1;
	size_t			i;

	src1 = (unsigned char *)src;
	dest1 = (unsigned char *)dst;
	if (dest1 > src1)
	{
		while (len > 0)
		{
			len--;
			dest1[len] = src1[len];
		}
	}
	else
	{
		i = -1;
		while (++i < len)
			dest1[i] = src1[i];
	}
	return (dst);
}
