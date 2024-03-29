/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substring_is_present_with_delimiter.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:30:30 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/27 15:22:27 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/*
**        permet de trouver si il y a un des sous chaine egal a elem
**        les substring ae separate by a delimiter(sep)
**
**  printf("%d\n",  is_with_delimiter("md5|sha256", "md5", '|'));
**                return 1
**  printf("%d\n",  is_with_delimiter("md5|sha256", "sha256", '|'));
**                return 2
**  printf("%d\n",  is_with_delimiter("md5|sha256", "", '|'));
**                return 0
**  printf("%d\n",  is_with_delimiter("md5|sha256", "sdfsdfsfsss", '|'));
**                return 0
*/

int			substring_is_present_with_delimiter(char *pattern,\
			char *elem, char sep)
{
	int		act_pattern;
	char	**split;

	if (!(split = ft_strsplit(pattern, sep)))
		return (0);
	act_pattern = 1;
	while (split && split[act_pattern - 1])
	{
		if (ft_strcmp(split[act_pattern - 1], elem) == 0)
		{
			ft_strfreesplit(split);
			return (act_pattern);
		}
		act_pattern++;
	}
	ft_strfreesplit(split);
	return (0);
}
