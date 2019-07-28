#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "ft_arg.h"
# include "ft_display.h"

void	display_hash_string_and_file(char *hash, t_arg arg, char sep, char *name);

void	display_hash_name(int hash_num);

int	ft_usage(char *str, int ret);

#endif
