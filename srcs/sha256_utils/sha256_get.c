/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:59:35 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/25 15:59:54 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"
#include "ft_string.h"

char				*sha256_get(char *str)
{
	t_word_sha256	word;
	char			*hash;
	size_t			size;

	size = 8 * 8 + 1;
	if (!(hash = malloc(sizeof(char) * size)))
		return (0);
	bzero(hash, size);
	word = word_init_sha256(str);
	sha256_run(&word);
	store_hex128_to_32_char(hash, word.word, 8);
	return (hash);
}
