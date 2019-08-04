/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_arg_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 12:41:36 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/29 15:23:01 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display.h"
#include "ft_string.h"
#include "ft_md5.h"
#include "ft_sha256.h"
#include "ft_arg.h"
#include "ft_file.h"
#include "ft_display.h"
#include "ft_utils.h"
#include <string.h>
#include <stdlib.h>

static void		display_error_file(char *name_file, int d_show, int type_hash)
{
	if (d_show)
		return ;
	ft_putstr("ft_ssl: ");
	if (type_hash)
	{
		ft_putstr(g_hash[type_hash - 1].name_hash);
		ft_putstr(":");
	}
	else
		ft_putstr("Unknown hash: ");
	ft_putstr(name_file);
	ft_putstr(": No such file or directory\n");
}

void			ft_manage_arg_file(t_arg arg,\
		char *(hash)(char *str, size_t size), char **av, int ac)
{
	int			count;
	size_t		size;
	char		*tstr2;
	char		*tstr;

	tstr2 = 0;
	if (arg.file)
	{
		count = arg.pos_first_pathfile;
		while (count < ac)
		{
			size = 0;
			if (!(tstr = ft_file_return_data_size(av[count], &size)))
			{
				display_error_file(av[count], arg.q, arg.type_hash);
				count++;
				continue;
			}
			tstr2 = hash(tstr, size);
			display_hash_string_and_file(tstr2, arg, 0, av[count]);
			free(tstr);
			free(tstr2);
			count++;
		}
	}
}
