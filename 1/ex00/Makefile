NAME	:= a.out
SRCS	:= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
SRC_DIR := .
INC_DIR := ./includes
OBJ_DIR := ./objs
OBJS	:= $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEPS 	:= $(OBJS:.o=.d)
CC		:= c++
FLAGS	:= -Wall -Wextra -Werror -std=c++98 -MMD -MP

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR)

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re