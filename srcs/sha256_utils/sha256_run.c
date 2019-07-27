/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 14:38:04 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/27 14:39:08 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"
#include "ft_stdlib.h"
#include <stdio.h>
#include "ft_string.h"

void			initialise_w(uint32_t *data, uint32_t *w)
{
	size_t		count;

	count = 0;
	ft_bzero(w, sizeof(uint32_t) * 64);
	while (count < 16)
	{
		w[count] = data[count];
		count++;
	}
	while (count < 64)
	{
		w[count] = f_ssig1(w[count - 2]) + w[count - 7] +\
		f_ssig0(w[count - 15]) + w[count - 16];
		count++;
	}
}

void			compute_logic_function(uint32_t *tmp, uint32_t *w)
{
	size_t		count;
	uint32_t	t1;
	uint32_t	t2;

	count = 0;
	while (count < 64)
	{
		t1 = tmp[7] + f_bsig1(tmp[4]) + f_ch(tmp[4],\
		tmp[5], tmp[6]) + g_sha256_k[count] + w[count];
		t2 = f_bsig0(tmp[0]) + f_maj(tmp[0], tmp[1], tmp[2]);
		tmp[7] = tmp[6];
		tmp[6] = tmp[5];
		tmp[5] = tmp[4];
		tmp[4] = tmp[3] + t1;
		tmp[3] = tmp[2];
		tmp[2] = tmp[1];
		tmp[1] = tmp[0];
		tmp[0] = t1 + t2;
		count++;
	}
}

void			sha256_process(t_word_sha256 *word, uint32_t *data)
{
	int			count;
	uint32_t	w[64];
	uint32_t	tmp[8];

	initialise_w(data, w);
	count = 0;
	while (count < 8)
	{
		tmp[count] = word->word[count];
		count++;
	}
	count = 0;
	compute_logic_function(tmp, w);
	while (count < 8)
	{
		word->word[count] += tmp[count];
		count++;
	}
}

void			sha256_run(t_word_sha256 *word)
{
	size_t		count;

	count = 0;
	while (count < word->nb_turn)
	{
		sha256_process(word, &(word->msg[count * 16]));
		count++;
	}
	count = 0;
	while (count < 8)
	{
		word->word[count] = swap32(word->word[count]);
		count++;
	}
}
