/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_resize_destroy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 00:03:45 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/18 00:04:05 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_resize.h"
#include <stdlib.h>

void	string_resize_destroy(t_string_resize *st)
{
	if (!st)
		return ;
	if (st->str)
		free(st->str);
	free(st);
	st = 0;
}
