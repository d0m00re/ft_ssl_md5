#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include "ft_display.h"
#include "ft_string.h"
#include "ft_md5.h"
#include "ft_sha256.h"
#include "ft_arg.h"
#include "ft_file.h"
#include "ft_display.h"

/*
** ajouter le bit "1" au message
** ajouter le bit "0" jusqu'à ce que la taille du message en bits soit égale à 448 (mod 512)
** ajouter la taille du message initial(avant le padding) codée en 64-bit little-endian au message
** 448 / 8 : 56 octet
** 512 / 8 : 64 octet
*/

int ft_usage(char *str)
{
	ft_putstr(str);
	return (1);
}

/*
** void arg_tostring(t_arg arg)
** {
**	printf("type hash : %d\n", arg.type_hash);
**	printf("q : %d| p : %d | s : %d | r : %d\n", arg.q, arg.p, arg.s, arg.r);
**	printf("string --> %s\n", arg.string);
**	printf("file : %d | name file :%s\n", arg.file, arg.name_file);
**	printf("error : %d\n", arg.error);
**}
*/

char *get_fd0(void)
{
	char *buffer;
	int count;

	count = 0;
	if (!(buffer = malloc(sizeof(char) * 10000)))
		return (0);
	bzero(buffer, 10000);
	while (read(0, &(buffer[count]), 1) && buffer[count] != 10)
		count++;
	return (buffer);
}

void	display_hash_name(int hash_num)
{
	if (hash_num == 0)
		ft_putstr("MD5 (");
	else
		ft_putstr("SHA256 (");
}

int	main(int ac, char **av)
{
	char *(*hash[])(char *str, size_t size) = {md5_get, sha256_get};
	t_arg arg;
	char *buff;
	char *tstr;

	arg = manage_arg(ac, av);
	if (arg.error || arg.type_hash == 0)
	{
		ft_usage("usage:\n\t./hash [md5/sha256] [string]\n");
		return (arg.error);
	}
	buff = 0;
	tstr = 0;
	if (arg.p)
	{
		buff = get_fd0();
		ft_putstr(buff);
		tstr = hash[arg.type_hash - 1](buff, strlen(buff));//md5_get(buff);
		ft_putstr(tstr);
		ft_putchar('\n');
		free(tstr);
		free(buff);
	}
	if (arg.s)
	{
		tstr = hash[arg.type_hash - 1](arg.string, strlen(arg.string));

		display_hash_name(arg.type_hash - 1);
		ft_putstr("\"");
		ft_putstr(arg.string);
		ft_putstr("\") = ");
		ft_putstr(tstr);
		ft_putchar('\n');
		free(tstr);
	}
	if (arg.file)
	{
		int count = arg.pos_first_pathfile;
		while (count < ac)
		{
			size_t size = 0;
			tstr = ft_file_return_data_size(av[count], &size);
			if (tstr)
			{
				char *tstr2 = hash[arg.type_hash - 1](tstr, size);
				printf("%s\t%s\n", tstr2, av[count]);
				free(tstr);
				free(tstr2);
			}
			count++;
		}
	}
	return (0);
}
