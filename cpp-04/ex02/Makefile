NAME = brain
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -pedantic-errors -fsanitize=address -std=c++98
SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp
OBJS = ${addprefix $(OBJS_DIR)/,$(SRCS:.cpp=.o)}
OBJS_DIR = objs
INCLUDE_DIR = ./include
DEPFILES = $(OBJS:%.o=%.d)
RM = rm -f
.DEFAULT_GOAL :=$(NAME)
all: $(NAME)
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c -MMD -MP $< -I $(INCLUDE_DIR) -o $@
$(OBJS_DIR):
	mkdir $(OBJS_DIR)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
-include $(DEPFILES)
