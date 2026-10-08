re: all fclean

all: exe

exe: mastermind
	./mastermind -c 0 -t 10

mastermind: mastermind.c
	@gcc mastermind.c into.c generation.c resetArray.c -Wall -Wextra -Werror -o mastermind

fclean:
	@rm -f mastermind

.PHONY: fclean