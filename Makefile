re: fclean all

all: exe

exe: mastermind
	./mastermind

mastermind: mastermind.c
	@gcc mastermind.c into.c generation.c -Wall -Wextra -Werror -o mastermind

fclean:
	@rm -f mastermind

.PHONY: fclean