NAME	:= a.out
SRC_DIR := .
INC_DIR := ./
OBJ_DIR := ./objs
DEPS 	:= $(OBJS:.o=.d)
CC		:= c++
FLAGS	:= -Wall -Wextra -Werror -std=c++98 -MMD -MP

$(NAME): $(OBJ_DIR) $(OBJ_DIR)/main.o
	$(CC) $(FLAGS) $(OBJ_DIR)/main.o -o $@

$(OBJ_DIR)/main.o: main.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re