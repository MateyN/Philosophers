SRCS		= philo.c philo_operations.c
NAME		= philo
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all:		$(NAME)
$(NAME):	$(SRCS)
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: re all fclean