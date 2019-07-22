CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = hash_bitch
MAIN_NAME = hash
SRC_PATH = srcs
SRC_M_MD5_PATH = md5_utils
OBJ_PATH = srcs
# LIBFT BITCH
LIBFT_PATH = libft_genesis
INC = includes
INC_PATH= ./$(LIBFT_PATH)/$(INC)

#################################
############ SOURCES
#################################
SRC_M_MD5 = md5_global.c  md5_init.c  md5_process.c  md5_run.c

#############################
############ OBJECT GENERQTION
OBJ_M_MD5 = $(patsubst %.c, %.o, $(SRC_M_MD5))
SRC_MD5 =  $(addprefix ./$(SRC_M_MD5_PATH)/, $(SRC_M_MD5))
OBJ_MD5 =  $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_MD5))

OBJS = $(OBJ_MD5)

#################################
############ RULES
#################################

all: $(NAME)

$(NAME): $(OBJ_MD5) libft
	gcc main.c $(OBJ_MD5) $(LIBFT_PATH)/libft.a  -o $(MAIN_NAME) -I $(INC_PATH) -I $(INC)

# rep generation file
$(OBJ_MD5): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_MD5_PATH)/%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -c $< -o $@

fclean:
	rm -f $(MAIN_NAME)

#libft rules
libft:
	@cd $(LIBFT_PATH) && make

clean_libft:
	@cd $(LIBFT_PATH) && make fclean
	@echo "$(COL_WHITE)[ FCLEAN LIBFT ]\n"

