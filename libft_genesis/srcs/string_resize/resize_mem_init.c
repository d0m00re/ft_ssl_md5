/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_mem_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:55:16 by alhelson          #+#    #+#             */
/*   Updated: 2019/08/01 16:55:22 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_resize.h"
#include "ft_string.h"
#include <stdlib.h>

/*
** alloc max_size and init structure
** max_size : taille max que la string peut contenir avec redimenssion
*/

int	resize_mem_init(t_resize_mem *r_str, size_t max_size)
{
	r_str->size = 0;
	r_str->max_size = max_size;
	if (!(r_str->mem = malloc(sizeof(char) * max_size)))
		return (1);
	ft_bzero(r_str->mem, max_size);
	return (0);
}
