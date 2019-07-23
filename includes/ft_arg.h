#ifndef FT_ARG_H
# define FT_ARG_H

# include "ft_string.h"

typedef struct	s_arg
{
	short int type_hash;
	short int q;
	short int p; // stdin to stdout
	char *string;
	short int s;
	short int r;
	short int file;
	char *name_file;
	short int error;
}	t_arg;


t_arg	manage_arg(int ac, char **av);

void	arg_tostring(t_arg arg);

#endif
