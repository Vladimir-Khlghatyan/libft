/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:38:06 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/03/15 23:31:20 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *) s;
	i = ft_strlen(str);
	if (c == '\0' && str[i] == '\0')
		return (str + i);
	while (str[i - 1])
	{
		if (str[i - 1] != (char) c)
			i--;
		else
			break ;
	}
	if (i <= 0)
		return (NULL);
	else
		return (str + i - 1);
}
