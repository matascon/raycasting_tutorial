/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:36:48 by matascon          #+#    #+#             */
/*   Updated: 2020/06/29 10:42:16 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_digit(int n)
{
	if (n > -10 && n < 10)
		return (1);
	else
		return (1 + number_digit(n / 10));
}

static char	*build_str(char *ptr, int n, int n_digit)
{
	int	i;
	int	sign;

	i = n_digit - 1;
	sign = 1;
	if (n < 0)
	{
		ptr[0] = '-';
		sign = sign * -1;
	}
	while (n >= 10 || n <= -10)
	{
		ptr[i--] = ((n % 10) * sign) + 48;
		n /= 10;
	}
	ptr[i] = ((n % 10) * sign) + 48;
	ptr[n_digit] = '\0';
	return (ptr);
}

char		*ft_itoa(int n)
{
	char	*ptr;
	int		n_digit;

	n_digit = number_digit(n);
	if (n < 0)
		n_digit++;
	ptr = (char *)malloc(n_digit + 1);
	if (!ptr)
		return (NULL);
	ptr = build_str(ptr, n, n_digit);
	return (ptr);
}
