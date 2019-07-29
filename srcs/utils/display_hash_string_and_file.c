/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hash_string_and_file.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 12:31:16 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/29 12:32:25 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display.h"
#include "ft_utils.h"
#include "ft_arg.h"

void	display_hash_string_and_file(char *hash, t_arg arg,\
		char sep, char *name)
{
	if (!(arg.r))
	{
		if (arg.q == 0)
		{
			display_hash_name(arg.type_hash - 1);
			ft_putchar(sep);
			ft_putstr(name);
			ft_putchar(sep);
			ft_putstr(") = ");
		}
		ft_putstr(hash);
		ft_putchar('\n');
	}
	else
	{
		ft_putstr(hash);
		if (arg.q == 0)
		{
			ft_putstr("\t");
			ft_putchar(sep);
			ft_putstr(name);
			ft_putchar(sep);
		}
		ft_putstr("\n");
	}
}
