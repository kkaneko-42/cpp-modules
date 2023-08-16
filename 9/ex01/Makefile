NAME	:= RPN
SRCS	:= main.cpp RPN.cpp
SRC_DIR := ./srcs
OBJ_DIR := ./objs
OBJS	:= $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEPS 	:= $(OBJS:.o=.d)
CC		:= c++
FLAGS	:= -std=c++98 -MMD -MP #-Wall -Wextra -Werror 

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	./test.sh

-include $(DEPS)

.PHONY: all clean fclean re test