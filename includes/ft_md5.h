/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:06:03 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/25 16:06:23 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H

# include <stdint.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

extern const uint32_t	g_r[];
extern const uint32_t	g_k[];

typedef struct			s_word_md5
{
	uint32_t			*msg;
	uint32_t			word[4];
	size_t				len;
	size_t				nb_turn;
}						t_word_md5;

uint32_t				md5_process_f(uint32_t x, uint32_t y, uint32_t z);

uint32_t				md5_process_g(uint32_t x, uint32_t y, uint32_t z);

uint32_t				md5_process_h(uint32_t x, uint32_t y, uint32_t z);

uint32_t				md5_process_i(uint32_t x, uint32_t y, uint32_t z);

void					md5_run(t_word_md5 *word);

void					md5_destroy(t_word_md5 *word);

t_word_md5				word_init_md5(char *str, size_t size, int *error);

char					*md5_get(char *str, size_t size);

#endif
