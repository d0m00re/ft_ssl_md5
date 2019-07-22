#ifndef FT_DISPLAY_H
# define FT_DISPLAY_H

# include <stdint.h>
# include <unistd.h>

void ft_putchar(int c);

void ft_putstr(char *str);

void display_hex_u8(uint8_t v);

void display_hex_u32(uint32_t v);

#endif
