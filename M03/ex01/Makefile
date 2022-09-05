SRC = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

NAME = a.out

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
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