#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include "ft_display.h"
#include "ft_string.h"
#include "ft_md5.h"
#include "ft_arg.h"

extern const uint32_t g_r[];

/*
void init_g_k(void)
{
	int count = 0;

	while (count < 64):
	{
		g_k[count] = floor(abs(sin(i+1)) * (4294967296);
		count++;
	}
}
*/

void hexa_display(char *str, size_t size)
{
	size_t count;
	uint8_t tmp;
	printf("mem display :\n");
	printf("%lu\n", size);//exit(1);
	count = 0;
	while (count < size)
	{
		tmp = str[count];
		printf("%x|", tmp);
		count++;
	}
	printf("\n");
}

void hexa_display32(uint32_t *str, size_t size)
{
        size_t count;
        uint32_t tmp;
        printf("mem display :\n");
        printf("%lu\n", size);//exit(1);
        count = 0;
        while (count < size)
        {
                tmp = str[count];
                printf("%u|", tmp);
                count++;
        }
        printf("\n");
}


/*
ajouter le bit "1" au message
ajouter le bit "0" jusqu'à ce que la taille du message en bits soit égale à 448 (mod 512)
ajouter la taille du message initial(avant le padding) codée en 64-bit little-endian au message
448 / 8 : 56 octet
512 / 8 : 64 octet
*/
void word_tostring_md5(t_word_md5 *word)
{
	printf("word : {a : %x, b : %x, c : %x, d : %x}\n", word->word[0], word->word[1], word->word[2], word->word[3]);
}

void md5_display(t_word_md5 *word)
{
	ft_putstr("\nmd5 hash : {");
	display_hex_u32(word->word[0]);
	display_hex_u32(word->word[1]);
	display_hex_u32(word->word[2]);
	display_hex_u32(word->word[3]);
	ft_putstr("}\n");
}

char *md5(char *str)
{
	t_word_md5 word;

	printf("----------------\n");
	word = word_init_md5(str);
	md5_run(&word);
	//word_tostring_md5(&word);
	md5_display(&word);
	printf("______________________________\n");
	return ("hash");
}

char *sha256(char *str)
{
	ft_putstr("sha256:\n");
}

int ft_usage()
{
	ft_putstr("usage:\n\t./hash [md5/sha256] [string]\n");
	return (1);
}

#define MD5_STRING "md5"
#define SHA256_STRING "sha256"



//substring_is_present_with_delimiter(char *pattern, char *elem, char sep)

#include <math.h>

void arg_tostring(t_arg arg)
{
	printf("type hash : %d\n", arg.type_hash);
	printf("q : %d| p : %d | s : %d | r : %d\n", arg.q, arg.p, arg.s, arg.r);
	printf("string --> %s\n", arg.string);
	printf("file : %d | name file :%s\n", arg.file, arg.name_file);
	printf("error : %d\n", arg.error);
}

int power_of_two(int nb)
{
	int c = 0;
	int tot = 1;

	while (c < nb)
	{
		tot *= 2;
		c++;
	}
	return (tot);
}

char *get_fd0(void)
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

int main(int ac, char **av)
{
	t_arg arg;
	char *buff;

	arg = manage_arg(ac, av);
	arg_tostring(arg);
	if (arg.error)
	{
		ft_putstr("error argument ....\n");
		return (arg.error);
	}

	if (arg.p)
	{
		ft_putstr("get fd0 :\n");
		buff = get_fd0();
	}

	printf("buff : %s\n", buff);

        if (arg.type_hash == 1)
        {
		md5(buff);
        }
        else if (arg.type_hash == 2)
                sha256(av[2]);
        else
                return (ft_usage("usage:\n\t./hash [md5/sha256] [string]\n"));

}
