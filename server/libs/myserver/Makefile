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

NAME 		=	libmyserver.so

SRC_FILES 	=	myserver_init.c \
			myserver_destroy.c \
				myserver_start.c \
				myserver_stop.c \
				myserver_add_connexion.c \
				myserver_listen_to_connexions.c \
				myserver_reply_to_connexions.c \
				myserver_update_max_fd.c \
				myserver_free_connexion_list.c \
				myserver_get_connexion.c \
				myserver_reload_connexions_fd.c \
				myserver_select_connexion.c \
				myserver_accept_new_connexion.c \
				myserver_ban_connexions.c \
				myserver_disconnect_connexions.c \
				myserver_debug_fd.c \
				myserver_set_data.c \
				myserver_exec_connexions_command.c \
				myserver_set_data.c \
				myserver_add_in_all_reply_buffer.c \
				myserver_add_to_connexion_type_buffer.c \
				myserver_set_welcome_message.c \
				myconnexion_init.c \
				myconnexion_is_logged_in.c \
				myconnexion_link.c \
				myconnexion_parse_buffer.c \
				myconnexion_read_packets.c \
				myconnexion_is_buffer_full.c \
				myconnexion_clear_buffer.c \
				myconnexion_dump_buffer.c \
				myconnexion_move_buffer.c \
				myconnexion_add_in_reply_buffer.c \
				myconnexion_update_end_of_cmd_index.c \
				myconnexion_write_reply_buffer.c \
				myconnexion_remove_from_list.c \
				myconnexion_destroy.c \
				myconnexion_overwrite_first_command.c \
				myconnexion_shift_buffer.c \
				myconnexion_set_data.c \
				myconnexion_get_buffer_info_array.c \
				myconnexion_set_type.c \
				myevent_handler_add_event.c \
				myevent_handler_destroy.c \
				myevent_handler_get_function.c \
				myevent_handler_init.c
SRC_DIR 	=	src

OBJ_FILES 	=	myserver_init.o \
			myserver_destroy.o \
				myserver_start.o \
				myserver_stop.o \
				myserver_add_connexion.o \
				myserver_listen_to_connexions.o \
				myserver_reply_to_connexions.o \
				myserver_update_max_fd.o \
				myserver_free_connexion_list.o \
				myserver_get_connexion.o \
				myserver_reload_connexions_fd.o \
				myserver_select_connexion.o \
				myserver_accept_new_connexion.o \
				myserver_ban_connexions.o \
				myserver_disconnect_connexions.o \
				myserver_debug_fd.o \
				myserver_set_data.o \
				myserver_exec_connexions_command.o \
				myserver_add_in_all_reply_buffer.o \
				myserver_add_to_connexion_type_buffer.o \
				myserver_set_welcome_message.o \
				myconnexion_init.o \
				myconnexion_is_logged_in.o \
				myconnexion_link.o \
				myconnexion_parse_buffer.o \
				myconnexion_read_packets.o \
				myconnexion_is_buffer_full.o \
				myconnexion_clear_buffer.o \
				myconnexion_dump_buffer.o \
				myconnexion_add_in_reply_buffer.o \
				myconnexion_update_end_of_cmd_index.o \
				myconnexion_write_reply_buffer.o \
				myconnexion_remove_from_list.o \
				myconnexion_destroy.o \
				myconnexion_overwrite_first_command.o \
				myconnexion_shift_buffer.o \
				myconnexion_set_data.o \
				myconnexion_set_type.o \
				myconnexion_get_buffer_info_array.o \
				myevent_handler_add_event.o \
				myevent_handler_destroy.o \
				myevent_handler_get_function.o \
				myevent_handler_init.o
OBJ_DIR 	= 	obj
OBJ_DIR_FILES	=	$(patsubst %,$(OBJ_DIR)/%,$(OBJ_FILES))

CFLAGS 		=	-Wall -Wextra -g -Wno-unused-variable \
					-L../buffer_info -lmybufferinfo
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

re: fclean all

tests_run:
	@valgrind ./tests/tests.sh
	@echo -e "$(YEL)\tTesting eventhandler$(NC)"
	@gcc tests/myevent_handler_t.c \
		src/myevent_handler* \
		-o .eventhandler $(CFLAGS) $(INCLUDES) -Wno-unused-parameter -g
	@valgrind ./.eventhandler
	@echo -e "$(GRN)\teventhandler success !$(NC)"
	@rm ./.eventhandler

.Phony: all clean fclean tests_run re
