/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzougari <mzougari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:21:29 by mzougari          #+#    #+#             */
/*   Updated: 2025/10/24 18:58:52 by mzougari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len_dest;
	size_t	i;

	len_src = 0;
	len_dest = 0;
	while (src[len_src])
		len_src++;
	while (len_dest < dstsize && dst[len_dest])
		len_dest++;
	if (len_dest == dstsize)
		return (dstsize + len_src);
	i = 0;
	while (src[i] && (len_dest + i + 1) < dstsize)
	{
		dst[len_dest + i] = src[i];
		i++;
	}
	if (len_dest + i < dstsize)
		dst[len_dest + i] = '\0';
	return (len_dest + len_src);
}
