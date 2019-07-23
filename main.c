#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include "ft_display.h"
#include "ft_string.h"
#include "ft_md5.h"

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


/*
int get_type_hash(char *string, char *arg)
{
	return (1);
}*/
/*
typedef struct s_arg
{
	short type_hash;
} t_arg;
*/

//substring_is_present_with_delimiter(char *pattern, char *elem, char sep)

#include <math.h>

int main(int ac, char **av)
{
	uint8_t flag;
	int type_hash;
	if (ac < 2)
		return (ft_usage());

	type_hash = substring_is_present_with_delimiter("md5|sha256", av[1], '|');

	int c = 3;

	while (c < ac)
	{
		int tmp = substring_is_present_with_delimiter("-p|-q|-s|-r", av[c], '|');
		if (tmp == 3)
		{
			c++;
			if (c < ac)
			{
				printf("md5 string : %s\n", av[c]);
			}
			else
			{
				printf("no string ...\n");
				exit(1);
			}
		}
		printf("argument found : %d\n", tmp);
		c++;
	}


	if (type_hash == 1)
	{
		if (ac == 3)
			md5(av[2]);
		else
		{
			size_t count = 0;
			char buff[200];
			bzero(buff, 200);
			while (read(0, &(buff[count]), 1) && buff[count] != 10)
			{count++;}
			for (int x = 0; buff[x]; x++)
				printf("--> %d\n", buff[x]);
			md5(buff);
		}
	}
	else if (type_hash == 2)
		sha256(av[2]);
	else
		return (ft_usage("usage:\n\t./hash [md5/sha256] [string]\n"));
	return (0);
}
