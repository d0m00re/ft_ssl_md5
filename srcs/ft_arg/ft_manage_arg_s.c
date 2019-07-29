/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_arg_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 12:41:21 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/29 12:41:29 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arg.h"
#include "ft_string.h"
#include "ft_utils.h"
#include <stdlib.h>

void		ft_manage_arg_s(t_arg arg, char *(hash)(char *str, size_t size))
{
	char	*tstr;

	if (arg.s)
	{
		tstr = hash(arg.string, ft_strlen(arg.string));
		display_hash_string_and_file(tstr, arg, '\"', arg.string);
		free(tstr);
	}
}
