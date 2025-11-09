/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:16:54 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/10 00:27:26 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void	*memset(void *s, int c, size_t n);

static char		*ft_res, *res;
static size_t	n;
static int		c;

void test1(void)
{
    set_description("Basic set"); n = 6; c = 'A';
    ft_res = malloc(n); res = malloc(n);
    ft_memset(ft_res, 0, n); memset(res, 0, n);
    ft_res = ft_memset(ft_res, c, n); res = memset(res, c, n);
    check_is_equal(STR, ft_res, res);
    free(ft_res); free(res);
}

void test2(void)
{
    set_description("Overwrite existing data"); n = 5; c = 0;
    ft_res = malloc(n); res = malloc(n);
    memcpy(ft_res, "Hello", n); memcpy(res, "Hello", n);
    ft_res = ft_memset(ft_res, c, n); res = memset(res, c, n);
    check_is_equal(STR, ft_res, res);
    free(ft_res); free(res);
}

void test3(void)
{
    (void)ft_memset(NULL, 'A', 5);
}

int main(void)
{
    handle(&test1);
    handle(&test2);
    handle_sigsegv("NULL pointer [segfault]", &test3, SEGFAULT);
    return (0);
}
