#include "ft_sha256.h"
#include "ft_stdlib.h"
#include <stdio.h>

void	sha256_process(t_word_sha256 *word, uint32_t *data)
{
	int count = 0;
	uint32_t w[64];
	uint32_t tmp[8];

	bzero(w, sizeof(uint32_t) * 64);
	// 1 ) repare the message schedule w
	//printf("Step 1\n");
	while (count < 16)
	{
	//	printf("Data : %u | %u\n", w[count], data[count]);
		w[count] = data[count];
		count++;
	}
	//printf("step 2\n");
	while (count < 64)
	{
		w[count] = f_ssig1(w[count-2]) + w[count - 7] + f_ssig0(w[count-15]) + w[count-16];
		count++;
	}
	// 2 ) initialize the wortking variables
	count = 0;
	//printf("step3\n");
	while (count < 8)
	{
		tmp[count] = word->word[count];
		count++;
	}

	// 3 ) perform the main hash computation
	//printf("step4\n");
	count = 0;
	while (count < 64)
	{
		uint32_t t1 = tmp[7] + f_bsig1(tmp[4]) + f_ch(tmp[4], tmp[5], tmp[6]) + g_sha256_k[count] + w[count];
		uint32_t t2 = f_bsig0(tmp[0]) + f_maj(tmp[0],tmp[1],tmp[2]);
		tmp[7] = tmp[6];
		tmp[6] = tmp[5];
		tmp[5] = tmp[4];
		tmp[4] = tmp[3] + t1;
		tmp[3] = tmp[2];
		tmp[2] = tmp[1];
		tmp[1] = tmp[0];
		tmp[0] = t1 + t2;
		count++;
	}
	count = 0;
	while (count < 8)
	{
		word->word[count] += tmp[count];
		count++;
	}
}

void			sha256_run(t_word_sha256 *word)
{
	size_t count;

	count = 0;
	while (count < word->nb_turn)
	{
		sha256_process(word, &(word->msg[count * 16]));
		count++;
	}
	for (int i =0; i < 8; i++)
		word->word[i] = swap32(word->word[i]);
}
