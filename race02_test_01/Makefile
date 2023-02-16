CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

SRC = src/main.c \
      src/mx_atoi.c \
      src/mx_find_path.c \
      src/mx_parse_maze.c \
      src/mx_print_error.c \
      src/mx_print_maze.c \
      src/mx_print_path.c \
      src/mx_print_route.c \
      src/mx_print_usage.c \
      src/mx_strsplit.c \
      src/mx_isspace.c \
      src/mx_isdigit.c

OBJ = $(SRC:%.c=%.o)

INC = -I inc

LIB = libmx/libmx.a

all: way_home

way_home: $(OBJ)
	@make -C libmx
	@$(CC) $(CFLAGS) $(INC) $^ $(LIB) -o $@

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make -C libmx clean
	@rm -rf $(OBJ)

uninstall: clean
	@make -C libmx uninstall
	@rm -rf way_home

reinstall: uninstall all

