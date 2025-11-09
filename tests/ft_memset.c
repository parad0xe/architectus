/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:16:54 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 19:18:42 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void *memset(void *s, int c, size_t n);

int main(void)
{
    char *ft_res, *res;
    int status;
    pid_t pid;
    size_t n;
    int c;

    // test 1
    set_description("Basic set"); n = 6; c = 'A'; 
    ft_res = malloc(n); res = malloc(n);
    ft_memset(ft_res, 0, n); memset(res, 0, n);
    ft_res = ft_memset(ft_res, c, n); res = memset(res, c, n);
    check_is_equal(STR, ft_res, res);
    free(ft_res); free(res);

    // test 3
    set_description("Overwrite existing data"); n = 5; c = 0; 
    ft_res = malloc(n); res = malloc(n);
    memcpy(ft_res, "Hello", n); memcpy(res, "Hello", n);
    ft_res = ft_memset(ft_res, c, n); res = memset(res, c, n);
    check_is_equal(STR, ft_res, res);
    free(ft_res); free(res);

    // test 4
    set_description("NULL pointer [segfault]");
    pid = fork();
    if (pid == 0)
    {
        (void)ft_memset(NULL, 'A', 5);
        exit(0);
    }
    waitpid(pid, &status, 0);
    if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
        check_is_equal(STR, "Segfault", "Segfault");
    else
        check_is_equal(STR, "No Segfault", "Segfault");

    return (0);
}
