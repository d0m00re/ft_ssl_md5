#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_string.h"

/*
	permet de trouver si il y a un des sous chaine egal a elem
	les substring ae separate by a delimiter(sep)

        printf("%d\n",  is_substring_is_present_with_delimiter("md5|sha256", "md5", '|'));
		return 1
        printf("%d\n",  is_substring_is_present_with_delimiter("md5|sha256", "sha256", '|'));
		return 2
        printf("%d\n",  is_substring_is_present_with_delimiter("md5|sha256", "", '|'));
		return 0
        printf("%d\n",  is_substring_is_present_with_delimiter("md5|sha256", "sdfsdfsfsss", '|'));
		return 0
*/
int substring_is_present_with_delimiter(char *pattern, char *elem, char sep)
{
	int act_pattern;
	char **split;
	int count;

	split = ft_strsplit(pattern, sep);
	act_pattern = 1;
	while (split && split[act_pattern - 1])
	{
		if (strcmp(split[act_pattern - 1], elem) == 0)
			return (act_pattern);
		act_pattern++;
	}
	return (0);
}


int main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	printf("%d\n",  is_substring_is_present_with_delimiter("md5|sha256", "md5", '|'));
	printf("%d\n",  is_substring_is_present_with_delimiter("md5|sha256", "sha256", '|'));
	printf("%d\n",  is_substring_is_present_with_delimiter("md5|sha256", "", '|'));
	printf("%d\n",  is_substring_is_present_with_delimiter("md5|sha256", "sdfsdfsfsss", '|'));
	return (1);
}
