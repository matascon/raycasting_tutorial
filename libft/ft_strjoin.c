/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:39:16 by matascon          #+#    #+#             */
/*   Updated: 2020/06/29 10:39:16 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	int		length;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	size = 0;
	length = -1;
	while (s2[++length])
		size++;
	length = -1;
	while (s1[++length])
		size++;
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, length + 1);
	ft_strlcat(ptr, s2, size + 1);
	return (ptr);
}
