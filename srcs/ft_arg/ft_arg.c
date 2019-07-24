#include "ft_arg.h"
#include <stdio.h>

t_arg manage_arg(int ac, char **av)
{
        t_arg arg;
        int count;
        int tmp;

        bzero(&arg, sizeof(arg));
        arg.type_hash =  substring_is_present_with_delimiter("md5|sha256", av[1], '|');
        if (arg.type_hash == 0)
        {
                arg.error = 1;
                return (arg);
        }
        count = 2;
        while (count < ac)
        {
                tmp = substring_is_present_with_delimiter("-p|-q|-s|-r", av[count], '|');
                if (tmp == 1)
                        arg.p = 1;
                else if (tmp == 2)
                        arg.q = 1;
                else if (tmp == 3)
                {
                        arg.s += 1;
                        count++;
                        if (count < ac)
                                arg.string = av[count];
                        else
                        {
                                arg.error = 4;
                                return (arg);
                        }
                }
                else if (tmp == 4)
                        arg.r = 1;
                else if (tmp == 0 && arg.file == 0)
                {
                        arg.file = 1;
                        arg.name_file = av[count];
                }
                else //name file
                {
                        arg.error = 3;
                        return (arg);
                }
                count++;
        }
        // set stdout if we need that
        if (arg.s == 0 && arg.file == 0)
                arg.p = 1;
        return (arg);
}

