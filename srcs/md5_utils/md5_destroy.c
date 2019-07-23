#include "ft_md5.h"

void	md5_destroy(t_word_md5 *word)
{
	if (word && word->msg)
		free(word->msg);
}
