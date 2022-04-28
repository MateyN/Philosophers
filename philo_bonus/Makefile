SRCS		= philo_bonus.c operations_bonus.c philo_bonus_utils.c init_bonus.c utils_bonus.c
NAME		= philo_bonus
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -pthread

all:		$(NAME)
$(NAME):	$(SRCS)
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
			@echo "\033[92mphilo_bonus SUCCESSFULLY CREATED\033[0m"

clean:

fclean:		clean
			rm -f $(NAME)
			@echo "\033[91mphilo_bonus SUCCESSFULLY DELETED\033[0m"

re:			fclean all

.PHONY:		re all fclean