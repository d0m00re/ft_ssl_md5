/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:21:45 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/27 13:21:59 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*dest2;
	const char		*src2;

	dest2 = (char *)dst;
	src2 = (char *)src;
	while (n > 0)
	{
		*dest2 = *src2;
		dest2++;
		src2++;
		n--;
	}
	return (dst);
}
