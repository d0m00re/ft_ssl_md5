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
#include "ft_utils.h"

/*
** ajouter le bit "1" au message
** ajouter le bit "0" jusqu'à ce que la taille du message en bits soit égale à 448 (mod 512)
** ajouter la taille du message initial(avant le padding) codée en 64-bit little-endian au message
** 448 / 8 : 56 octet
** 512 / 8 : 64 octet
*/

int	main(int ac, char **av)
{
	char *(*hash[])(char *str, size_t size) = {md5_get, sha256_get};
	t_arg arg;

	if (ac < 2)
		return (ft_usage("usage:\n\t./hash [md5/sha256] [string]\n", 1));
	arg = manage_arg(ac, av);
	if (arg.error || arg.type_hash == 0)
		return (ft_usage("usage:\n\t./hash [md5/sha256] [string]\n", arg.error));
	ft_manage_arg_p(arg, hash[arg.type_hash - 1]);
	ft_manage_arg_s(arg, hash[arg.type_hash - 1]);
	ft_manage_arg_file(arg, hash[arg.type_hash - 1], av, ac);
	return (0);
}
