#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include "ft_display.h"
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


uint64_t                        swap64(uint64_t r)
{
        uint64_t                res;

        res  = (r << 56)  & 0xff00000000000000; //& 0x000000ff;
        res += ((r << 40) & 0x00ff000000000000);
        res += ((r << 24) & 0x0000ff0000000000);
        res += ((r << 8)  & 0x000000ff00000000);
        res += ((r >> 8)  & 0x00000000ff000000);
        res += ((r >> 24) & 0x0000000000ff0000);
        res += ((r >> 40) & 0x000000000000ff00);
        res += ((r >> 56) & 0x00000000000000ff);
	printf("\nswap64 : {%lu | %lu}\n", r, res);
	//exit(1);
        return (res);
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

uint32_t	leftrotate(uint32_t x, uint32_t c)
{
	return (((x) << (c)) | ((x) >> (32 - (c))));
}

void    md5_process(t_word_md5 *word, uint32_t *data);

void	md5_process(t_word_md5 *word, uint32_t *data)
{
	int count = 0;
	uint32_t tmp[4];
	uint32_t f;
	uint32_t g;

	//uint32_t *wstr = (uint32_t *)str;
	//int nb_word = strlen(str) / 4;
	//printf("Nb word 32bits : %d\n", nb_word);
	//bzero(tmp, sizeof(uint32_t) * 4);
	memcpy(tmp, word->word, sizeof(uint32_t) * 4);
	printf("step-1 : {a : %u, b : %u, c : %u, d : %u}\n", tmp[0], tmp[1], tmp[2], tmp[3]);
	while (count < 64)
	{
		if (count < 16)
		{
			f = md5_process_f(tmp[1], tmp[2], tmp[3]);
			g = count;
		}
		else if (count < 32)
		{
			f = md5_process_g(tmp[1], tmp[2], tmp[3]);
			g = (5*count + 1) % 16;
		}
		else if (count < 48)
		{
			f = md5_process_h(tmp[1], tmp[2], tmp[3]);
			g = (3*count + 5) % 16;
		}
		else
		{
			f = md5_process_i(tmp[1], tmp[2], tmp[3]);
			g = (7*count) % 16;
		}
		uint32_t temp = tmp[3];
		tmp[3] = tmp[2]; //d = c
		tmp[2] = tmp[1]; //c = b
		//((a + f + k[i] + w[g]) leftrotate r[i]) + b
		tmp[1] = leftrotate(tmp[0] + f + g_k[count] + word->msg[g], g_r[count]) + tmp[1];// ((a + f + k[i] + w[g]) leftrotate r[i]) + b
		tmp[0] = temp;
		printf("step %d : {a : %u, b : %u, c : %u, d : %u}\n", count, tmp[0], tmp[1], tmp[2], tmp[3]);
		count++;
	}
	printf("--> %d\n\n", tmp[0]);
	word->word[0] += tmp[0];
	word->word[1] += tmp[1];
	word->word[2] += tmp[2];
	word->word[3] += tmp[3];
}

void md5_process_all(t_word_md5 *word)
{
	int count;

	count = 0;
	printf("fuck you\n");
	while (count < word->nb_turn)
	{
		printf("MD5 : turn %d\n", count);
		md5_process(word, &(word->msg[count*16]));
		count++;
	}
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
	md5_process_all(&word);
	word_tostring_md5(&word);
	md5_display(&word);
	printf("______________________________\n");
	return ("hash");
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	md5(av[1]);
}
