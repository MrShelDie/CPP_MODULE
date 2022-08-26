SRC = 						\
	source/Contact.cpp 		\
	source/PhoneBook.cpp	\
	source/Executor.cpp		\
	source/main.cpp
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

NAME = phoneBook

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
CPPFLAGS = -MMD -I./include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

clean:
	$(RM) $(OBJ) $(DEP)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)