#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include "ft_display.h"

const uint32_t g_r[] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,\
			5, 9,  14, 20, 5, 9,  14, 20, 5, 9,  14, 20, 5, 9,  14, 20,\
			4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,\
			6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

const uint32_t g_k[] =  {\
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,\
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,\
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,\
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,\
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,\
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,\
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,\
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,\
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,\
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,\
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,\
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,\
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,\
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,\
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,\
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

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

typedef struct s_word
{
	uint32_t word[4];
	uint32_t *msg;
	size_t len;
	size_t nb_turn;
} t_word;

t_word word_init_md5(void)
{
	t_word word;

	//low order bit
	word.word[0] = 0x67452301;
	word.word[1] = 0xefcdab89;
	word.word[2] = 0x98badcfe;
	word.word[3] = 0x10325476;
	return (word);
}

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
void	word_padding_md5(t_word *word, char *str)
{
	size_t init_len;
	size_t size_to_add; // taille a ajouter pour obtenir une string n % 512 == 448
	size_t res_mod;

	size_to_add = 0;
	init_len = strlen(str) + 1;
	while ((init_len + size_to_add) % 64 != 56)
		size_to_add++;
	// 64 for len msg
	if (!(word->msg = (uint32_t *)(malloc(sizeof(char) * (init_len + size_to_add) + 64))))
	{
		printf("error malloc ...\n");
		exit(1);
	}
	word->len = (init_len + size_to_add + 64/8);
	bzero((void *)word->msg, word->len);
	strcpy((char *)word->msg, str);
	uint8_t *b8 = &(((uint8_t *)word->msg)[word->len - 8]);
	uint64_t *b64 = (uint64_t *)(b8);
	*b64 = swap64((uint64_t)init_len * 8);
	*b64 = (init_len-1)*8;
	printf("wordlen : %ld\n", word->len); //exit(1);
	((uint8_t *)word->msg)[init_len - 1] = 128;
	printf("---> msg:%s|%lu|%lu + %lu\n", (char *)word->msg, word->len, init_len, size_to_add);
	hexa_display((char *)word->msg, word->len);
	hexa_display32((uint32_t *)word->msg, 16);
	word->nb_turn = word->len / 64;
	//exit(1);
}

void word_tostring_md5(t_word *word)
{
	printf("word : {a : %x, b : %x, c : %x, d : %x}\n", word->word[0], word->word[1], word->word[2], word->word[3]);
}

uint32_t process_f(uint32_t x, uint32_t y, uint32_t z)
{
	return (x & y) | ((~x) & z);
}

uint32_t process_g(uint32_t x, uint32_t y, uint32_t z)
{
        return (x & z) | ((y & (~z)));
}

uint32_t process_h(uint32_t x, uint32_t y, uint32_t z)
{
	return (x ^ y ^ z);
}

uint32_t process_i(uint32_t x, uint32_t y, uint32_t z)
{
	return (y ^ (x | (~z)));
}

uint32_t	leftrotate(uint32_t x, uint32_t c)
{
	return (((x) << (c)) | ((x) >> (32 - (c))));
}

/*
** word : data structure who contain update element
** data : begin element perform actual hash
** nb_word size of this part, utils to stop end block without segfault
*/
void md5_process(t_word *word, uint32_t *data)
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
			f = process_f(tmp[1], tmp[2], tmp[3]);
			g = count;
		}
		else if (count < 32)
		{
			f = process_g(tmp[1], tmp[2], tmp[3]);
			g = (5*count + 1) % 16;
		}
		else if (count < 48)
		{
			f = process_h(tmp[1], tmp[2], tmp[3]);
			g = (3*count + 5) % 16;
		}
		else
		{
			f = process_i(tmp[1], tmp[2], tmp[3]);
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

void md5_process_all(t_word *word)
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

void md5_display(t_word *word)
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
	t_word word;

	printf("----------------\n");
	word = word_init_md5();
	word_padding_md5(&word, str);
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
