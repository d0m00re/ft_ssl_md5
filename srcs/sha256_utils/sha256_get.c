/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:59:35 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/29 15:23:27 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"
#include "ft_string.h"

char				*sha256_get(char *str, size_t size_str)
{
	t_word_sha256	word;
	char			*hash;
	size_t			size;
	int				error;

	error = 0;
	size = 8 * 8 + 1;
	word = word_init_sha256(str, size_str, &error);
	if (error)
		return (0);
	if (error || !(hash = malloc(sizeof(char) * size)))
	{
		free(word.msg);
		return (0);
	}
	ft_bzero(hash, size);
	sha256_run(&word);
	store_hex128_to_32_char(hash, word.word, 8);
	sha256_destroy(&word);
	return (hash);
}
