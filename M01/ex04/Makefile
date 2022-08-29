SRC = main.cpp

NAME = fileReplace

CXX = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CFLAGS) -o $@ $<

clean:

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re