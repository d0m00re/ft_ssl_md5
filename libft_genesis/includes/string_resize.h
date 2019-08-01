/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_resize.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:00:31 by alhelson          #+#    #+#             */
/*   Updated: 2019/08/01 17:37:28 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** purpose : strin resize in each size, can improve buffer size
*/

#ifndef STRING_RESIZE_H
# define STRING_RESIZE_H

# include "ft_string.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "ft_stdlib.h"

typedef struct	s_resize_mem
{
	char		*mem;
	size_t		size;
	size_t		max_size;
}				t_resize_mem;

/*
** alloc max_size and init structure
** max_size : taille max que la string peut contenir avec redimenssion
*/

int				resize_mem_init(t_resize_mem *r_str, size_t max_size);

/*
** redimenssionner la string
** 1 : overflow probelm
** 2 : realloction problem
** 3 :
*/

int				resize_mem_resize(t_resize_mem *r_str, size_t max_size);

/*
** 1 : overflow problem
*/

int				resize_mem_add_data(t_resize_mem *r_str,\
		void *mem_add, size_t size);

int				resize_mem_destroy(t_resize_mem *r_str);

/*
** -------------------------------------------------------------------------
** utilities function
*/

int				resize_mem_get_stdin(t_resize_mem *r_str);

int				get_fd0(char **mem, size_t *size);

#endif
