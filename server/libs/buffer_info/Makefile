##
## EPITECH PROJECT, 2024
## myteams
## File description:
## build the ftp lib
##
YEL=\033[1;33m
GRN='\033[0;32m'
RED='\033[0;31m'
NC=\033[0m # No Color

NAME 		=	libmybufferinfo.so

SRC 		=	mybuffer_info_array_get.c \
				mybuffer_info_array_destroy.c \
				mybuffer_info_array_dump.c \
				mybuffer_info_array_init.c \
				mybuffer_info_strdup.c
SRC_DIR 	=	src

OBJ_FILES 	=	mybuffer_info_array_get.o \
				mybuffer_info_array_destroy.o \
				mybuffer_info_array_dump.o \
				mybuffer_info_array_init.o \
				mybuffer_info_strdup.o
OBJ_DIR 	= 	obj
OBJ_DIR_FILES	=	$(patsubst %,$(OBJ_DIR)/%,$(OBJ_FILES))

CFLAGS 		=	-Wall -Wextra -g -Wno-unused-variable
INCLUDES 	=	-iquote./includes/

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc -c -fPIC -Iint -o $@ $< $(CFLAGS) $(INCLUDES)

all: $(OBJ_DIR_FILES)
	@gcc -shared -fPIC -o $(NAME) $^
	@echo -e "$(YEL)\t$(NAME) done!$(NC)"

clean:
	@rm -f --verbose $(OBJ_DIR_FILES)

fclean: clean
	@rm --verbose $(NAME) || true

tests_run:
	@gcc $(CFLAGS) tests/bufferinfo_t.c \
		src/mybuffer_info_array_init.c \
		src/mybuffer_info_array_destroy.c \
		src/mybuffer_info_array_dump.c \
		src/mybuffer_info_array_get.c \
		-o ./buffer_info_t.out
	@valgrind --leak-check=full ./buffer_info_t.out
	@rm ./buffer_info_t.out
	@gcc $(CFLAGS) tests/bufferinfo_t.c \
		src/mybuffer_info_array_init.c \
		src/mybuffer_info_array_destroy.c \
		src/mybuffer_info_array_dump.c \
		src/mybuffer_info_array_get.c \
		src/mybuffer_info_strdup.c \
		-o ./buffer_info_strdup_t.out
	@valgrind --leak-check=full ./buffer_info_strdup_t.out
	@rm ./buffer_info_strdup_t.out

re: fclean all

.Phony: all clean fclean tests_run re
