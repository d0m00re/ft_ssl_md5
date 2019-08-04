CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = hash_bitch
MAIN_NAME = ft_ssl
SRC_PATH = srcs
RM = rm -f

INCLUDES = includes/ft_arg.h includes/ft_md5.h includes/ft_sha256.h includes/ft_utils.h

# PATH MODULE
SRC_M_UTILS_PATH = utils
SRC_M_MD5_PATH    = md5_utils
SRC_M_SHA256_PATH = sha256_utils
SRC_M_ARG_PATH    = ft_arg

OBJ_PATH = srcs
# LIBFT BITCH
LIBFT_PATH = libft_genesis
LIBFT_NAME = libft.a
LIBFT_FLAGS = -lft -L $(LIBFT_PATH)
INC = includes
INC_PATH= ./$(LIBFT_PATH)/$(INC)

#################################
############ SOURCES
#################################
SRC_M_UTILS = ft_usage.c display_hash_name.c display_hash_string_and_file.c main.c
SRC_M_MD5 =     md5_global.c    md5_init.c  md5_process.c  md5_run.c md5_destroy.c md5_get.c
SRC_M_SHA256 =  sha256_global.c sha256_get.c  sha256_init.c sha256_run.c  sha256_logical.c sha256_logical2.c sha256_destroy.c
SRC_M_ARG = ft_arg.c ft_manage_arg_p.c ft_manage_arg_file.c ft_manage_arg_s.c global_hash.c

#############################
############ OBJECT GENERATION
OBJ_M_UTILS =  $(patsubst %.c, %.o, $(SRC_M_UTILS))
SRC_UTILS   =  $(addprefix ./$(SRC_M_UTILS_PATH)/, $(SRC_M_UTILS))
OBJ_UTILS   =  $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_UTILS))

OBJ_M_MD5 =  $(patsubst %.c, %.o, $(SRC_M_MD5))
SRC_MD5   =  $(addprefix ./$(SRC_M_MD5_PATH)/, $(SRC_M_MD5))
OBJ_MD5   =  $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_MD5))

OBJ_M_SHA256 =  $(patsubst %.c, %.o, $(SRC_M_SHA256))
SRC_SHA256   =  $(addprefix ./$(SRC_M_SHA256_PATH)/, $(SRC_M_SHA256))
OBJ_SHA256   =  $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_SHA256))

OBJ_M_ARG =  $(patsubst %.c, %.o, $(SRC_M_ARG))
SRC_ARG   =  $(addprefix ./$(SRC_M_ARG_PATH)/, $(SRC_M_ARG))
OBJ_ARG   =  $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_ARG))

OBJS = $(OBJ_MD5) $(OBJ_SHA256) $(OBJ_ARG) $(OBJ_UTILS)

#################################
############ RULES
#################################

.PHONY: all clean fclean re

all: libft_genesis $(MAIN_NAME)

$(MAIN_NAME): $(OBJ_MD5) $(OBJ_SHA256) $(OBJ_ARG) $(OBJ_UTILS)
	$(CC) $(CFLAGS) $(OBJ_MD5) $(OBJ_SHA256) $(OBJ_ARG) $(OBJ_UTILS) $(LIBFT_FLAGS)/ -I $(INC_PATH) -I $(INC) -o $(MAIN_NAME)

# rep generation file
$(OBJ_UTILS): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_UTILS_PATH)%.c $(INCLUDES)
	$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -c $< -o $@

$(OBJ_MD5): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_MD5_PATH)%.c $(INCLUDES)
	$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -c $< -o $@

$(OBJ_SHA256): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_SHA256_PATH)%.c $(INCLUDES)
	$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -c $< -o $@

$(OBJ_ARG): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_ARG_PATH)%.c $(INCLUDES)
	$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -c $< -o $@

clean: clean_libft
	$(RM) $(OBJS)

fclean: clean fclean_libft
	$(RM) $(MAIN_NAME)

re : fclean all

##############################
############### libft rules ##
libft_genesis:
	make -C $(LIBFT_PATH)

fclean_libft:
	@cd $(LIBFT_PATH) && make fclean
	@echo "$(COL_WHITE)[ FCLEAN LIBFT ]\n"

clean_libft:
	@cd $(LIBFT_PATH) && make clean
	@echo "$(COL_WHITE)[ CLEAN LIBFT ]\n"
