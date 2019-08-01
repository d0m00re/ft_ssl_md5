/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 12:38:45 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/29 12:39:00 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "ft_arg.h"
# include "ft_display.h"

void	display_hash_string_and_file(char *hash, t_arg arg,\
	char sep, char *name);

void	display_hash_name(int hash_num);

int		ft_usage(int ret);

#endif
