/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:45:25 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/10 01:03:18 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

char *strchr(const char *s, int c);

static char			*ft_res, *res;
static const char	*s;

void test1(void)
{
    set_description("Basic match");
    s = "Hello world";
    ft_res = ft_strchr(s, 'o'); res = strchr(s, 'o');
    check_is_equal(STR, ft_res, res);
}

void test2(void)
{
    set_description("No match");
    s = "abcdef";
    ft_res = ft_strchr(s, 'z'); res = strchr(s, 'z');
    check_is_equal(STR, ft_res, res);
}

void test3(void)
{
    set_description("Match with first character");
    s = "abc";
    ft_res = ft_strchr(s, 'a'); res = strchr(s, 'a');
    check_is_equal(STR, ft_res, res);
}

void test4(void)
{
    set_description("Match with last character");
    s = "abc";
    ft_res = ft_strchr(s, 'c'); res = strchr(s, 'c');
    check_is_equal(STR, ft_res, res);
}

void test5(void)
{
    set_description("Search for '\\0'");
    s = "abc";
    ft_res = ft_strchr(s, '\0'); res = strchr(s, '\0');
    check_is_equal(STR, ft_res, res);
}

void test6(void)
{
    set_description("Empty string");
    s = "";
    ft_res = ft_strchr(s, 'a'); res = strchr(s, 'a');
    check_is_equal(STR, ft_res, res);
}

void test7(void)
{
    (void)ft_strchr(NULL, 'a');
}

int main(void)
{
    handle(&test1);
    handle(&test2);
    handle(&test3);
    handle(&test4);
    handle(&test5);
    handle(&test6);
    handle_sigsegv("NULL pointer [segfault]", &test7, SEGFAULT);
    return (0);
}
