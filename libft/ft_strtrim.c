/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:39:50 by matascon          #+#    #+#             */
/*   Updated: 2020/07/08 11:16:37 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptr;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = 0;
	while (s1[end])
		end++;
	while (check_set(s1[start], set))
		start++;
	while (end > 0 && check_set(s1[end - 1], set))
		end--;
	if (end < start)
		return (ft_strdup(""));
	if (!(ptr = (char *)malloc(end - start + 1)))
		return (NULL);
	i = 0;
	while (start < end)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}
