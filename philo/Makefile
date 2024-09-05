all: philo

NAME = philo
CFLAGS = -Wall -Wextra -Werror -g -pthread
PROJECTFILES = philo.c utils.c actions.c init.c single_philo.c utils2.c utils3.c

philo: ${PROJECTFILES}
	cc ${PROJECTFILES} ${CFLAGS} -o philo

clean:
	rm -rf ./philo

fclean:
	rm -rf ./philo

re:
	make fclean
	make all