/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:24:25 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/10 10:16:46 by ldecavel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

char *ft_strdup(const char *s1);

static char			*ft_res, *res;
static const char	*s1;

void test1(void)
{
    set_description("Basic string");
    s1 = "Hello world";
    ft_res = ft_strdup(s1); res = strdup(s1);
    check_is_equal(STR, ft_res, res);
    free(ft_res); free(res);
}

void test2(void)
{
    set_description("Empty string");
    s1 = "";
    ft_res = ft_strdup(s1); res = strdup(s1);
    check_is_equal(STR, ft_res, res);
    free(ft_res); free(res);
}

void test3(void)
{
    set_description("Special characters");
    s1 = "abcdéf";
    ft_res = ft_strdup(s1); res = strdup(s1);
    check_is_equal(STR, ft_res, res);
    free(ft_res); free(res);
}

void test4(void)
{
    (void)ft_strdup(NULL);
}

int main(void)
{
    handle(&test1);
    handle(&test2);
    handle(&test3);
    handle_sigsegv("NULL pointer [segfault]", &test4, SEGFAULT);
    return (0);
}
