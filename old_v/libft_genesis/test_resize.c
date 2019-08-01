#include <stdio.h>
#include "string_resize.h"

void test_delete_char()
{
	int c = 0;
	t_string_resize *st;

	st = string_resize_make_with_str(100, "Go in the future.");
        while (st->len)
                string_resize_del_char(st, 0);
	if (st->len == 0 && ft_strlen(st->str) == 0)
		printf("Good.\n");
	else
		printf("False.\n");
}

void test_add_char(char *str)
{
	int c;
	t_string_resize *st;

	c = 0;
	st = string_resize_make(100);
	while (c < ft_strlen(str))
	{
		string_resize_add_char(st, st->len, str[c]);
		c++;
	}
	printf("--->%s|%s\n", str, st->str);
}

void test_add_char2(char *str)
{
        int c;
        t_string_resize *st;

        c = 0;
        st = string_resize_make(100);
        while (c < ft_strlen(str))
        {
                string_resize_add_char(st, 0, str[c]);
                c++;
        }
        printf("--->%s|%s\n", str, st->str);
}

/*
test d ajout au debut puis au milieu
*/
void test_add_char3(char *str, char *str2)
{
	int c;
	t_string_resize *st;

	c = 0;
	st = string_resize_make(100);
	while (st->len < ft_strlen(str))
		string_resize_add_char(st, st->len, str[st->len]);
	while (c < ft_strlen(str2))
	{
		string_resize_add_char(st, c + ft_strlen(str) / 2, str2[c]);
		c++;
	}
	printf("%s\n", st->str);
}

int main(int argc, char **argv)
{
	int c = 0;
	t_string_resize *st;

	test_delete_char();
	test_add_char("Miaou !");
	test_add_char2("Modulo bitch");	
	test_add_char3("Rouf", "Miaou");
	return (1);
}
