/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:32:18 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/09 12:00:17 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static char	*s_actual_name = "actual";
static char	*s_expected_name = "expected";
static char	*s_description = "";
static int	s_counter = 1;

static void	_print_line(char *title, uint64_t res, t_vtype type, char *color)
{
	printf("%s∎%s %-10s|%s", color, RESET, title, color);
	switch (type)
	{
		case SIZE_T:
			printf("%ld", (size_t)res);
			break ;
		case INT:
			printf("%d", (int)res);
			break ;
		case CHAR:
			printf("%c", (int)res);
			break ;
		default:
			printf("unknown type '%d'\n", type);
	}
	printf("%s|\n", RESET);
}

static void	_log_result(t_vtype type, _Bool ok, ...)
{
	uint64_t	a, b;

	char	*color = (ok) ? GREEN : RED;

	va_list	args;
	va_start(args, ok);
	a = (uint64_t)va_arg(args, uint64_t);
	b = (uint64_t)va_arg(args, uint64_t);
	va_end(args);
	display_description();
	_print_line(s_actual_name, a, type, color);
	_print_line(s_expected_name, b, type, color);
	s_counter++;
}

void	segfault_handler(int code)
{
	(void)code;
	display_description();
	printf("[%sSEGFAULT%s]\n", RED, RESET);
	exit(0);
}

void	display_description()
{
	printf("\n─ %d ─ %s ⸺\n", s_counter, s_description);
}

void	set_description(const char *description)
{
	s_description = (char *)description;
}

void	set_display(const char *actual_name, const char *expected_name)
{
	s_actual_name = (char *)actual_name;
	s_expected_name = (char *)expected_name;
}

void check_is_equal(t_vtype type, ...)
{
	uint64_t	a, b;
	int			ok;
	
	va_list	args;
	va_start(args, type);
	a = va_arg(args, uint64_t);
	b = va_arg(args, uint64_t);
	va_end(args);

	ok = 0;
	switch (type)
	{
		case SIZE_T:
		case INT:
		case CHAR:
			ok = (a == b);
			_log_result(type, ok, a, b);
			break ;
		case STR:
			ok = (!strcmp((char *)a, (char *)b));
			_log_result(type, ok, a, b);
			break ;
	}
}
