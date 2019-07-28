#include "ft_display.h"
#include "ft_arg.h"
#include <stdlib.h>

static char *get_fd0(void)
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


void	ft_manage_arg_p(t_arg arg, char *(hash)(char *str, size_t size))
{
	char *tstr;
	char *buff;

	tstr = 0;
	if (arg.p)
	{
		buff = get_fd0();
		if (arg.pp)
			ft_putstr(buff);
		tstr = hash(buff, ft_strlen(buff));
		ft_putstr(tstr);
		ft_putchar('\n');
		free(tstr);
		free(buff);
	}
}
