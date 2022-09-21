NAME	:= convert
SRC_DIR	:= src
SRCS	:= main.cpp Converter.cpp type_specify.cpp toFloat.cpp toDouble.cpp
INC_DIR := ./include
OBJ_DIR := ./objs
OBJS	:= $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEPS 	:= $(OBJS:.o=.d)
VPATH	:= ./src
CC		:= c++
FLAGS	:= -Wall -Wextra -Werror -std=c++98 -MMD -MP

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR):
	mkdir -p $@

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@ -I $(INC_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re