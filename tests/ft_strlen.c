/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 22:50:14 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/07 23:08:03 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../../libft.h"

int	main(void)
{
	printf("libft:    |%ld|\n", ft_strlen("oui"));
	printf("original: |%ld|\n", strlen("oui"));
}
