/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:00:12 by alhelson          #+#    #+#             */
/*   Updated: 2019/08/01 17:09:23 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stdlib.h>
# include <stdint.h>

int			ft_atoi(const char *str);

void		*ft_realloc(void *mem, size_t size, size_t new_size);

uint32_t	swap32(uint32_t r);

uint64_t	swap64(uint64_t r);

#endif
