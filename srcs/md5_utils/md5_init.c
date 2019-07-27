/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 12:57:52 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/27 13:02:17 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include "ft_display.h"
#include "ft_string.h"

/*
** void display_hex8(uint8_t *data, size_t size)
** {
** 	for (size_t i = 0; i < size; i++)
** 	{
**		printf("%x ", data[i]);
**	}
**	printf("\n");
** }
*/

/*
** word : data structure who contain update element
** data : begin element perform actual hash
** nb_word_md5 size of this part, utils to stop end block without segfault
** (init_len + size_to_add) + 64
** 64 : size of 64 byte end of string
** init_len + size_to_add need to be 448 with mod 512
*/

void			word_padding_md5(t_word_md5 *word, char *str, size_t size)
{
	size_t		init_len;
	size_t		size_to_add;
	uint8_t		*b8;
	uint64_t	*b64;

	size_to_add = 0;
	init_len = size + 1;
	while ((init_len + size_to_add) % 64 != 56)
		size_to_add++;
	if (!(word->msg = (uint32_t *)(malloc(sizeof(char) *\
	(init_len + size_to_add) + 64))))
		exit(1);
	word->len = (init_len + size_to_add + 64 / 8);
	ft_bzero((void *)word->msg, word->len);
	ft_memcpy(word->msg, str, size);
	b8 = &(((uint8_t *)word->msg)[word->len - 8]);
	b64 = (uint64_t *)(b8);
	*b64 = (init_len - 1) * 8;
	((uint8_t *)word->msg)[init_len - 1] = 128;
	word->nb_turn = word->len / 64;
}

/*
** word in low bit order
*/

t_word_md5		word_init_md5(char *str, size_t size)
{
	t_word_md5 word;

	word.word[0] = 0x67452301;
	word.word[1] = 0xefcdab89;
	word.word[2] = 0x98badcfe;
	word.word[3] = 0x10325476;
	word_padding_md5(&word, str, size);
	return (word);
}
