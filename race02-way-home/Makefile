NAME = way_home

SRCS = src/mx_strlen.c src/mx_printchar.c src/mx_printint.c src/mx_isdigit.c src/mx_isspace.c src/mx_printstr.c src/mx_strcmp.c  src/mx_strdel.c  src/mx_strncpy.c src/mx_strnew.c src/mx_strtrim.c src/mx_printerr.c src/mx_atoi.c src/int_matrix.c src/file_to_str.c src/max_way.c src/road.c src/main.c src/imatrix.c
SRCSOB =  mx_printchar.c mx_printint.c mx_isdigit.c mx_isspace.c   mx_printstr.c mx_strcmp.c mx_strdel.c mx_strlen.c mx_strncpy.c mx_strnew.c mx_strtrim.c mx_printerr.c mx_atoi.c int_matrix.c file_to_str.c max_way.c road.c main.c imatrix.c

INC = inc/header.h
INCOB = header.h

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean
install:
	@cp $(SRCS) .
	@cp $(INC) .
	@clang $(CFLAGS) -o $(NAME) $(SRCSOB) -I $(INCOB)
uninstall: clean
	@rm -rf $(NAME)
clean:
	@rm -rf $(INCOB)
	@rm -rf $(SRCSOB)
reinstall: uninstall clean all
