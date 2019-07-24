CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = hash_bitch
MAIN_NAME = hash
SRC_PATH = srcs

# PATH MODULE
SRC_M_MD5_PATH    = md5_utils
SRC_M_SHA256_PATH = sha256_utils
SRC_M_ARG_PATH    = ft_arg

OBJ_PATH = srcs
# LIBFT BITCH
LIBFT_PATH = libft_genesis
INC = includes
INC_PATH= ./$(LIBFT_PATH)/$(INC)

#################################
############ SOURCES
#################################
SRC_M_MD5 =     md5_global.c  md5_init.c  md5_process.c  md5_run.c md5_destroy.c md5_get.c
SRC_M_SHA256 =  sha256_get.c  sha256_init.c sha256_run.c  sha256_logical.c sha256_logical2.c
SRC_M_ARG = ft_arg.c

#############################
############ OBJECT GENERQTION
OBJ_M_MD5 =  $(patsubst %.c, %.o, $(SRC_M_MD5))
SRC_MD5   =  $(addprefix ./$(SRC_M_MD5_PATH)/, $(SRC_M_MD5))
OBJ_MD5   =  $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_MD5))

OBJ_M_SHA256 =  $(patsubst %.c, %.o, $(SRC_M_SHA256))
SRC_SHA256   =  $(addprefix ./$(SRC_M_SHA256_PATH)/, $(SRC_M_SHA256))
OBJ_SHA256   =  $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_SHA256))

OBJ_M_ARG =  $(patsubst %.c, %.o, $(SRC_M_ARG))
SRC_ARG   =  $(addprefix ./$(SRC_M_ARG_PATH)/, $(SRC_M_ARG))
OBJ_ARG   =  $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_ARG))

OBJS = $(OBJ_MD5) $(OBJ_SHA256) $(OBJS_ARG)

#################################
############ RULES
#################################

all: $(NAME)

$(NAME): $(OBJ_MD5) $(OBJ_SHA256) $(OBJ_ARG) libft
	gcc main.c $(OBJ_MD5) $(OBJ_SHA256) $(OBJ_ARG) $(LIBFT_PATH)/libft.a  -o $(MAIN_NAME) -I $(INC_PATH) -I $(INC)

# rep generation file
$(OBJ_MD5): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_MD5_PATH)/%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -c $< -o $@

$(OBJ_SHA256): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_SHA256_PATH)/%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -c $< -o $@

$(OBJ_ARG): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_ARG_PATH)/%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -c $< -o $@

fclean:
	rm -f $(MAIN_NAME)

#libft rules
libft:
	@cd $(LIBFT_PATH) && make

clean_libft:
	@cd $(LIBFT_PATH) && make fclean
	@echo "$(COL_WHITE)[ FCLEAN LIBFT ]\n"

