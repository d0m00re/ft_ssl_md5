#include "ft_md5.h"

static uint32_t	leftrotate(uint32_t x, uint32_t c)
{
	return (((x) << (c)) | ((x) >> (32 - (c))));
}

static void	md5_process_core(uint32_t *f, uint32_t *g, uint32_t *tmp, int count)
{
	if (count < 16)
	{
		*f = md5_process_f(tmp[1], tmp[2], tmp[3]);
		*g = count;
	}
	else if (count < 32)
	{
		*f = md5_process_g(tmp[1], tmp[2], tmp[3]);
		*g = (5 * count + 1) % 16;
	}
	else if (count < 48)
	{
		*f = md5_process_h(tmp[1], tmp[2], tmp[3]);
		*g = (3 * count + 5) % 16;
	}
	else
	{
		*f = md5_process_i(tmp[1], tmp[2], tmp[3]);
		*g = (7 * count) % 16;
	}
}

static void	md5_process(t_word_md5 *word, uint32_t *data)
{
	uint32_t tmp[5];
	uint32_t f;
	uint32_t g;
	uint32_t temp;

	tmp[4] = 0;
	memcpy(tmp, word->word, sizeof(uint32_t) * 4);
	while (tmp[4] < 64)
	{
	//	printf("%d : turn ... %x %x %x %x\n", tmp[4], tmp[0], tmp[1], tmp[2], tmp[3]);
		md5_process_core(&f, &g, tmp, tmp[4]);
		temp = tmp[3];
		tmp[3] = tmp[2]; //d = c
		tmp[2] = tmp[1]; //c = b
		tmp[1] = leftrotate(tmp[0] + f + g_k[tmp[4]] + data[g], g_r[tmp[4]]) + tmp[1];// ((a + f + k[i] + w[g]) leftrotate r[i]) + b
		tmp[0] = temp;
		tmp[4] += 1;
	}
	word->word[0] += tmp[0];
	word->word[1] += tmp[1];
	word->word[2] += tmp[2];
	word->word[3] += tmp[3];
//	 printf("Last turn : turn ... %x %x %x %x\n", tmp[0], tmp[1], tmp[2], tmp[3]);
}

void	md5_run(t_word_md5 *word)
{
	size_t count;

	count = 0;
//	printf("---> %ld\n", word->nb_turn);
	while (count < word->nb_turn)
	{
		printf("MD5 : turn %ld < %ld\n", count, word->nb_turn);
		md5_process(word, &(word->msg[count*16]));
		count++;
	}
//	 printf("Last turn : turn ... %x %x %x %x\n", word->word[0], word->word[1], word->word[2], word->word[3]);
}
