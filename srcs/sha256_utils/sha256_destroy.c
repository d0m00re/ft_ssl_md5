#include "ft_sha256.h"

void	sha256_destroy(t_word_sha256 *word)
{
	if (word && word->msg)
		free(word->msg);
}
