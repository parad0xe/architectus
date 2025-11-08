TESTS = $(wildcard $(TESTS_DIR)*.c)
BINARIES = $(TESTS:$(TESTS_DIR)%.c=%.ev)

.PHONY: .FORCE all clean r rb

# -j has issues on recursive makefiles
#MAKE_FLAGS = -j $$(nprocs) 
MAKE_FLAGS =

SHELL := /bin/bash
CC = cc
CFLAGS = -Wall -Wextra -Werror -L ../ -lft
TESTS_DIR = tests/
LIB = ../libft.a

all: $(BINARIES)

# run make {name of function with '.ev' to test}
%.ev: $(TESTS_DIR)%.c $(LIB) .FORCE
	$(CC) $(CFLAGS) $< $(LIB) -o $@
	./$@

# rebuild lib
$(LIB):
	$(MAKE) fclean -C ../
	$(MAKE) $(MAKE_FLAGS) -C ../
	$(MAKE) bonus $(MAKE_FLAGS) -C ../

clean:
	rm -f *.ev

rb:
	@$(MAKE) MAKE_FLAGS="bonus $(MAKE_FLAGS)" r BONUS=1 --no-print-directory

# relink
r:
	@read -n 1 -s -p "Double make: (press any key to continue)"
	@echo
	@make $(MAKE_FLAGS) fclean -C ../ --no-print-directory
	@make $(MAKE_FLAGS) -C ../ --no-print-directory
	@make $(MAKE_FLAGS) -C ../ --no-print-directory
	@read -n 1 -s -p "C files relink: (press any key to continue)"
	@echo
	@if [ "$$BONUS" = "1" ]; then touch ../ft_lstadd_back_bonus.c; \
	else touch ../ft_strlen.c; fi
	@make $(MAKE_FLAGS) -C ../ --no-print-directory
	@read -n 1 -s -p "Headers relink: (press any key to continue)"
	@echo
	@touch ../libft.h
	@make $(MAKE_FLAGS) -C ../ --no-print-directory
	@make $(MAKE_FLAGS) fclean -C ../ --no-print-directory
