/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 14:21:15 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/27 14:22:48 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"
#include "ft_stdlib.h"
#include "ft_string.h"

/*
** void	display_hex_string(uint8_t *str, size_t len)
** {
**	size_t	count;
**
**	count = 0;
**	printf("Display padding :\n[\n");
**	while (count < len)
**	{
**		printf("%x ", str[count]);
**		count++;
**	}
**	printf("]\n");
** }
*/

void				swap32_n(uint32_t *data, size_t len)
{
	size_t			count;
	uint32_t		tmp;

	count = 0;
	while (count < len)
	{
		data[count] = swap32(data[count]);
		count++;
	}
	tmp = data[count - 1];
	data[count - 1] = swap32(data[count - 2]);
	data[count - 2] = swap32(tmp);
}

/*
** same of smd5 init - merger next version
** size total : %512 == 0
** format data n % 512 == 448 + 64 bits (size0
** convert stri g in little endianess
*/

void				word_padding_sha256(t_word_sha256 *word,\
	char *str, size_t size)
{
	size_t			init_len;
	size_t			size_to_add;
	uint8_t			*b8;
	uint64_t		*b64;

	size_to_add = 0;
	init_len = size + 1;
	while ((init_len + size_to_add) % 64 != 56)
		size_to_add++;
	if (!(word->msg = (uint32_t *)(malloc(sizeof(char) *\
	(init_len + size_to_add) + 64))))
		exit(1);
	word->len = (init_len + size_to_add + 64 / 8);
	ft_bzero((void *)word->msg, word->len);
	ft_memcpy((char *)word->msg, str, size);
	((uint8_t *)word->msg)[init_len - 1] = 128;
	b8 = &(((uint8_t *)word->msg)[word->len - 8]);
	b64 = (uint64_t *)(b8);
	*b64 = (init_len - 1) * 8;
	word->nb_turn = word->len / 64;
	swap32_n(word->msg, word->len / 4);
}

t_word_sha256		word_init_sha256(char *str, size_t size)
{
	t_word_sha256	word;

	bzero(&word, sizeof(word));
	word.word[0] = 0x6a09e667;
	word.word[1] = 0xbb67ae85;
	word.word[2] = 0x3c6ef372;
	word.word[3] = 0xa54ff53a;
	word.word[4] = 0x510e527f;
	word.word[5] = 0x9b05688c;
	word.word[6] = 0x1f83d9ab;
	word.word[7] = 0x5be0cd19;
	word_padding_sha256(&word, str, size);
	return (word);
}
