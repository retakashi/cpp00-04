NAME = account
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = tests.cpp Account.cpp
OBJS = ${addprefix $(OBJS_DIR)/,$(SRCS:.cpp=.o)}
OBJS_DIR = objs
RM = rm -f
.DEFAULT_GOAL :=$(NAME)
all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
$(OBJS_DIR)/%.o: %.cpp $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re