NAME = philo

SRCS		= src/all_your_life.c \
			src/create_philo_treads.c \
			src/create_philo.c \
			src/data_init.c \
			src/get_time.c src/main.c \
			src/mutex_create.c \
			src/ft_join_threads.c \
			src/checker.c \
			src/ft_usleep.c \
			src/philo_utils.c \

HDRS		= inc/messages.h \
			inc/philo.h \

OBJS		= $(SRCS:.c=.o)

OBJ_D		= $(SRCS:.c=.d)

CC			= cc

FLAGS		= -Wall -Werror -Wextra

RM			= rm -f

RED			= \x1b[31m
RESET		= \x1b[0m
BLUE		= \x1b[34m
GREEN		= \x1b[32m

$(NAME): $(OBJS) $(HDRS)
			@echo "$(RED)Generating object files $(RESET)"
			@echo "$(BLUE)Compiling and linking binary file $(RESET)"
			$(CC) $(OBJS) -o $(NAME)
			@echo "$(GREEN)IT IS FINALLY GENERATED (to use it run $(RED)./$(NAME)$(GREEN) with arguments) $(RESET)"

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

clean:
			rm -f $(OBJS)$(OBJ_D)

fclean: clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all re clean fclean