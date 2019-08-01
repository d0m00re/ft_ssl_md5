/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_resize_make.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 00:10:14 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/18 00:11:29 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_resize.h"
#include <stdlib.h>

t_string_resize		*string_resize_make(unsigned int len_max)
{
	t_string_resize	*s;
	unsigned int	c;

	if (!(s = malloc(sizeof(t_string_resize))))
		return (0);
	if (!(s->str = malloc(sizeof(char) * (len_max + 1))))
		return (0);
	s->len_max = len_max;
	s->len = 0;
	c = 0;
	while (c <= s->len_max)
	{
		s->str[c] = '\0';
		c++;
	}
	return (s);
}

t_string_resize		*string_resize_make_with_str(unsigned int len_max,\
		char *str)
{
	int				c;
	t_string_resize *st;

	c = 0;
	if (!(st = string_resize_make(len_max)))
		return (0);
	while (str[c])
	{
		st->str[c] = str[c];
		c++;
	}
	st->len = ft_strlen(str);
	return (st);
}
