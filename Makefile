SRCS		= philo.c philo_operations.c philo_utils.c philo.c utils.c threads.c
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