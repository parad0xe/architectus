/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 23:41:03 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/08 15:23:24 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	size_t	i = -1;
	char	*tests[] = { "Hello World", "", "\0", NULL };

	while (tests[++i])
		check_is_equal(T_INT, ft_strlen(tests[i]), strlen(tests[i]));
	return (0);
}
