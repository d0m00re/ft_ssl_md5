/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 12:31:28 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/29 12:37:32 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include "ft_display.h"
#include "ft_string.h"
#include "ft_md5.h"
#include "ft_sha256.h"
#include "ft_arg.h"
#include "ft_file.h"
#include "ft_display.h"
#include "ft_utils.h"

/*
** ajouter le bit "1" au message
** ajouter le bit "0" jusqu'à ce que la taille du
** message en bits soit égale à 448 (mod 512)
** ajouter la taille du message initial(avant le padding)
** codée en 64-bit little-endian au message
** 448 / 8 : 56 octet
** 512 / 8 : 64 octet
*/

int			main(int ac, char **av)
{
	t_arg	arg;

	if (ac < 2)
		return (ft_usage(1));
	arg = manage_arg(ac, av);
	if (arg.error || arg.type_hash == 0)
		return (ft_usage(arg.error));
	ft_manage_arg_p(arg, g_hash[arg.type_hash - 1].opt);
	ft_manage_arg_s(arg, g_hash[arg.type_hash - 1].opt);
	ft_manage_arg_file(arg, g_hash[arg.type_hash - 1].opt, av, ac);
	return (0);
}
