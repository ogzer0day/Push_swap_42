/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzougari <mzougari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:21:58 by mzougari          #+#    #+#             */
/*   Updated: 2025/10/26 08:41:25 by mzougari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	is_valid(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	len(char const *s1, int i, int j)
{
	int	len;

	len = 0;
	while (s1[i] && i <= j)
	{
		i++;
		len++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*buff;
	char	*first;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && is_valid(set, s1[start]))
		start++;
	while (end >= 0 && is_valid(set, s1[end]))
		end--;
	buff = malloc((len(s1, start, end) + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	first = buff;
	while (s1[start] && start <= end)
		*buff++ = s1[start++];
	*buff = '\0';
	return (first);
}
