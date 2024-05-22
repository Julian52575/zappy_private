#!/bin/bash
GRN='\033[0;32m'
RED='\033[0;31m'
YEL='\033[1;33m'
NC='\033[0m' # No Color
FLAGS='-Wall -Wextra -iquote./includes/ -Wno-unused-variable'
LOG='tests/.log'
NAME='cpp de con'
SPFILE='hpp de con'
CMDFILE='src/myconnexion_add_in_reply_buffer.c src/myconnexion_is_logged_in.c src/myconnexion_change_path.c src/myconnexion_parent_path.c'
GOOD='🥵'
BAD='💀'
LOG='.log.log'

@echo -e "${YEL} Shift buffer ${NC}"
SPFILE='src/myconnexion_init.c src/myconnexion_update_end_of_cmd_index.c src/myconnexion_is_command_full.c src/myconnexion_get_last_byte.c src/myconnexion_is_buffer_full.c src/myconnexion_dump_buffer.c src/myconnexion_clear_buffer.c src/myconnexion_shift_buffer.c src/myconnexion_destroy.c'
NAME='shift'
gcc ${SPFILE} ${CMDFILE} tests/shift_buffer_t.c -o ".${NAME}" ${FLAGS}
./.${NAME}
if [ $? -eq 0 ]
then
    @echo -ne "${GRN} [${GOOD}]" >> ${LOG}
else
    @echo -ne "${RED} [${BAD}]" >> ${LOG}
fi
@echo -e " ${NAME} ${NC}" >> ${LOG}
rm ".${NAME}" || true
