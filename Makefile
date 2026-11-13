re: fclean all

all: exe

exe: mastermind
	./mastermind -c 1234 -t -1

mastermind: mastermind.c
	@gcc mastermind.c into.c generation.c resetArray.c -Wall -Wextra -Werror -o mastermind

fclean:
	@rm -f mastermind

.PHONY: fclean