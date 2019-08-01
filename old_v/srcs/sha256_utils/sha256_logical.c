/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_logical.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:03:30 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/25 16:03:35 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uint32_t	rotr(uint32_t x, uint32_t rot)
{
	return (((x >> rot) | (x << (32 - rot))));
}

uint32_t	ft_shr(uint32_t x, uint32_t shr)
{
	return (x >> shr);
}

uint32_t	f_ch(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) ^ ((~x) & z));
}

uint32_t	f_maj(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) ^ (x & z) ^ (y & z));
}
