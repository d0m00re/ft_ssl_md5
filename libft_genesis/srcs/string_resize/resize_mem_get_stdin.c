/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_mem_get_stdin.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:04:33 by alhelson          #+#    #+#             */
/*   Updated: 2019/08/01 17:04:52 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_resize.h"

int			resize_mem_get_stdin(t_resize_mem *r_str)
{
	ssize_t	size;
	char	buffer[10];
	int		ret;

	resize_mem_init(r_str, 1000);
	while ((size = read(0, buffer, 10)) > 0)
	{
		if ((ret = resize_mem_add_data(r_str, buffer, size)))
			return (1);
	}
	return (0);
}
