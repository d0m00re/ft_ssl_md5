/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:08:25 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/24 16:52:28 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"
#include "ft_string.h"

char			*md5_get(char *str)
{
	t_word_md5	word;
	char		*hash;
	size_t		size;

	size = 8 * 4 + 1;
	if (!(hash = malloc(size)))
		return (0);
	bzero(hash, size);
	word = word_init_md5(str);
	md5_run(&word);
	store_hex128_to_32_char(hash, word.word, 4);
	return (hash);
}
