/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:39:18 by matascon          #+#    #+#             */
/*   Updated: 2020/06/29 10:39:19 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_length;
	size_t	src_length;
	size_t	count;

	dest_length = 0;
	while (dest[dest_length] != '\0' && dest_length < size)
		dest_length++;
	count = dest_length;
	src_length = 0;
	while (src[src_length] != '\0')
		src_length++;
	while (count + 1 < size && ((char *)src)[count - dest_length] != '\0')
	{
		dest[count] = ((char *)src)[count - dest_length];
		count++;
	}
	if (dest_length < size)
		dest[count] = '\0';
	return (dest_length + src_length);
}
