/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 02:02:46 by sueno-te          #+#    #+#             */
/*   Updated: 2024/03/02 02:02:47 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c);
static char		*next_word(const char **s, char c);

char	**ft_split(const char *s, char c)
{
	char	**arr;
	size_t	word_count;
	size_t	i;

	word_count = count_words(s, c);
	arr = ft_calloc((word_count + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		arr[i] = next_word(&s, c);
		if (!arr[i])
		{
			ft_memclear((void **)arr, free);
			return (NULL);
		}
		i++;
	}
	return (arr);
}

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	char	new_word;
	size_t	i;

	count = 0;
	new_word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && new_word == 0)
		{
			count++;
			new_word = 1;
		}
		else if (s[i] == c)
			new_word = 0;
		i++;
	}
	return (count);
}

static char	*next_word(const char **s, char c)
{
	char	*word;

	while (**s == c)
		(*s)++;
	word = ft_substr(*s, 0, ft_strchr(*s, c) - *s);
	while (**s != '\0' && **s != c)
		(*s)++;
	return (word);
}
