SRC =							\
main.cpp						\
Bureaucrat.cpp					\
Form.cpp						\
PresidentialPardonForm.cpp		\
RobotomyRequestForm.cpp			\
ShrubberyCreationForm.cpp		\
Intern.cpp

OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

NAME = a.out
OUTFILE = Bender_shrubbery

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
CPPFLAGS = -MMD -I./inc

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $@

clean:
	$(RM) $(OBJ) $(DEP) 

fclean:	clean
	$(RM) $(NAME) $(OUTFILE)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)
