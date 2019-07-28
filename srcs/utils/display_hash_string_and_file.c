#include "ft_display.h"
#include "ft_utils.h"
#include "ft_arg.h"

void	display_hash_string_and_file(char *hash, t_arg arg, char sep, char *name)
{
	if (!(arg.r))
	{
		if (arg.q == 0)
		{
			display_hash_name(arg.type_hash - 1);
			ft_putchar(sep);
			ft_putstr(name);
			ft_putchar(sep);
			ft_putstr(") = ");
		}
		ft_putstr(hash);
		ft_putchar('\n');
	}
	else
	{
		ft_putstr(hash);
		if (arg.q == 0)
		{
			ft_putstr("\t");
			ft_putchar(sep);
			ft_putstr(name);
			ft_putchar(sep);
		}
		ft_putstr("\n");
	}
}
