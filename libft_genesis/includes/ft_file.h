/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:57:55 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/27 15:22:57 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H
# define FT_FILE_H

# include <fcntl.h>
# include <unistd.h>
# include "ft_display.h"
# include <stdlib.h>
# include <string.h>

int		ft_file_exist(char *name);

int		ft_file_size(char *name);

size_t		ft_file_size2(char *name);

char	*ft_file_return_data(char *name);

char	*ft_file_return_data_end_caract(char *name, char end);

char	*ft_file_return_data_end_caract_size(char *name,\
		char end, size_t *size);

char	*ft_file_return_data_size(char *name, size_t *size);

#endif
