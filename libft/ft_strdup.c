/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:39:10 by matascon          #+#    #+#             */
/*   Updated: 2020/06/29 10:39:11 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		length;
	int		i;
	char	*ptr;

	length = 0;
	while (s[length])
		length++;
	ptr = (char *)malloc(length + 1);
	if (!ptr)
		return (NULL);
	i = -1;
	while (++i < length)
		ptr[i] = s[i];
	ptr[i] = '\0';
	return (ptr);
}
