/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzougari <mzougari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:21:07 by mzougari          #+#    #+#             */
/*   Updated: 2025/10/25 13:46:54 by mzougari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*solve_words(const char *str, char c, int *index)
{
	int		i;
	int		len_word;
	char	*word;

	i = *index;
	len_word = 0;
	while (str[i] && str[i] == c)
		i++;
	*index = i;
	while (str[i] && str[i] != c)
	{
		len_word++;
		i++;
	}
	word = malloc((len_word + 1) * sizeof(char));
	if (!word)
		return (NULL);
	word[len_word] = '\0';
	i = 0;
	while (str[*index] && str[*index] != c)
		word[i++] = str[(*index)++];
	return (word);
}

static void	free_all(char **arr, int n)
{
	while (n-- > 0)
		free(arr[n]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	int		i;
	int		index;
	char	**buff;

	words = count_word(s, c);
	i = 0;
	index = 0;
	buff = malloc((words + 1) * sizeof(char *));
	if (!buff)
		return (NULL);
	while (i < words)
	{
		buff[i] = solve_words(s, c, &index);
		if (!buff[i])
		{
			free_all(buff, i);
			return (NULL);
		}
		i++;
	}
	buff[i] = NULL;
	return (buff);
}
