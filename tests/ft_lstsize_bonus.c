/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:49:17 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/10 00:27:58 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tester.h"

static	t_list	*list, *node;

void test1(void)
{
    set_description("Empty list should return size 0");
    list = NULL;
    check_is_equal(INT, ft_lstsize(list), 0);
}

void test2(void)
{
    set_description("Single element list should return size 1");
    list = ft_lstnew("Hello");
    check_is_equal(INT, ft_lstsize(list), 1);
    
	free(list);
}

void test3(void)
{
    set_description("List with two elements should return size 2");
    list = ft_lstnew("Hello");
    node = ft_lstnew("World");
    ft_lstadd_front(&list, node);
    check_is_equal(INT, ft_lstsize(list), 2);
    
	free(list->next);
    free(list);
}

void test4(void)
{
    int n = 42;
    
	set_description("List with nodes pointing to different content types");
    list = ft_lstnew(&n);
    node = ft_lstnew("String");
    ft_lstadd_front(&list, node);
    check_is_equal(INT, ft_lstsize(list), 2);
    
	free(list->next);
    free(list);
}

int main(void)
{
    handle(&test1);
    handle(&test2);
    handle(&test3);
    handle(&test4);
	return (0);
}
