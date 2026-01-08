/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzougari <mzougari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:21:53 by mzougari          #+#    #+#             */
/*   Updated: 2025/10/25 18:49:20 by mzougari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return ((char *)(s + i));
	while (i > 0)
	{
		i--;
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((char *)(s + i));
	}
	if (((unsigned char *)s)[0] == (unsigned char)c)
		return ((char *)(s + i));
	return (NULL);
}
