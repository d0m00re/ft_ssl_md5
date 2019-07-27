/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 12:41:28 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/27 12:43:33 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"
#include "ft_string.h"

static uint32_t		leftrotate(uint32_t x, uint32_t c)
{
	return (((x) << (c)) | ((x) >> (32 - (c))));
}

static void			md5_process_core(uint32_t *f, uint32_t *g,\
		uint32_t *tmp, int count)
{
	if (count < 16)
	{
		*f = md5_process_f(tmp[1], tmp[2], tmp[3]);
		*g = count;
	}
	else if (count < 32)
	{
		*f = md5_process_g(tmp[1], tmp[2], tmp[3]);
		*g = (5 * count + 1) % 16;
	}
	else if (count < 48)
	{
		*f = md5_process_h(tmp[1], tmp[2], tmp[3]);
		*g = (3 * count + 5) % 16;
	}
	else
	{
		*f = md5_process_i(tmp[1], tmp[2], tmp[3]);
		*g = (7 * count) % 16;
	}
}

static void			md5_process(t_word_md5 *word, uint32_t *data)
{
	uint32_t		tmp[5];
	uint32_t		f;
	uint32_t		g;
	uint32_t		temp;

	tmp[4] = 0;
	ft_memcpy(tmp, word->word, sizeof(uint32_t) * 4);
	while (tmp[4] < 64)
	{
		md5_process_core(&f, &g, tmp, tmp[4]);
		temp = tmp[3];
		tmp[3] = tmp[2];
		tmp[2] = tmp[1];
		tmp[1] = leftrotate(tmp[0] + f + g_k[tmp[4]] +\
		data[g], g_r[tmp[4]]) + tmp[1];
		tmp[0] = temp;
		tmp[4] += 1;
	}
	word->word[0] += tmp[0];
	word->word[1] += tmp[1];
	word->word[2] += tmp[2];
	word->word[3] += tmp[3];
}

void				md5_run(t_word_md5 *word)
{
	size_t			count;

	count = 0;
	while (count < word->nb_turn)
	{
		md5_process(word, &(word->msg[count * 16]));
		count++;
	}
}
