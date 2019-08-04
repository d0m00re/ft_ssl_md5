/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:04:59 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/29 12:38:34 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARG_H
# define FT_ARG_H

# include "ft_string.h"

# define NB_HASH 2

typedef char	*(*t_hash)(char *str, size_t size);

typedef struct	s_hash_ref
{
        t_hash		opt;
        const char	*name_hash;
        const char	*label_hash;
}	t_hash_ref;

extern const t_hash_ref g_hash[];

/*
** type_hash : md5 or sha256 or error
** p : stdin to stdout
*/

typedef struct	s_arg
{
	short int	type_hash;
	short int	q;
	short int	p;
	short int	pp;
	char		*string;
	short int	s;
	short int	r;
	short int	file;
	char		*name_file;
	int			pos_first_pathfile;
	short int	error;
}				t_arg;

t_arg			manage_arg(int ac, char **av);

void			arg_tostring(t_arg arg);

void			ft_manage_arg_p(t_arg arg, char *(hash)(char *str,\
				size_t size));

void			ft_manage_arg_s(t_arg arg, char *(hash)(char *str,\
				size_t size));

void			ft_manage_arg_file(t_arg arg,\
		char *(hash)(char *str, size_t size), char **av, int ac);

#endif
