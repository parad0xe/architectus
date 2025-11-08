# HOW TO USE :
# 'make' to test all functions at once
# 'make {function.ev}' to test a single function
# 'make libft.a' to rebuild the libft.a
# 'make clean' to delete .ev files
# 'make fclean' to delete libft.a and .ev files
# 'make rb' to test bonus relink
# 'make r' to test mandatory relink

.PHONY: .FORCE all clean r rb

SHELL := /bin/bash
CC = cc
CFLAGS = -Wall -Wextra -Werror -L ../ -lft
TESTS_DIR = tests/
BINARIES = $(TESTS:$(TESTS_DIR)%.c=%.ev)
LIB = ../libft.a

# 'make' to test all functions at once
all: $(BINARIES)

# 'make {function.ev}' to test a single function
%.ev: $(TESTS_DIR)%.c $(LIB) .FORCE
	@$(CC) $(CFLAGS) $< $(LIB) -o $@ 
	@./$@

$(LIB): libft.a

# 'make libft.a' to rebuild the libft.a
libft.a:
	@$(MAKE) fclean -C ../ --quiet
	@$(MAKE)  -C ../ > /dev/null 2>&1
	@$(MAKE) bonus -C ../ > /dev/null 2>&1 

# 'make clean' to delete .ev files
clean:
	@rm -f *.ev

# 'make fclean' to delete libft.a and .ev files
fclean: clean
	@$(MAKE) fclean -C ../ --quiet	

# 'make rb' to test bonus relink
rb:
	@$(MAKE) BONUS_FLAG="bonus $(BONUS_FLAG)" r BONUS=1 --no-print-directory

# 'make r' to test mandatory relink
r:
	@printf "\033[1;31mDouble make:\033[1;30m\n"
	@make $(BONUS_FLAG) fclean -C ../ --no-print-directory > /dev/null 2>&1 
	@make $(BONUS_FLAG) -C ../ --no-print-directory > /dev/null 2>&1 
	@make $(BONUS_FLAG) -C ../ --no-print-directory 
	@printf "\033[1;31mC files relink:\033[0;30m\n"
	@if [ "$$BONUS" = "1" ]; then touch ../ft_lstadd_back_bonus.c; \
	else touch ../ft_strlen.c; fi
	@make $(BONUS_FLAG) -C ../ --no-print-directory
	@printf "\033[1;31mHeaders relink:\033[0;30m\n"
	@touch ../libft.h
	@make $(BONUS_FLAG) -C ../ --no-print-directory
	@make $(BONUS_FLAG) fclean -C ../ --no-print-directory > /dev/null 2>&1 
