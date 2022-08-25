SRC = megaphone.cpp
NAME = megaphone

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

clean:

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
