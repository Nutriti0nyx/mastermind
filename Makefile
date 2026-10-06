re: all fclean

all: exe

exe: mastermind
	./mastermind -c 1234 -t 2

mastermind: mastermind.c
	@gcc mastermind.c into.c generation.c resetArray.c -Wall -Wextra -Werror -o mastermind

fclean:
	@rm -f mastermind

.PHONY: fclean