/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 09:02:31 by matascon          #+#    #+#             */
/*   Updated: 2020/07/15 09:02:42 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsdup(char *s, int free_str)
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
	if (free_str)
		free(s);
	return (ptr);
}
