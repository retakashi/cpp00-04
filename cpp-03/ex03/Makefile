NAME = diamondtrap
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98  -Wshadow
SRCS =  main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp DiamondTrap.cpp
OBJS_DIR = objs
VPATH = ./pre_exercise
OBJS = ${addprefix $(OBJS_DIR)/,$(SRCS:.cpp=.o)}
RM = rm -f
.DEFAULT_GOAL :=$(NAME)
all: $(NAME)
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $^ -o $@
$(OBJS_DIR):
	mkdir $(OBJS_DIR)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re