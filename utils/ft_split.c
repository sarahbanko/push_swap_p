/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 15:13:49 by adrperei          #+#    #+#             */
/*   Updated: 2026/08/07 15:34:08 by adrperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"
#include <stdlib.h>

static int	word_count(const char *s, char c) // parte do split, c eh o espaco
{
	int	i;
	int	j; // resultado do tanto de palavras
	
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			j++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (j);
}

static char	*word_dup(const char* s, char c) // duplica uma char* using o delimitador C
{
	char	*word;
	int	len;
	int	i;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len +1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static int fill_words(char **result, const char *str, char c, int words)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < words)
	{
		while (str[i] == c)
			i++;
		result[j] = word_dup(str + i, c);
		if (!result[j])
		{
			while (j > 0)
				free(result[--j]);
			free(result);
			return (0);
		}
		while (str[i] && str[i] != c)
			i++;
		j++;
	}
	result[j] = NULL;
	return (1);
}

char **ft_split(const char *s, char c)
{
	char    **r;
	int     words;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	r = (char **)malloc(sizeof(char *) * (words + 1));
	if (!r)
		return (NULL);
	if (!fill_words(r, s, c, words))
		return (NULL);
	return (r);
}

void ft_free_split(char **split)
{
	int i;

	if (!split)
		return;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
