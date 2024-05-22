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
echo -n "" > ${LOG}


# shift buffer
./tests/shift_buffer_t.sh

# overwrite first command
echo -e "${YEL} Overwrite first command ${NC}"
SPFILE='src/myconnexion_init.c src/myconnexion_overwrite_first_command.c src/myconnexion_update_end_of_cmd_index.c src/myconnexion_is_command_full.c src/myconnexion_get_last_byte.c src/myconnexion_is_buffer_full.c src/myconnexion_dump_buffer.c src/myconnexion_clear_buffer.c src/myconnexion_shift_buffer.c'
NAME='overwritefirst'
gcc ${SPFILE} ${CMDFILE} tests/overwrite_first_buffer_t.c -o ".${NAME}" ${FLAGS}
valgrind ./.${NAME}
if [ $? -eq 0 ]
then
    echo -ne "${GRN} [${GOOD}]" >> ${LOG}
else
    echo -ne "${RED} [${BAD}]" >> ${LOG}
fi
echo -e " ${NAME} ${NC}" >> ${LOG}
rm ".${NAME}" || true

# add in reply buffer
echo -e "${YEL} Add in reply buffer ${NC}"
SPFILE='src/myconnexion_init.c src/myconnexion_update_end_of_cmd_index.c src/myconnexion_dump_buffer.c src/myconnexion_overwrite_first_command.c src/myconnexion_clear_buffer.c src/myconnexion_shift_buffer.c'
NAME='addreply'
gcc ${SPFILE} ${CMDFILE} tests/add_in_reply_buffer_t.c -o ".${NAME}" ${FLAGS}
valgrind ./.${NAME}
if [ $? -eq 0 ]
then
    echo -ne "${GRN} [${GOOD}]" >> ${LOG}
else
    echo -ne "${RED} [${BAD}]" >> ${LOG}
fi
echo -e " ${NAME} ${NC}" >> ${LOG}
rm ".${NAME}" || true

# cut command
#@echo -e "${YEL} Cut command ${NC}"
#SPFILE='src/myconnexion_init.c src/myconnexion_update_end_of_cmd_index.c src/myconnexion_move_buffer.c src/myconnexion_dump_buffer.c'
#NAME='cutcommand'
#gcc ${SPFILE} ${CMDFILE} tests/cut_command_t.c -o ".${NAME}" ${FLAGS}
#./.${NAME}
#if [ $? -eq 0 ]
#then
#    @echo -ne "${GRN} [${GOOD}]" >> ${LOG}
#else
#    @echo -ne "${RED} [${BAD}]" >> ${LOG}
#fi
#@echo -e " ${NAME} ${NC}" >> ${LOG}
#rm ".${NAME}" || true

# remove from list command
echo -e "${YEL} Remove From List ${NC}"
SPFILE='src/myconnexion_init.c src/myconnexion_remove_from_list.c src/myconnexion_link.c src/myconnexion_destroy.c src/myconnexion_update_end_of_cmd_index.c'
NAME='removeFromList'
gcc ${SPFILE} ${CMDFILE} tests/remove_from_list_t.c -o ".${NAME}" ${FLAGS}
valgrind ./.${NAME}
if [ $? -eq 0 ]
then
    echo -ne "${GRN} [${GOOD}]" >> ${LOG}
else
    echo -ne "${RED} [${BAD}]" >> ${LOG}
fi
echo -e " ${NAME} ${NC}" >> ${LOG}
rm ".${NAME}" || true

echo -e "${YEL} Result: ${NC}"
cat ${LOG}
rm ${LOG} || true


#RESULTS
echo -e "${YEL} Result: ${NC}"
cat ${LOG}
rm ${LOG} || true
