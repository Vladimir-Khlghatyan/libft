/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <vkhlghat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:46:00 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/04/11 18:57:00 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**arrfree(char **arr)
{
	int	i;

	if (!arr)
		return (NULL);
	i = -1;
	while (arr[++i])
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;
	return (NULL);
}

static int	wordcount(const char *s, char c)
{
	int		count;
	int		i;

	if (!s || !s[0])
		return (0);
	count = 0;
	i = 0;
	while (s[++i])
		if (s[i] == c && s[i - 1] != c)
			++count;
	if (s[i - 1] != c)
		++count;
	return (count);
}

static int	wordlen(const char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		wc;
	int		i[2];

	if (!s)
		return (NULL);
	i[0] = -1;
	wc = wordcount(s, c);
	arr = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	while (++i[0] < wc)
	{
		arr[i[0]] = (char *)malloc(sizeof(char) * (wordlen(s, c) + 1));
		if (!arr[i[0]])
			return (arrfree(arr));
		while (*s == c)
			s++;
		i[1] = 0;
		while (*s != c && *s)
			arr[i[0]][i[1]++] = *s++;
		arr[i[0]][i[1]] = '\0';
	}
	arr[i[0]] = NULL;
	return (arr);
}
