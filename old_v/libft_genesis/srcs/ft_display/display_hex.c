/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:23:01 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/25 15:24:13 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display.h"

void			display_hex_u8(uint8_t v)
{
	int			a;
	int			b;

	a = v / 16;
	b = v % 16;
	if (a > 9)
		ft_putchar('a' + a - 10);
	else
		ft_putchar('0' + a);
	if (b > 9)
		ft_putchar('a' + b - 10);
	else
		ft_putchar('0' + b);
}

void			display_hex_u32(uint32_t v)
{
	int			c;
	uint8_t		*tab;

	c = 0;
	tab = (uint8_t *)(&v);
	while (c < 4)
	{
		display_hex_u8(tab[c]);
		c++;
	}
}
