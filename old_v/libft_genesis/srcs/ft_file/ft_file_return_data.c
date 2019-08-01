/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_return_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:03:06 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/27 15:20:47 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file.h"

char		*ft_file_return_data(char *name)
{
	char	*str;
	char	c;
	int		count;
	int		size;
	int		fd;

	size = ft_file_size(name);
	if (!name || size <= 0)
		return (0);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	fd = open(name, O_RDONLY);
	count = 0;
	while (read(fd, &c, 1) && count < size)
	{
		str[count] = c;
		count++;
	}
	close(fd);
	str[size - 1] = '\0';
	return (str);
}

char		*ft_file_return_data_end_caract(char *name, char end)
{
	char	*str;
	size_t	size;
	int		fd;

	size = ft_file_size(name);
	if (!name || size <= 0)
		return (0);
	str = malloc(sizeof(char) * (size + 2));
	if (!str)
		return (0);
	fd = open(name, O_RDONLY);
	read(fd, str, size);
	close(fd);
	str[size - 1] = end;
	str[size] = 0;
	return (str);
}

char		*ft_file_return_data_end_caract_size(char *name,\
	char end, size_t *size)
{
	char	*str;
	int		fd;

	*size = ft_file_size2(name);
	if (!name || *size <= 0)
		return (0);
	str = malloc(sizeof(char) * (*size + 2));
	if (!str)
		return (0);
	fd = open(name, O_RDONLY);
	read(fd, str, *size);
	close(fd);
	str[*size - 1] = end;
	str[*size] = 0;
	return (str);
}

char		*ft_file_return_data_size(char *name, size_t *size)
{
	char	*str;
	int		fd;

	*size = ft_file_size2(name);
	if (!name || *size <= 0)
		return (0);
	str = malloc(sizeof(char) * (*size + 1));
	if (!str)
		return (0);
	fd = open(name, O_RDONLY);
	read(fd, str, *size);
	close(fd);
	return (str);
}
