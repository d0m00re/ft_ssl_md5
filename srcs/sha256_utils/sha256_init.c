#include "ft_sha256.h"
#include "ft_stdlib.h"

void	display_hex_string(char *str, size_t len)
{
	size_t	count;

	count = 0;
	printf("Display padding :\n[\n");
	while (count < len)
	{
		printf("%x ", str[count]);
		count++;
	}
	printf("]\n");
}

// same of smd5 init - merger next version
void	word_padding_sha256(t_word_sha256 *word, char *str)
{
	size_t init_len;
	size_t size_to_add; // taille a ajouter pour obtenir une string n % 512 == 448
	size_t count;


	size_to_add = 0;
	init_len = strlen(str) + 1;
	while ((init_len + size_to_add) % 64 != 56)
		size_to_add++;
	// 64 for len msg
	if (!(word->msg = (uint32_t *)(malloc(sizeof(char) * (init_len + size_to_add) + 64))))
		exit(1);
	word->len = (init_len + size_to_add + 64/8);
	bzero((void *)word->msg, word->len);
	strcpy((char *)word->msg, str);
	count = 0;
	((uint8_t *)word->msg)[init_len - 1] = 128;
	// a reverse
	uint8_t *b8 = &(((uint8_t *)word->msg)[word->len - 8]);
	uint64_t *b64 = (uint64_t *)(b8);
	*b64 = swap64((init_len-1)*8);
	*b64 = (init_len-1)*8;
	word->nb_turn = word->len / 64;
	//display_hex_string((char *)(word->msg), word->nb_turn * 64);
	// reverse 32 bits words
	while (count < (word->len / 4))
	{
		word->msg[count] = swap32(word->msg[count]);
		count++;
	}
	uint32_t tmp;
	tmp = word->msg[count-1];
	//printf("----> %ld\n", count-1);
	word->msg[count-1] = swap32(word->msg[count-2]);
	word->msg[count-2] = swap32(tmp);
	//display_hex_string((char *)(word->msg), word->nb_turn * 64);
}

t_word_sha256	word_init_sha256(char *str)
{
	t_word_sha256 word;
	char *tmp;

	bzero(&word, sizeof(word));
	word.word[0] = 0x6a09e667;
	word.word[1] = 0xbb67ae85;
	word.word[2] = 0x3c6ef372;
	word.word[3] = 0xa54ff53a;
	word.word[4] = 0x510e527f;
	word.word[5] = 0x9b05688c;
	word.word[6] = 0x1f83d9ab;
	word.word[7] = 0x5be0cd19;
	word_padding_sha256(&word, str);
	tmp = (char *)(word.msg);
	return (word);
}
