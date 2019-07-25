/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_logical2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:03:46 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/25 16:03:49 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"
#include <stdint.h>

uint32_t		f_bsig0(uint32_t x)
{
	uint32_t	res;

	res = rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22);
	return (res);
}

uint32_t		f_bsig1(uint32_t x)
{
	uint32_t	res;

	res = rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25);
	return (res);
}

uint32_t		f_ssig0(uint32_t x)
{
	uint32_t	res;

	res = rotr(x, 7) ^ rotr(x, 18) ^ ft_shr(x, 3);
	return (res);
}

uint32_t		f_ssig1(uint32_t x)
{
	uint32_t	res;

	res = rotr(x, 17) ^ rotr(x, 19) ^ ft_shr(x, 10);
	return (res);
}
