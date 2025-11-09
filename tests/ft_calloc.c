/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:45:12 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 18:49:12 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void *calloc(size_t count, size_t size);

static int	buffer_is_zero(void *buf, size_t len)
{
	for (size_t i = 0; i < len; i++)
		if (((unsigned char *)buf)[i] != 0)
			return (0);
	return (1);
}

int	main(void)
{
	void	*ft_res, *res;
	size_t	len;

	// test 1
	set_description("Basic allocation"); len = 5 * sizeof(int); 
	ft_res = ft_calloc(5, sizeof(int)); res = calloc(5, sizeof(int));
	check_is_equal(INT, buffer_is_zero(ft_res, len), buffer_is_zero(res, len));
	free(ft_res); free(res);

	// test 2
	set_description("Zero bytes allocation"); len = 0; 
	ft_res = ft_calloc(0, sizeof(int)); res = calloc(0, sizeof(int));
	check_is_equal(STR, ft_res == NULL ? "NULL" : "Not NULL", res == NULL ? "NULL" : "Not NULL");
	free(ft_res); free(res);

	// test 3
	set_description("Large allocation"); len = 100 * sizeof(char); 
	ft_res = ft_calloc(100, sizeof(char)); res = calloc(100, sizeof(char));
	check_is_equal(INT, buffer_is_zero(ft_res, len), buffer_is_zero(res, len));
	free(ft_res); free(res);

	return (0);
}
