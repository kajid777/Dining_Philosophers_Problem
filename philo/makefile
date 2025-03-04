CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	   create_philos.c \
	   settings.c \
	   take_a_fork.c \
	   threads.c \
	   eat.c \
	   sleep.c \
	   think.c \
	   gettimeofday.c \
	   init_ctx.c \
	   initialize_philosophers.c \
	   monitor.c \
	   print.c \
	   destroy_mutexes.c \
	   clean.c \
	   atoi.c \
	   errors/malloc_fail.c \

OBJS = $(SRCS:.c=.o)

NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
