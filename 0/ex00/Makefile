NAME	:= megaphone
SRCS	:= megaphone.cpp
OBJS	:= $(SRCS:.cpp=.o)
CC		:= c++
FLAGS	:= -Wall -Wextra -Werror
TEST1	:= "shhhhh... I think the students are asleep..."
TEST2	:= Damnit " ! " "Sorry students, I thought this thing was off."

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

.cpp.o:
	$(CC) $(FLAGS) -c $^

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	./$(NAME) $(TEST1)
	./$(NAME) $(TEST2)
	./$(NAME)

.PHONY: all clean fclean re test