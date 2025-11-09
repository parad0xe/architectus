/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:10:38 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/10 00:22:12 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void *memchr(const void *s, int c, size_t n);

static unsigned char	*ft_res, *res;
static char				*s;
static int				c;
static size_t			n;

void test1(void)
{
    set_description("Basic match");
    s = "abcdef"; c = 'c'; n = 6;
    ft_res = ft_memchr(s, c, n); res = memchr(s, c, n);
    check_is_equal(STR, ft_res, res);
}

void test2(void)
{
    set_description("No match");
    s = "abcdef"; c = 'z'; n = 6;
    ft_res = ft_memchr(s, c, n); res = memchr(s, c, n);
    check_is_equal(STR, ft_res, res);
}

void test3(void)
{
    set_description("Match first byte");
    s = "abcdef"; c = 'a'; n = 6;
    ft_res = ft_memchr(s, c, n); res = memchr(s, c, n);
    check_is_equal(STR, ft_res, res);
}

void test4(void)
{
    set_description("Match last byte");
    s = "abcdef"; c = 'f'; n = 6;
    ft_res = ft_memchr(s, c, n); res = memchr(s, c, n);
    check_is_equal(STR, ft_res, res);
}

void test5(void)
{
    set_description("Zero length");
    s = "abcdef"; c = 'a'; n = 0;
    ft_res = ft_memchr(s, c, n); res = memchr(s, c, n);
    check_is_equal(STR, ft_res, res);
}

void test6(void)
{
    s = NULL;
    (void)ft_memchr(s, 'a', 5);
}

int main(void)
{
    handle(&test1);
    handle(&test2);
    handle(&test3);
    handle(&test4);
    handle(&test5);
    handle_sigsegv("NULL pointer [segfault]", &test6, SEGFAULT);
    return (0);
}
