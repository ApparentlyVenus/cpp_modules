
NAME = abstractAnimal

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98


SRCS = Brain.cpp AAnimal.cpp Cat.cpp Dog.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = Brain.hpp AAnimal.hpp Cat.hpp Dog.hpp

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