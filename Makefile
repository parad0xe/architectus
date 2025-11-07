TESTS_DIR = tests/

CFLAGS = -Wall -Wextra -Werror
CC = cc
MAKE_FLAGS = -j $$(nproc)

# run make {name of function with '.c' to test}
%.c: ../libft.a
	$(CC) $(CFLAGS) $(TESTS_DIR)$@ ../libft.a -o $(@:.c=)
	./$(@:.c=)

../libft.a:
	make $(MAKE_FLAGS) -C ../

# relink
r:
	make $(MAKE_FLAGS) fclean -C ../
	make $(MAKE_FLAGS) -C ../
	make $(MAKE_FLAGS) -C ../
	touch ../ft_strlen.c
	make $(MAKE_FLAGS) -C ../
	touch ../libft.h
	make $(MAKE_FLAGS) -C ../
	make $(MAKE_FLAGS) fclean -C ../

# relink bonus
rb:
	make $(MAKE_FLAGS) fclean -C ../
	make bonus $(MAKE_FLAGS) -C ../
	make bonus $(MAKE_FLAGS) -C ../
	touch ../ft_lstadd_back.c
	make bonus $(MAKE_FLAGS) -C ../
	touch ../libft.h
	make bonus $(MAKE_FLAGS) -C ../
	make $(MAKE_FLAGS) fclean -C ../
