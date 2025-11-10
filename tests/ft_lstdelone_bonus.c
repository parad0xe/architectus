/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:16:14 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/10 10:20:09 by ldecavel         ###   ########lyon.fr   */
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

static	t_list	*node;

void del_free(void *content)
{
    free(content);
}

void test1(void)
{
    node = ft_lstnew(malloc(10));
    ft_lstdelone(node, del_free);
}

void test2(void)
{
    node = ft_lstnew(NULL);
    ft_lstdelone(node, del_free);
}

void test3(void)
{
	ft_lstdelone(NULL, del_free);
}

int main(void)
{
    handle_sigsegv("Check frees node and content [no segfault]", &test1, NO_SEGFAULT);
    handle_sigsegv("Check free node with NULL content [no segfault]", &test2, NO_SEGFAULT);
    handle_sigsegv("Check NULL node [no segfault]", test3, NO_SEGFAULT);
	return (0);
}
