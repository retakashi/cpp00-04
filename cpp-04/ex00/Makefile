NAME = animal
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -fsanitize=address -std=c++98
SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
DEPFILES = $(OBJS:%.o=%.d)
OBJS = ${addprefix $(OBJS_DIR)/,$(SRCS:.cpp=.o)}
OBJS_DIR = objs
RM = rm -f
.DEFAULT_GOAL :=$(NAME)
all: $(NAME)
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c -MMD -MP $< -I include -o $@
$(OBJS_DIR):
	mkdir $(OBJS_DIR)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
-include $(DEPFILES)
