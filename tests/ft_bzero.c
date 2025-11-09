/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:19:12 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 19:19:53 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void ft_bzero(void *s, size_t n);

int main(void)
{
    char *ft_buf, *res;
    int status;
    pid_t pid;
    size_t n;

    // test 1
    set_description("Basic zero"); n = 6; 
    ft_buf = malloc(n); res = malloc(n);
    memcpy(ft_buf, "Hello!", n); memcpy(res, "Hello!", n);
    ft_bzero(ft_buf, n); bzero(res, n);
    check_is_equal(STR, ft_buf, res);
    free(ft_buf); free(res);

    // test 3
    set_description("Partial zero"); n = 3; 
    ft_buf = malloc(5); res = malloc(5);
    memcpy(ft_buf, "Hello", 5); memcpy(res, "Hello", 5);
    ft_bzero(ft_buf, n); bzero(res, n);
    check_is_equal(STR, ft_buf, res);
    free(ft_buf); free(res);

    // test 4
    set_description("NULL pointer [segfault]");
    pid = fork();
    if (pid == 0)
    {
        ft_bzero(NULL, 5);
        exit(0);
    }
    waitpid(pid, &status, 0);
    if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
        check_is_equal(STR, "Segfault", "Segfault");
    else
        check_is_equal(STR, "No Segfault", "Segfault");

    return (0);
}
