NAME	:= a.out
SRC_DIR := .
INC_DIR := ./
OBJ_DIR := ./objs
DEPS 	:= $(OBJS:.o=.d)
CXX		:= c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98 -MMD -MP -fsanitize=undefined -g3

$(NAME): $(OBJ_DIR) $(OBJ_DIR)/main.o
	$(CXX) $(CXXFLAGS) $(OBJ_DIR)/main.o -o $@

$(OBJ_DIR)/main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

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