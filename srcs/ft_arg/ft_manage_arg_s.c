#include "ft_arg.h"
#include "ft_string.h"
#include <stdlib.h>

void	ft_manage_arg_s(t_arg arg, char *(hash)(char *str, size_t size))
{
	char *tstr;

	if (arg.s)
	{
		tstr = hash(arg.string, ft_strlen(arg.string));
		display_hash_string_and_file(tstr, arg, '\"', arg.string);
		free(tstr);
	}
}
