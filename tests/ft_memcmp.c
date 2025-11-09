/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:09:57 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/10 00:23:20 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int memcmp(const void *s1, const void *s2, size_t n);

int ft_memcmp(const void *s1, const void *s2, size_t n);

static int			ft_res, res;
static const char	*s1, *s2;
static size_t		n;

void test1(void)
{
    set_description("Equal buffers");
    s1 = "abcdef"; s2 = "abcdef"; n = 6;
    ft_res = ft_memcmp(s1, s2, n); res = memcmp(s1, s2, n);
    check_is_equal(INT, ft_res, res);
}

void test2(void)
{
    set_description("Different buffers");
    s1 = "abcdef"; s2 = "abcdez"; n = 6;
    ft_res = ft_memcmp(s1, s2, n); res = memcmp(s1, s2, n);
    check_is_equal(INT, ft_res, res);
}

void test3(void)
{
    set_description("Empty buffers");
    s1 = ""; s2 = ""; n = 0;
    ft_res = ft_memcmp(s1, s2, n); res = memcmp(s1, s2, n);
    check_is_equal(INT, ft_res, res);
}

void test4(void)
{
    set_description("Partial comparison");
    s1 = "abcdef"; s2 = "abcdez"; n = 3;
    ft_res = ft_memcmp(s1, s2, n); res = memcmp(s1, s2, n);
    check_is_equal(INT, ft_res, res);
}

void test5(void)
{
    (void)ft_memcmp(NULL, NULL, 5);
}

int main(void)
{
    handle(&test1);
    handle(&test2);
    handle(&test3);
    handle(&test4);
    handle_sigsegv("NULL pointers [segfault]", &test5, SEGFAULT);
    return (0);
}
