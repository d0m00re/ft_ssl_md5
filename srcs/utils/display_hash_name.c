#include "ft_utils.h"

void	display_hash_name(int hash_num)
{
	if (hash_num == 0)
		ft_putstr("MD5 (");
	else
		ft_putstr("SHA256 (");
}
