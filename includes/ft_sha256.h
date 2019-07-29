/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:05:22 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/29 12:39:18 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA256_H
# define FT_SHA256_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include "ft_string.h"
# include "ft_display.h"

extern const uint32_t	g_sha256_k[];

typedef struct			s_word_sha256
{
	uint32_t			*msg;
	uint32_t			word[8];
	size_t				len;
	size_t				nb_turn;
}						t_word_sha256;

void					sha256_run(t_word_sha256 *word);

void					sha256_destroy(t_word_sha256 *word);

t_word_sha256			word_init_sha256(char *str, size_t size);

char					*sha256_get(char *str, size_t size);

/*
**        CH( x, y, z) = (x AND y) XOR ( (NOT x) AND z)
**        MAJ( x, y, z) = (x AND y) XOR (x AND z) XOR (y AND z)
**        BSIG0(x) = ROTR^2(x) XOR ROTR^13(x) XOR ROTR^22(x)
**        BSIG1(x) = ROTR^6(x) XOR ROTR^11(x) XOR ROTR^25(x)
**        SSIG0(x) = ROTR^7(x) XOR ROTR^18(x) XOR SHR^3(x)
**        SSIG1(x) = ROTR^17(x) XOR ROTR^19(x) XOR SHR^10(x)
*/

uint32_t				rotr(uint32_t x, uint32_t rot);

uint32_t				ft_shr(uint32_t x, uint32_t shr);

/*
** CH( x, y, z) = (x AND y) XOR ( (NOT x) AND z)
*/

uint32_t				f_ch(uint32_t x, uint32_t y, uint32_t z);

/*
** MAJ( x, y, z) = (x AND y) XOR (x AND z) XOR (y AND z)
*/

uint32_t				f_maj(uint32_t x, uint32_t y, uint32_t z);

/*
** BSIG0(x) = ROTR^2(x) XOR ROTR^13(x) XOR ROTR^22(x)
*/

uint32_t				f_bsig0(uint32_t x);

/*
** BSIG1(x) = ROTR^6(x) XOR ROTR^11(x) XOR ROTR^25(x)
*/

uint32_t				f_bsig1(uint32_t x);

/*
** SSIG0(x) = ROTR^7(x) XOR ROTR^18(x) XOR SHR^3(x)
*/

uint32_t				f_ssig0(uint32_t x);

/*
** SSIG1(x) = ROTR^17(x) XOR ROTR^19(x) XOR SHR^10(x)
*/

uint32_t				f_ssig1(uint32_t x);

#endif
