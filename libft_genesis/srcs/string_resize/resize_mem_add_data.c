/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_mem_add_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:57:09 by alhelson          #+#    #+#             */
/*   Updated: 2019/08/01 17:01:17 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"string_resize.h"

/*
** 1 : overflow problem
*/

int			resize_mem_add_data(t_resize_mem *r_str, void *mem_add, size_t size)
{
	size_t	new_size;
	int		ret;

	new_size = r_str->size + size;
	if (new_size < r_str->size)
		return (1);
	if (new_size > r_str->max_size)
	{
		if ((ret = resize_mem_resize(r_str, new_size)))
			return (ret + 1);
	}
	ft_memcpy(&(r_str->mem[r_str->size]), mem_add, size);
	r_str->size = new_size;
	return (0);
}
