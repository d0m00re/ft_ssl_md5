#include "ft_display.h"
#include <string.h>

void ft_putchar(int c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	size_t size;

	size = strlen(str);
	write(1, str, size);
}

void display_hex_u8(uint8_t v)
{
	int a;
	int b;

	a = v / 16;
	b = v % 16;
	if (a > 9)
		ft_putchar('a' + a - 10);
	else
		ft_putchar('0' + a );
	if (b > 9)
		ft_putchar('a' + b - 10);
	else
                ft_putchar('0' + b);
}

void display_hex_u32(uint32_t v)
{
	int c;
	uint8_t *tab;

	c = 0;
	tab = (uint8_t *)(&v);
	while (c < 4)
	{
		display_hex_u8(tab[c]);
		c++;
	}
}
