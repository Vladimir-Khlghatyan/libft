/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:38:24 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/03/13 16:35:45 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *) s;
	i = 0;
	while (str[i])
		i++;
	if (c == '\0')
		return (str + i);
	i = 0;
	while (str[i])
	{
		if (str[i] != (char) c)
			i++;
		else
			return (str + i);
	}
	return (NULL);
}
