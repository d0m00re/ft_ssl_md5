/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 15:13:40 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/29 12:45:48 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arg.h"
#include <stdio.h>

static int		arg_update_hash(t_arg *arg, char *str)
{
	arg->type_hash =\
		substring_is_present_with_delimiter("md5|sha256", str, '|');
	if (arg->type_hash == 0)
		arg->error = 1;
	return (arg->error);
}

static int		arg_update_string(t_arg *arg, char **av, int ac, int *count)
{
	arg->s += 1;
	(*count)++;
	if (*count < ac)
		arg->string = av[(*count)];
	else
	{
		arg->error = 4;
		return (1);
	}
	return (0);
}

static void		update_arg_pp(t_arg *arg)
{
	arg->p = 1;
	arg->pp = 1;
}

int				arg_update_core(t_arg *arg, char **av, int ac, int *count)
{
	int			tmp;

	tmp = substring_is_present_with_delimiter("-p|-q|-s|-r", av[*count], '|');
	if (tmp == 1)
		update_arg_pp(arg);
	else if (tmp == 2)
		arg->q = 1;
	else if (tmp == 3)
		return (arg_update_string(arg, av, ac, count));
	else if (tmp == 4)
		arg->r = 1;
	else if (tmp == 0 && arg->file == 0)
	{
		arg->file = 1;
		arg->pos_first_pathfile = *count;
		arg->name_file = av[*count];
		*count = -2;
	}
	else
	{
		arg->error = 3;
		return (1);
	}
	return (0);
}

/*
** when we have no string or file, we take fd 0 by default
*/

t_arg			manage_arg(int ac, char **av)
{
	t_arg		arg;
	int			count;

	ft_bzero(&arg, sizeof(arg));
	if (arg_update_hash(&arg, av[1]))
		return (arg);
	count = 2;
	while (count < ac && count > 0)
	{
		if (arg_update_core(&arg, av, ac, &count))
			return (arg);
		count++;
	}
	if (arg.s == 0 && arg.file == 0)
		arg.p = 1;
	return (arg);
}
