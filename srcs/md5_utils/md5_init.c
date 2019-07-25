#include "ft_md5.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include "ft_display.h"

/*
** word : data structure who contain update element
** data : begin element perform actual hash
** nb_word_md5 size of this part, utils to stop end block without segfault
*/

void	word_padding_md5(t_word_md5 *word, char *str)
{
	size_t init_len;
	size_t size_to_add; // taille a ajouter pour obtenir une string n % 512 == 448

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
	*b64 = (init_len-1)*8;
	((uint8_t *)word->msg)[init_len - 1] = 128;
	word->nb_turn = word->len / 64;
	printf("word->len : %ld | %ld\n", word->len, word->nb_turn);
}

t_word_md5	word_init_md5(char *str)
{
	t_word_md5	word;

	printf("str : %s\n", str);
        //low order bit
	word.word[0] = 0x67452301;
	word.word[1] = 0xefcdab89;
	word.word[2] = 0x98badcfe;
	word.word[3] = 0x10325476;
	word_padding_md5(&word, str);
	return (word);
}
