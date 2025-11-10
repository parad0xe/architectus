/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:50:59 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/10 10:15:23 by ldecavel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

size_t strlcpy(char *dest, const char *src, size_t size);

static char     *ft_dest, *dest, *src;
static size_t   ft_res, res, size;

void test1(void)
{
    set_description("Test regular string");
    ft_dest = malloc(10); dest = malloc(10);
    src = "Hello world"; size = 5;
    ft_res = ft_strlcpy(ft_dest, src, size);
    res = strlcpy(dest, src, size);
    check_is_equal(SIZE_T, ft_res, res);
    free(ft_dest); free(dest);
}

void test2(void)
{
    ft_dest = ""; src = "Hello world"; size = 5;
    (void)ft_strlcpy(ft_dest, src, size);
}

void test3(void)
{
    set_description("Size 0");
    ft_dest = malloc(10); dest = malloc(10);
    src = "Hello world"; size = 0;
    ft_res = ft_strlcpy(ft_dest, src, size);
    res = strlcpy(dest, src, size);
    check_is_equal(SIZE_T, ft_res, res);
    free(ft_dest); free(dest);
}

void test4(void)
{
    set_description("Empty src");
    ft_dest = malloc(10); dest = malloc(10);
    src = ""; size = 0;
    ft_res = ft_strlcpy(ft_dest, src, size);
    res = strlcpy(dest, src, size);
    check_is_equal(SIZE_T, ft_res, res);
    free(ft_dest); free(dest);
}

void test5(void)
{
    set_description("Size 1");
    ft_dest = malloc(10); dest = malloc(10);
    src = "Hello world"; size = 1;
    ft_res = ft_strlcpy(ft_dest, src, size);
    res = strlcpy(dest, src, size);
    check_is_equal(SIZE_T, ft_res, res);
    free(ft_dest); free(dest);
}

void test6(void)
{
    ft_dest = NULL; src = "Hello world"; size = 5;
    (void)ft_strlcpy(ft_dest, src, size);
}

void test7(void)
{
    ft_dest = malloc(8); src = NULL; size = 5;
    (void)ft_strlcpy(ft_dest, src, size);
}

int main(void)
{
    handle(&test1);
    handle_sigsegv("emtpy dst [segfault]", &test2, SEGFAULT);
    handle(&test3);
    handle(&test4);
    handle(&test5);
    handle_sigsegv("NULL dst [segfault]", &test6, SEGFAULT);
    handle_sigsegv("NULL src [segfault]", &test7, SEGFAULT);
    return (0);
}
