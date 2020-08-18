/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:39:45 by matascon          #+#    #+#             */
/*   Updated: 2020/06/29 10:39:46 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	s_length;

	s_length = 0;
	while (s[s_length])
		s_length++;
	while (s_length >= 0)
	{
		if (s[s_length] == (char)c)
			return ((char *)s + s_length);
		s_length--;
	}
	return (NULL);
}
