/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:50:32 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/25 15:50:34 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

uint32_t	md5_process_f(uint32_t x, uint32_t y, uint32_t z)
{
	return (x & y) | ((~x) & z);
}

uint32_t	md5_process_g(uint32_t x, uint32_t y, uint32_t z)
{
	return (x & z) | ((y & (~z)));
}

uint32_t	md5_process_h(uint32_t x, uint32_t y, uint32_t z)
{
	return (x ^ y ^ z);
}

uint32_t	md5_process_i(uint32_t x, uint32_t y, uint32_t z)
{
	return (y ^ (x | (~z)));
}
