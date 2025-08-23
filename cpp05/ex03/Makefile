
NAME = mesh_3am_le2e_internship

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98


SRCS = Intern.cpp AForm.cpp Bureaucrat.cpp main.cpp ShrubberyCreationForm.cpp \
		PresidentialPardonForm.cpp RobotomyRequestForm.cpp 

OBJS = $(SRCS:.cpp=.o)

HEADERS = Intern.hpp Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp \
			PresidentialPardonForm.hpp RobotomyRequestForm.hpp

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) created successfully!"

%.o: %.cpp $(HEADERS)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Removing object files..."
	@rm -f $(OBJS)

fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re