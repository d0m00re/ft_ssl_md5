/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_arg_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 12:39:56 by alhelson          #+#    #+#             */
/*   Updated: 2019/08/03 18:50:48 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display.h"
#include "ft_arg.h"
#include <stdlib.h>
#include "string_resize.h"

void		ft_manage_arg_p(t_arg arg, char *(hash)(char *str, size_t size))
{
	char	*tstr;
	char	*buff;
	size_t	size;

	tstr = 0;
	size = 0;
	buff = 0;
	if (arg.p)
	{
		if ((get_fd0(&buff, &size)))
		{
			ft_putstr("/!\\ error 0x1001 | failed stdin\n");
			return ;
		}
		if (arg.pp)
			ft_putstr(buff);
		tstr = hash(buff, size);
		ft_putstr(tstr);
		ft_putchar('\n');
		free(tstr);
		free(buff);
	}
}
