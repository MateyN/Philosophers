SRCS		= philo_bonus.c operations_bonus.c philo_bonus_utils.c init_bonus.c utils.c
NAME		= philo_bonus
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -pthread

all:		$(NAME)
$(NAME):	$(SRCS)
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		re all fclean