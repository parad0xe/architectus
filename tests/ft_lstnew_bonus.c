/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 20:18:17 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/10 00:57:19 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tester.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = malloc(sizeof(struct s_list));
	if (!ptr)
		return (0);
	ptr->content = content;
	ptr->next = 0;
	return (ptr);
}

static	t_list	*list;

void	test1(void)
{
	set_description("Create new list with content pointer on str 'hello'");
	list = ft_lstnew("Hello");
	check_is_equal(STR, list->content, "Hello");
	
	set_description("Create new list with next = 'null'");
	check_is_equal(PTR, list->next, NULL);
	free(list);
}

void	test2(void)
{
	list = ft_lstnew(NULL);
	free(list);
}

void	test3(void)
{
	int		n = 98;
	set_description("Create new list with pointer on int");
	list = ft_lstnew(&n);
	check_is_equal(PTR, list->content, &n);
	free(list);
}

int	main(void)
{
	handle(&test1);
	handle_sigsegv("Create new list with NULL content", &test2, NO_SEGFAULT);
	handle(&test3);
	return (0);
}
