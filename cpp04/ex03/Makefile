NAME = Materia
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRCS = AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)
OBJS_NO_DEBUG = $(SRCS:.cpp=.no_debug.o)

HEADERS = AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) created successfully!"

no_debug: CXXFLAGS += -D DEBUG_CONSTRUCTORS=0
no_debug: $(NAME)_no_debug

$(NAME)_no_debug: $(OBJS_NO_DEBUG)
	@echo "Linking $(NAME) (no debug)..."
	@$(CXX) $(CXXFLAGS) $(OBJS_NO_DEBUG) -o $(NAME)
	@echo "$(NAME) created successfully (without debug messages)!"

%.o: %.cpp $(HEADERS)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

%.no_debug.o: %.cpp $(HEADERS)
	@echo "Compiling $< (no debug)..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Removing object files..."
	@rm -f $(OBJS) $(OBJS_NO_DEBUG)

fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all no_debug clean fclean re