#!/bin/bash
#   Note:   This script requires the following packages:
#   graphviz
#   doxygen

DOXYFILE_DEFAULT="DOXYFILE_ENCODING = UTF-8
PROJECT_NAME = \"Zappy\"
HAVE_DOT = YES
EXTRACT_ALL = YES
CLASS_GRAPH = YES
FILE_PATTERNS = *.c *.h
INPUT = server/
RECURSIVE = YES"


test -d doxygen
if [ $? != 0 ]
then
    test -f doxygen
    if [ $? == 0 ]
    then
        rm -rf doxygen
    fi
    mkdir doxygen
fi

test -f doxygen/Doxyfile
if [ $? != 0 ]
then
    echo "${DOXYFILE_DEFAULT}" > doxygen/Doxyfile
fi

doxygen ./doxygen/Doxyfile
if [ $? != 0 ]
then
    echo "An error occured when generating the documentation..."
    exit 84
fi
test -d doxygen/html/ && rm -r doxygen/html/
test -d doxygen/latex/ && rm -r doxygen/latex/
mv -f html/ doxygen/
mv -f latex/ doxygen/
echo "Succesfuly generated the documentation !"
echo "Look at index.html or class.png !"
firefox doxygen/html/index.html
if [ $? != 0 ]
then
    opera doxygen/html/index.html
fi
exit 0
