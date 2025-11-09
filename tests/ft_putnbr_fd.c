/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:31:45 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 19:32:03 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>

void ft_putnbr_fd(int n, int fd);

int main(void)
{
    int pipefd[2];
    char buf[50];

    // test 1
    set_description("Positive number"); 
    if (pipe(pipefd) == -1)
        exit(1);
    ft_putnbr_fd(12345, pipefd[1]);
    int r = read(pipefd[0], buf, 5);
    buf[r] = '\0';
    check_is_equal(STR, buf, "12345");
    close(pipefd[0]); close(pipefd[1]);

    // test 2
    set_description("Zero"); 
    if (pipe(pipefd) == -1)
        exit(1);
    ft_putnbr_fd(0, pipefd[1]);
    r = read(pipefd[0], buf, 1);
    buf[r] = '\0';
    check_is_equal(STR, buf, "0");
    close(pipefd[0]); close(pipefd[1]);

    // test 3
    set_description("Negative number"); 
    if (pipe(pipefd) == -1)
        exit(1);
    ft_putnbr_fd(-6789, pipefd[1]);
    r = read(pipefd[0], buf, 5);
    buf[r] = '\0';
    check_is_equal(STR, buf, "-6789");
    close(pipefd[0]); close(pipefd[1]);

    // test 4
    set_description("INT_MIN"); 
    if (pipe(pipefd) == -1)
        exit(1);
    ft_putnbr_fd(-2147483648, pipefd[1]);
    r = read(pipefd[0], buf, 11);
    buf[r] = '\0';
    check_is_equal(STR, buf, "-2147483648");
    close(pipefd[0]); close(pipefd[1]);

    // test 5
    set_description("INT_MAX"); 
    if (pipe(pipefd) == -1)
        exit(1);
    ft_putnbr_fd(2147483647, pipefd[1]);
    r = read(pipefd[0], buf, 10);
    buf[r] = '\0';
    check_is_equal(STR, buf, "2147483647");
    close(pipefd[0]); close(pipefd[1]);

    return (0);
}
