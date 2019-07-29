/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:08:25 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/27 12:44:21 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"
#include "ft_string.h"

char			*md5_get(char *str, size_t size_str)
{
	t_word_md5	word;
	char		*hash;
	size_t		size;
	int		error;

	error = 0;
	size = 8 * 4 + 1;
	word = word_init_md5(str, size_str, &error);
	if (error || !(hash = malloc(sizeof(char) * size)))
		return (0);
	ft_bzero(hash, size);
	md5_run(&word);
	store_hex128_to_32_char(hash, word.word, 4);
	md5_destroy(&word);
	return (hash);
}
