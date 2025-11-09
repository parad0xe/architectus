/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:02:09 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/10 00:57:13 by ldecavel         ###   ########.fr       */
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

static	t_list	*list, *node;

void test1(void)
{
    list = NULL;

    set_description("Empty list returns NULL");
    check_is_equal(PTR, ft_lstlast(list), NULL);
}

void test2(void)
{
    set_description("Single node list returns that node");
    list = ft_lstnew("hello");
    check_is_equal(PTR, ft_lstlast(list), list);
    free(list);
}

void test3(void)
{
    set_description("Two nodes list returns last node");
    list = ft_lstnew("first");
    node = ft_lstnew("last");
    ft_lstadd_front(&list, node);

    t_list *last = ft_lstlast(list);
    check_is_equal(PTR, last, list->next);
    check_is_equal(STR, last->content, "first");
    free(list->next);
    free(list);
}

void test4(void)
{
    int n = 42;

    set_description("List with mixed content, last node correct");
    list = ft_lstnew(&n);
    node = ft_lstnew("string");
    ft_lstadd_front(&list, node);

    t_list *last = ft_lstlast(list);
    check_is_equal(PTR, last, list->next);
    check_is_equal(PTR, last->content, &n);
    free(list->next);
    free(list);
}

void test5(void)
{
    t_list wrong_node = { .content = NULL, .next = (void *)0x1 };
    ft_lstlast(&wrong_node);
}

void test6(void)
{
	ft_lstlast(NULL);
}

int main(void)
{
    handle(&test1);
    handle(&test2);
    handle(&test3);
    handle(&test4);
    handle_sigsegv("Testing ft_lstlast with invalid next pointer might segfault", &test5, SEGFAULT);
    handle_sigsegv("Calling ft_lstlast with NULL list should NOT segfault", &test6, NO_SEGFAULT);
	return (0);
}
