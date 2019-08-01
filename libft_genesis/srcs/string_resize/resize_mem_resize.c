/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_mem_resize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:56:45 by alhelson          #+#    #+#             */
/*   Updated: 2019/08/01 16:56:58 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_resize.h"
#include "ft_stdlib.h"

/*
** redimenssionner la string
** 1 : overflow probelm
** 2 : realloction problem
** 3 :
*/

int			resize_mem_resize(t_resize_mem *r_str, size_t max_size)
{
	if (max_size < r_str->max_size)
		return (1);
	if (!(r_str->mem = ft_realloc(r_str->mem, r_str->size, max_size)))
		return (2);
	r_str->max_size = max_size;
	return (0);
}
