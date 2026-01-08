/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzougari <mzougari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:21:17 by mzougari          #+#    #+#             */
/*   Updated: 2025/10/21 09:15:28 by mzougari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*buff;
	char	*first;

	buff = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	first = buff;
	while (*src)
		*buff++ = *src++;
	*buff = '\0';
	return (first);
}
