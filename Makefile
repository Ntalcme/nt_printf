########################
## ARGUMENTS
NAME        = libntprintf.a
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar
ARFLAGS     = rcs
RM 			= rm -rf

########################
## SOURCES
SRC         = nt_printf.c
LIB_DIR     = ./libnt
CONV_DIR    = $(LIB_DIR)/conversion
FD_DIR      = $(LIB_DIR)/fd
STR_DIR     = $(LIB_DIR)/str_utils
SRCS        = $(SRC) $(wildcard $(CONV_DIR)/*.c) $(wildcard $(FD_DIR)/*.c) $(wildcard $(STR_DIR)/*.c)
OBJ_DIR     = obj
OBJS        = $(SRCS:%.c=$(OBJ_DIR)/%.o)

########################
## RULES

all: 				$(NAME)

$(NAME): 			$(OBJ_DIR) $(OBJS)
					$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: 	%.c | $(OBJ_DIR)
					mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					$(RM) $(OBJ_DIR)

fclean: 			clean
					$(RM) $(NAME)

re: 				fclean $(NAME)

.PHONY: 			all clean fclean re
