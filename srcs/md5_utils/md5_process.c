#include "ft_md5.h"

uint32_t	md5_process_f(uint32_t x, uint32_t y, uint32_t z)
{
	return (x & y) | ((~x) & z);
}

uint32_t	md5_process_g(uint32_t x, uint32_t y, uint32_t z)
{
	return (x & z) | ((y & (~z)));
}

uint32_t	md5_process_h(uint32_t x, uint32_t y, uint32_t z)
{
	return (x ^ y ^ z);
}

uint32_t	md5_process_i(uint32_t x, uint32_t y, uint32_t z)
{
	return (y ^ (x | (~z)));
}
