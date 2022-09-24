SRC =							\
main.cpp						\
Bureaucrat.cpp					\
AForm.cpp						\
PresidentialPardonForm.cpp		\
RobotomyRequestForm.cpp			\
ShrubberyCreationForm.cpp

OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

NAME = a.out
OUTFILE = SomeShrubbery_shrubbery

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
CPPFLAGS = -MMD -I./inc

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $@

clean:
	$(RM) $(OBJ) $(DEP) $(OUTFILE)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)
