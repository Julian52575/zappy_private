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

NAME 		=	libgenericlinked.so

SRC_FILES 	=	mygeneric_linked_list_init.c \
				mygeneric_linked_list_delink.c \
				mygeneric_linked_list_link.c \
				mygeneric_linked_list_destroy.c \
				mygeneric_linked_list_handler_add_node.c \
				mygeneric_linked_list_handler_init.c \
				mygeneric_linked_list_handler_find.c \
				mygeneric_linked_list_handler_destroy.c \
				mygeneric_linked_list_handler_dump.c \
				mygeneric_linked_list_handler_remove_node.c \
				mygeneric_linked_list_set_uuid.c
SRC_DIR 	=	src
SRC_DIR_FILES	=	$(patsubst %,$(SRC_DIR)/%,$(SRC_FILES))
OBJ_FILES 	=	mygeneric_linked_list_init.o \
				mygeneric_linked_list_delink.o \
				mygeneric_linked_list_link.o \
				mygeneric_linked_list_destroy.o \
				mygeneric_linked_list_handler_add_node.o \
				mygeneric_linked_list_handler_init.o \
				mygeneric_linked_list_handler_find.o \
				mygeneric_linked_list_handler_destroy.o \
				mygeneric_linked_list_handler_dump.o \
				mygeneric_linked_list_handler_remove_node.o \
				mygeneric_linked_list_set_uuid.o
OBJ_DIR 	= 	obj
OBJ_DIR_FILES	=	$(patsubst %,$(OBJ_DIR)/%,$(OBJ_FILES))

CFLAGS 		=	-luuid -Wall -Wextra -g -Wno-unused-variable
INCLUDES 	=	-iquote./includes/

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc -c -Iint -o $@ $< $(CFLAGS) $(INCLUDES)

all: $(OBJ_DIR_FILES)
	@gcc -shared -fPIC -o $(NAME) $^
	@echo -e "$(YEL)\t$(NAME) done!$(NC)"

clean:
	@rm -f --verbose $(OBJ_DIR_FILES)

fclean: clean
	@rm --verbose $(NAME) || true

re: fclean all

tests_run:
	@echo -e "$(YEL)\tTesting generic linked list$(NC)"
	@gcc tests/genlinked_t.c \
		$(SRC_DIR_FILES) \
		-o .linked.out $(CFLAGS) $(INCLUDES) -g
	@valgrind ./.linked.out
	@rm ./.linked.out
	@echo -e "$(GRN)\tlinked list success !$(NC)"
	@echo -e "$(YEL)\tTesting linked list handler$(NC)"
	@gcc tests/handle_genlinked_t.c \
		$(SRC_DIR_FILES) \
		-o .linkedhandle.out $(CFLAGS) $(INCLUDES) -Wno-unused-parameter -g
	@valgrind ./.linkedhandle.out
	@rm ./.linkedhandle.out
	@echo -e "$(GRN)\tlinked list handler success !$(NC)"

.Phony: all clean fclean re
