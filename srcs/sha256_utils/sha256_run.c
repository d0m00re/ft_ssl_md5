#include "ft_sha256.h"
#include <stdio.h>

static uint32_t g_sha256_k[64] = {\
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,\
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,\
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,\
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,\
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,\
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,\
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,\
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,\
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,\
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,\
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,\
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,\
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,\
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,\
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,\
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

void                    sha256_process(t_word_sha256 *word, uint32_t *data)
{
	int count = 0;
	uint32_t w[64];
	uint32_t tmp[8];

	bzero(w, sizeof(uint32_t) * 64);
	// 1 ) repare the message schedule w
	printf("Step 1\n");
	while (count < 16)
	{
		printf("turn ....\n");
		w[count] = data[count];
		count++;
	}
	printf("step 2\n");
	while (count < 64)
	{
		w[count] = f_ssig1(w[count-2]) + w[count - 7] + f_ssig0(count-15) + w[count-16];
		count++;
	}
	// 2 ) initialize the wortking variables
	count = 0;
	printf("step3\n");
	while (count < 8)
	{
		tmp[count] = word->word[count];
		count++;
	}

	// 3 ) perform the main hash computation
	printf("step4\n");
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

	printf("%x\n", word->word[0]);
}

void			sha256_run(t_word_sha256 *word)
{
	size_t count;

	count = 0;
	while (count < word->nb_turn)
	{
		printf("SHA256 turn %ld\n", count);
		sha256_process(word, &(word->msg[count * 16]));
		count++;
	}
	printf("sha 256 last turn\n");
}
