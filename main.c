#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include "ft_display.h"
#include "ft_string.h"
#include "ft_md5.h"
#include "ft_arg.h"
#include "ft_file.h"

extern const uint32_t g_r[];

/*
ajouter le bit "1" au message
ajouter le bit "0" jusqu'à ce que la taille du message en bits soit égale à 448 (mod 512)
ajouter la taille du message initial(avant le padding) codée en 64-bit little-endian au message
448 / 8 : 56 octet
512 / 8 : 64 octet
*/

char *sha256(char *str)
{
	ft_putstr("sha256:\n");
}

int ft_usage()
{
	ft_putstr("usage:\n\t./hash [md5/sha256] [string]\n");
	return (1);
}

#define MD5_STRING "md5"
#define SHA256_STRING "sha256"



//substring_is_present_with_delimiter(char *pattern, char *elem, char sep)

#include <math.h>

void arg_tostring(t_arg arg)
{
	printf("type hash : %d\n", arg.type_hash);
	printf("q : %d| p : %d | s : %d | r : %d\n", arg.q, arg.p, arg.s, arg.r);
	printf("string --> %s\n", arg.string);
	printf("file : %d | name file :%s\n", arg.file, arg.name_file);
	printf("error : %d\n", arg.error);
}

int power_of_two(int nb)
{
	int c = 0;
	int tot = 1;

	while (c < nb)
	{
		tot *= 2;
		c++;
	}
	return (tot);
}

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

char *sha256_get(char *str)
{
	printf("KOUKOU");
	return (0);
}

int main(int ac, char **av)
{
	char *(*hash[])(char *str) = {md5_get, sha256_get};
	t_arg arg;
	char *buff;
	char *tstr;

	arg = manage_arg(ac, av);
	//arg_tostring(arg);
	if (arg.error || arg.type_hash == 0)
	{
		ft_usage("usage:\n\t./hash [md5/sha256] [string]\n");
		return (arg.error);
	}
	buff = 0;
	if (arg.p)
		buff = get_fd0();
	tstr = 0;
	if (arg.p)
	{
		tstr = hash[arg.type_hash - 1](buff);//md5_get(buff);
		printf("md5 generation fd 0: %s\n", tstr);
		free(tstr);
	}
	if (arg.s)
	{
		tstr = hash[arg.type_hash - 1](arg.string);
		printf("md generation with -s : %s\n", tstr);
		free(tstr);
	}
	if (arg.file)
	{
		tstr = ft_file_return_data_end_caract(arg.name_file, 10);
		if (tstr)
		{
			char *tstr2 = hash[arg.type_hash - 1](tstr);
			printf("get md from file : %s - %s\n", arg.name_file, tstr2);
			free(tstr);
			free(tstr2);
		}
		else
		{
			printf("unable open file %s\n", arg.name_file);
		}
	}
        //        return (ft_usage("usage:\n\t./hash [md5/sha256] [string]\n"));

}
