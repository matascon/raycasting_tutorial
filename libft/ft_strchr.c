/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:38:58 by matascon          #+#    #+#             */
/*   Updated: 2020/06/29 10:38:59 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	s_length;

	s_length = 0;
	while (s[s_length])
		s_length++;
	if (s[0] == c)
		return ((char *)s);
	i = -1;
	while (++i <= s_length)
	{
		if (s[i] == c)
			return ((char *)s + i);
	}
	return (NULL);
}
