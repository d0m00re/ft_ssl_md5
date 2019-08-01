/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:03:23 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/25 15:36:17 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H
# include <string.h>
# include <stdint.h>

void		*ft_memcpy(void *dst, const void *src, size_t n);

void		ft_bzero(void *s, size_t n);

size_t		ft_strlen(const char *s);

int			ft_strcmp(const char *s1, const char *s2);

int			ft_strncmp(const char *s1, const char *s2, size_t n);

char		*ft_strdup(const char *s1);

void		replace(char *str, char target, char replace);

char		*ft_strcpy(char *dst, const char *src);

char		*ft_strcat(char *s1, const char *s2);

char		**ft_strsplit(char const *s, char c);

void		ft_strfreesplit(char **data);

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_isseparator(int c);

void		ft_bzero(void *v, size_t n);

/*
** permet de trouver si il y a un des sous chaine egal a elem
** les substring ae separate by a delimiter(sep)
** printf("%d\n",  ("md5|sha256", "md5", '|'));
**   return 1
** printf("%d\n",  ("md5|sha256", "sha256", '|'));
**  return 2
** printf("%d\n",  ("md5|sha256", "", '|'));
**  return 0
** printf("%d\n",  ("md5|sha256", "sdfsdfsfsss", '|'));
**  return 0
*/

int			substring_is_present_with_delimiter(char *pattern,\
		char *elem, char sep);

/*
** parse uint in string
*/

void		store_hex8_to_2char(char *target, uint8_t num);

void		store_hex32_to_8char(char *target, uint32_t num);

void		store_hex128_to_32_char(char *target,\
		uint32_t *word, size_t nb_word);

void		store_hex128_to_32_char_rev(char *target, uint32_t *word,\
		size_t nb_word);

#endif
