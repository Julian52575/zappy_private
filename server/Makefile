##
## EPITECH PROJECT, 2024
## Zappy server
## File description:
## it still makes file
##
YEL=\033[1;33m
GRN='\033[0;32m'
RED='\033[0;31m'
NC=\033[0m # No Color


NAME = zappy_server

LIBS_DIR = libs/buffer_info \
	   libs/mygeneric_linked \
	   libs/myserver

SRC = src/main.c \
      src/loop.c

CFLAGS = -Wall -Wextra -O3 -iquote./includes \
	$(foreach current,$(LIBS_DIR), -iquote./$(current)/includes/) \
	-L./libs/mygeneric_linked -lgenericlinked \
	-L./libs/buffer_info -lmybufferinfo \
	-L./libs/myserver -lmyserver

all: shared
	@gcc -o $(NAME) $(SRC) $(CFLAGS)
	@echo -e "$(YEL)\t$(NAME) done!$(NC)"
	@echo -e "$(GRN) Run with export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./libs/buffer_info:./libs/myserver$(NC)"

shared:
	$(foreach current,$(LIBS_DIR), make -C $(current);)

clean:
	$(foreach current,$(LIBS_DIR), make clean -C $(current);)

fclean:
	$(foreach current,$(LIBS_DIR), make fclean -C $(current);)
	@rm ${NAME} || true

tests_run:
	$(foreach current,$(LIBS_DIR), make tests_run -C $(current) | grep "success";)

re: fclean all

.Phony: all shared clean fclean tests_run re
