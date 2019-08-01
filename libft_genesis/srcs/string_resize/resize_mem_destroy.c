/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_mem_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:02:40 by alhelson          #+#    #+#             */
/*   Updated: 2019/08/01 17:02:43 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_resize.h"
#include <stdlib.h>

int	resize_mem_destroy(t_resize_mem *r_str)
{
	if (r_str && r_str->mem)
		free(r_str->mem);
	else
		return (1);
	return (0);
}
