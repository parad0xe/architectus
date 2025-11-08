/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 22:02:25 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/08 15:05:45 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{	
	char *test_isalpha = "hazAZ";
	char *test_is_not_alpha = "09";

	while (*test_isalpha)
	{
		check_is_equal(T_INT, ft_isalpha(*test_isalpha), 1);
		test_isalpha++;
	}
	while (*test_is_not_alpha)
	{
		check_is_equal(T_INT, ft_isalpha(*test_is_not_alpha), 0);
		test_is_not_alpha++;
	}

}
