/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:46:00 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/03/17 15:13:27 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_tabfree(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static size_t	ft_strquant(char const *s, char c)
{
	size_t	i;
	size_t	strquant;

	if (!s[0])
		return (0);
	i = 0;
	strquant = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			strquant++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		strquant++;
	return (strquant);
}

static void	ft_get_next_str(char **next_str, size_t *next_str_len, char c)
{
	size_t	i;

	*next_str += *next_str_len;
	*next_str_len = 0;
	i = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*next_str_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*next_str;
	size_t	next_str_len;
	size_t	strquant;
	size_t	i;

	if (!s)
		return (NULL);
	strquant = ft_strquant(s, c);
	tab = (char **)malloc(sizeof(char *) * (strquant + 1));
	if (!tab)
		return (NULL);
	i = -1;
	next_str = (char *)s;
	next_str_len = 0;
	while (++i < strquant)
	{
		ft_get_next_str(&next_str, &next_str_len, c);
		tab[i] = (char *)malloc(sizeof(char) * (next_str_len + 1));
		if (!tab[i])
			return (ft_tabfree(tab));
		ft_strlcpy(tab[i], next_str, next_str_len + 1);
	}
	tab[i] = NULL;
	return (tab);
}
