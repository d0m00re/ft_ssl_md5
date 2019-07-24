#include "ft_md5.h"

static uint32_t        leftrotate(uint32_t x, uint32_t c)
{
        return (((x) << (c)) | ((x) >> (32 - (c))));
}

static void    md5_process(t_word_md5 *word, uint32_t *data)
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
                        f = md5_process_f(tmp[1], tmp[2], tmp[3]);
                        g = count;
                }
                else if (count < 32)
                {
                        f = md5_process_g(tmp[1], tmp[2], tmp[3]);
                        g = (5*count + 1) % 16;
                }
                else if (count < 48)
                {
                        f = md5_process_h(tmp[1], tmp[2], tmp[3]);
                        g = (3*count + 5) % 16;
                }
                else
                {
                        f = md5_process_i(tmp[1], tmp[2], tmp[3]);
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

void md5_run(t_word_md5 *word)
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
