NAME=philo

CC=gcc

CLAGS=-Wall -Werror -Wextra

SRCS=src/all_your_life.c src/create_philo_treads.c src/create_philo.c src/data_init.c\
src/ft_already_dead.c src/get_time.c src/main.c src/mutex_create.c utls/ft_isdigit.c\
utls/ft_philo_atoi.c utls/ft_print.c utls/ft_strcmp.c

HDRS=inc/messages.h inc/philo.h

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HDRS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

re:
	make clean
	make

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: all re clean fclean
