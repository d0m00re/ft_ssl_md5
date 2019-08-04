/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 12:38:45 by alhelson          #+#    #+#             */
/*   Updated: 2019/08/04 10:49:19 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "ft_arg.h"
# include "ft_display.h"

typedef char	*(*t_hash)(char *str, size_t size);

typedef struct	s_hash_ref
{
	t_hash		opt;
	const char	*name_hash;
}				t_hash_ref;

extern const	t_hash_ref g_hash[];

void			display_hash_string_and_file(char *hash, t_arg arg,\
				char sep, char *name);

void			display_hash_name(int hash_num);

int				ft_usage(int ret);

#endif
