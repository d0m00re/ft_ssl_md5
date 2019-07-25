/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_hex128_to_32_char.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:28:48 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/25 15:29:33 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void			store_hex8_to_2char(char *target, uint8_t num)
{
	int			a;
	int			b;

	a = num / 16;
	b = num % 16;
	if (a > 9)
		target[0] = 'a' + a - 10;
	else
		target[0] = '0' + a;
	if (b > 9)
		target[1] = 'a' + b - 10;
	else
		target[1] = '0' + b;
}

void			store_hex32_to_8char(char *target, uint32_t num)
{
	int			c;
	uint8_t		*tab;

	c = 0;
	tab = (uint8_t *)(&num);
	while (c < 4)
	{
		store_hex8_to_2char(&(target[2 * c]), tab[c]);
		c++;
	}
}

void			store_hex128_to_32_char(char *target, uint32_t *word,\
			size_t nb_word)
{
	size_t		c;

	c = 0;
	while (c < nb_word)
	{
		store_hex32_to_8char(&(target[8 * c]), word[c]);
		c++;
	}
}
