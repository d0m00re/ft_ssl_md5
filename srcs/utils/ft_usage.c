/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 12:31:22 by alhelson          #+#    #+#             */
/*   Updated: 2019/08/03 18:51:53 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display.h"

int	ft_usage(int ret)
{
	ft_putstr("usage:\n\t./ft_ssl [-s/-q/-p] [md5/sha256] [-s string] [file] ");
	ft_putstr("[md5/sha256] [-s string] [file]\n");
	ft_putstr("option: \n");
	ft_putstr("\t-s : print the sum of the given string\n");
	ft_putstr("\t-q : quiet mode\n\t-r : reverse format output\n");
	ft_putstr("\t-p : echo STDIN to STDOUT\n");
	return (ret);
}
