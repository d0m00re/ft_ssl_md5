/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:05:41 by alhelson          #+#    #+#             */
/*   Updated: 2019/08/01 17:06:10 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_resize.h"

int						get_fd0(char **mem, size_t *size)
{
	t_resize_mem		r_str;

	if (resize_mem_get_stdin(&r_str))
		return (1);
	*mem = r_str.mem;
	*size = r_str.size;
	return (0);
}
