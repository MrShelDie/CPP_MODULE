SRC = main.cpp  Zombie.cpp  zombieHorde.cpp
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

NAME = zombieHorde
CXX = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
CPPFLAGS = -MMD

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $@

clean:
	$(RM) $(OBJ) $(DEP)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)