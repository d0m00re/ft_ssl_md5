#include "ft_sha256.h"
#include "ft_string.h"

char *sha256_get(char *str)
{
	t_word_sha256 word;
	char *hash;
	size_t size;

	size = 8 * 8 + 1;
	if (!(hash = malloc(sizeof(char) * size)))
		return (0);
	bzero(hash, size);
	printf("Sha 256 run :)\n");
	word = word_init_sha256(str);
	sha256_run(&word);
	printf("End run ...\n");
	store_hex128_to_32_char(hash, word.word, 8);
        printf("%s\n", str);
	printf("---> hash : %s\n", hash);
        return (hash);
}
