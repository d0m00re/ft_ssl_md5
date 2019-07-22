CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
MAIN_NAME = hash
SRC_PATH = srcs

SRC_M_MD5_PATH = md5_utils

SRC_M_MD5 = ft_md5.h  md5_global.c  md5_init.c  md5_process.c  md5_run.c



all:
	gcc main.c ft_display.c -I . -I md5_utils ./md5_utils/md5_global.c ./md5_utils/md5_init.c ./md5_utils/md5_process.c ./md5_utils/md5_run.c -o $(MAIN_NAME)

fclean:
	rm -f $(MAIN_NAME)
