SRC = main.cpp	
OBJ = $(SRC:.cpp=.o)

NAME = a.out
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $@

clean:
	$(RM) $(OBJ) 

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
