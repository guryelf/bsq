NAME = bsq

SRCS = bsq.c map.c utils.c find_square.c
OBJS = $(SRCS:.c=.o)

CC = cc -g
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
