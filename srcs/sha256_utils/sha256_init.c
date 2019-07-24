#include "ft_sha256.h"

// same of smd5 init - merger next version
void    word_padding_sha256(t_word_sha256 *word, char *str)
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

t_word_sha256	word_init_sha256(char *str)
{
	t_word_sha256 word;

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
	return (word);
}
