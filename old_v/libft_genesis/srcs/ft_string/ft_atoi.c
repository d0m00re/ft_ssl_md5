/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:10:06 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/17 23:10:13 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int			ft_atoi(const char *str)
{
	int		nb;
	int		neg;
	char	*str2;

	nb = 0;
	neg = 0;
	str2 = (char *)str;
	while (*str2 && ft_isseparator(*str2))
		str2++;
	if (*str2 && *str2 == '+')
	{
		neg += 1;
		str2++;
	}
	else if (*str2 && *str2 == '-')
	{
		neg -= 1;
		str2++;
	}
	while (*str2 && *str2 <= '9' && *str2 >= '0')
	{
		nb = (nb) ? nb * 10 + (*str2 - '0') : *str2 - '0';
		str2++;
	}
	return (neg) ? nb * neg : nb;
}
