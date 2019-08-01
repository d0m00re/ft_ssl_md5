/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:47:41 by alhelson          #+#    #+#             */
/*   Updated: 2019/08/01 16:48:01 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "ft_string.h"

void	*ft_realloc(void *mem, size_t size, size_t new_size)
{
	void *mem_tmp;

	if (!(mem_tmp = malloc(new_size)))
		return (0);
	ft_bzero(mem_tmp, new_size);
	ft_memcpy(mem_tmp, mem, size);
	free(mem);
	mem = mem_tmp;
	return (mem);
}
