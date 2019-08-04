/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_return_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:03:06 by alhelson          #+#    #+#             */
/*   Updated: 2019/07/29 16:47:52 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

char			*ft_file_return_data(char *name)
{
	char		*str;
	char		c;
	int			count;
	int			size;
	int			fd;

	size = ft_file_size(name);
	if (!name || size <= 0)
		return (0);
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (0);
	if ((fd = open(name, O_RDONLY)) == -1)
	{
		free(str);
		return (0);
	}
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

char			*ft_file_return_data_end_caract(char *name, char end)
{
	char		*str;
	ssize_t		size;
	//size_t		size_tmp;
	int			fd;

	size = ft_file_size(name);
	if (!name || size <= 0)
		return (0);
	if (!(str = malloc(sizeof(char) * (size + 2))))
		return (0);
	if ((fd = open(name, O_RDONLY)) == -1)
	{
		free(str);
		return (0);
	}
	if ((read(fd, str, size)) != size)
	{
		free(str);
		return (0);
	}
	close(fd);
	str[size - 1] = end;
	str[size] = 0;
	return (str);
}

char			*ft_file_return_data_end_caract_size(char *name,\
	char end, size_t *size)
{
	char		*str;
	int			fd;

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

int				is_file(char *name)
{
	struct stat	path_stat;

	stat(name, &path_stat);
	return (S_ISREG(path_stat.st_mode));
}

char			*ft_file_return_data_size(char *name, size_t *size)
{
	char		*str;
	int			fd;

	if (is_file(name) == 0)
		return (0);
	*size = ft_file_size2(name);
	if (!name || *size <= 0)
		return (0);
	str = malloc(sizeof(char) * (*size + 1));
	if (!str)
		return (0);
	if ((fd = open(name, O_RDONLY)) == -1)
	{
		free(str);
		return (0);
	}
	read(fd, str, *size);
	close(fd);
	return (str);
}
