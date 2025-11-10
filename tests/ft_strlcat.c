/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:08:55 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/10 01:14:17 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void	*ft_memset(void *s, int c, size_t n)
{
	while (n--)
		((unsigned char *)s)[n] = (unsigned char)c;
	return (s);
}

size_t	ft_strlen(char const *s)
{
	size_t	i = -1;

	while (s[++i])
		;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	while (i + 1 < dstsize && src[i])
		*dst++ = src[i++];
	if (dstsize)
		*dst = 0;
	src_len = -1;
	while (src[++src_len])
		;
	return (src_len);
}

size_t strlcat(char *dest, const char *src, size_t size);

static char     *ft_dest, *dest, *src;
static size_t   ft_res, res, size;

void test1(void)
{
    set_description("Test regular string [return value]");
    ft_dest = malloc(10); dest = malloc(10);
    src = "Hello world"; size = 5;
    ft_res = ft_strlcat(ft_dest, src, size);
    res = strlcat(dest, src, size);
    check_is_equal(SIZE_T, ft_res, res);
    free(ft_dest); free(dest);
}

void test2(void)
{
    set_description("Test regular string [strings]");
    ft_dest = malloc(10); dest = malloc(10);
    src = "Hello world"; size = 5;
    ft_strlcat(ft_dest, src, size); strlcat(dest, src, size);
    check_is_equal(STR, ft_dest, dest);
    free(ft_dest); free(dest);
}

void test3(void)
{
    ft_dest = ""; src = "Hello world"; size = 5;
    (void)ft_strlcat(ft_dest, src, size);
}

void test4(void)
{
    set_description("Size 0");
    ft_dest = malloc(10); dest = malloc(10);
    src = "Hello world"; size = 0;
    ft_res = ft_strlcat(ft_dest, src, size);
    res = strlcat(dest, src, size);
    check_is_equal(SIZE_T, ft_res, res);
    free(ft_dest); free(dest);
}

void test5(void)
{
    set_description("Empty src");
    ft_dest = malloc(10); dest = malloc(10);
    src = ""; size = 0;
    ft_res = ft_strlcat(ft_dest, src, size);
    res = strlcat(dest, src, size);
    check_is_equal(SIZE_T, ft_res, res);
    free(ft_dest); free(dest);
}

void test6(void)
{
    set_description("Size 1");
    ft_dest = malloc(10); dest = malloc(10);
    src = "Hello world"; size = 1;
    ft_res = ft_strlcat(ft_dest, src, size);
    res = strlcat(dest, src, size);
    check_is_equal(SIZE_T, ft_res, res);
    free(ft_dest); free(dest);
}

void test7(void)
{
    ft_dest = NULL; src = "Hello world"; size = 5;
    (void)ft_strlcat(ft_dest, src, size);
}

void test8(void)
{
    ft_dest = malloc(8); src = NULL; size = 5;
    (void)ft_strlcat(ft_dest, src, size);
}

void test9(void)
{
    set_description("Dest already has content [return value]");
    ft_dest = malloc(20); dest = malloc(20);
    ft_strlcpy(ft_dest, "Hi ", 4); ft_strlcpy(dest, "Hi ", 4);
    src = "there!"; size = 20;
    ft_res = ft_strlcat(ft_dest, src, size);
    res = strlcat(dest, src, size);
    check_is_equal(SIZE_T, ft_res, res);
    free(ft_dest); free(dest);
}

void test10(void)
{
    set_description("Dest already has content [strings]");
    ft_dest = malloc(20); dest = malloc(20);
    ft_strlcpy(ft_dest, "Hi ", 4); ft_strlcpy(dest, "Hi ", 4);
    src = "there!"; size = 20;
    ft_strlcat(ft_dest, src, size); strlcat(dest, src, size);
    check_is_equal(STR, ft_dest, dest);
    free(ft_dest); free(dest);
}

void test11(void)
{
    set_description("Truncation when size < dest len [return value]");
    ft_dest = malloc(10); dest = malloc(10);
    ft_strlcpy(ft_dest, "abcdef", 7); ft_strlcpy(dest, "abcdef", 7);
    src = "12345"; size = 3;
    ft_res = ft_strlcat(ft_dest, src, size);
    res = strlcat(dest, src, size);
    check_is_equal(SIZE_T, ft_res, res);
    free(ft_dest); free(dest);
}

void test12(void)
{
    set_description("Truncation when size < dest len [strings]");
    ft_dest = malloc(10); dest = malloc(10);
    ft_strlcpy(ft_dest, "abcdef", 7); ft_strlcpy(dest, "abcdef", 7);
    src = "12345"; size = 3;
    ft_strlcat(ft_dest, src, size); strlcat(dest, src, size);
    check_is_equal(STR, ft_dest, dest);
    free(ft_dest); free(dest);
}

void test13(void)
{
    set_description("Dest too small [return value]");
    ft_dest = malloc(12); dest = malloc(12);
    ft_strlcpy(ft_dest, "abc", 4); ft_strlcpy(dest, "abc", 4);
    src = "defgh"; size = ft_strlen("abc") + ft_strlen("defgh");
    ft_res = ft_strlcat(ft_dest, src, size);
    res = strlcat(dest, src, size);
    check_is_equal(SIZE_T, ft_res, res);
    free(ft_dest); free(dest);
}

void test14(void)
{
    set_description("Dest too small [strings]");
    ft_dest = malloc(12); dest = malloc(12);
    ft_strlcpy(ft_dest, "abc", 4); ft_strlcpy(dest, "abc", 4);
    src = "defgh"; size = ft_strlen("abc") + ft_strlen("defgh");
    ft_strlcat(ft_dest, src, size); strlcat(dest, src, size);
    check_is_equal(STR, ft_dest, dest);
    free(ft_dest); free(dest);
}

void test15(void)
{
    set_description("Long src [return value]");
    ft_dest = malloc(50); dest = malloc(50);
    ft_memset(ft_dest, 0, 50); ft_memset(dest, 0, 50);
    ft_strlcpy(ft_dest, "short", 6); ft_strlcpy(dest, "short", 6);
    src = malloc(1001); ft_memset(src, 'A', 1000); src[1000] = '\0'; size = 50;
    ft_res = ft_strlcat(ft_dest, src, size);
    res = strlcat(dest, src, size);
    check_is_equal(SIZE_T, ft_res, res);
    free(ft_dest); free(dest); free(src);
}

void test16(void)
{
    set_description("Long src [strings]");
    ft_dest = malloc(50); dest = malloc(50);
    ft_memset(ft_dest, 0, 50); ft_memset(dest, 0, 50);
    ft_strlcpy(ft_dest, "short", 6); ft_strlcpy(dest, "short", 6);
    src = malloc(1001); ft_memset(src, 'A', 1000); src[1000] = '\0'; size = 50;
    ft_strlcat(ft_dest, src, size); strlcat(dest, src, size);
    check_is_equal(STR, ft_dest, dest);
    free(ft_dest); free(dest); free(src);
}

void test17(void)
{
    set_description("Empty dest with size 1 [return value]");
    ft_dest = malloc(10); dest = malloc(10);
    ft_dest[0] = '\0'; dest[0] = '\0';
    src = "Hello world"; size = 1;
    ft_res = ft_strlcat(ft_dest, src, size);
    res = strlcat(dest, src, size);
    check_is_equal(SIZE_T, ft_res, res);
    free(ft_dest); free(dest);
}

void test18(void)
{
    set_description("Empty dest with size 1 [strings]");
    ft_dest = malloc(10); dest = malloc(10);
    ft_dest[0] = '\0'; dest[0] = '\0';
    src = "Hello world"; size = 1;
    ft_strlcat(ft_dest, src, size); strlcat(dest, src, size);
    check_is_equal(STR, ft_dest, dest);
    free(ft_dest); free(dest);
}

void test19(void)
{
    set_description("dest size == dest len [return value]");
    ft_dest = malloc(10); dest = malloc(10);
    ft_strlcpy(ft_dest, "abc", 4); ft_strlcpy(dest, "abc", 4);
    src = "12345"; size = ft_strlen("abc");
    ft_res = ft_strlcat(ft_dest, src, size);
    res = strlcat(dest, src, size);
    check_is_equal(SIZE_T, ft_res, res);
    free(ft_dest); free(dest);
}

void test20(void)
{
    set_description("dest size == dest len [strings]");
    ft_dest = malloc(10); dest = malloc(10);
    ft_strlcpy(ft_dest, "abc", 4); ft_strlcpy(dest, "abc", 4);
    src = "12345"; size = ft_strlen("abc");
    ft_strlcat(ft_dest, src, size); strlcat(dest, src, size);
    check_is_equal(STR, ft_dest, dest);
    free(ft_dest); free(dest);
}

int main(void)
{
    handle(&test1); handle(&test2); handle_sigsegv("Empty dest", &test3, SEGFAULT);
	handle(&test4); handle(&test5); handle(&test6); handle_sigsegv("NULL dest", &test7, SEGFAULT);
	handle_sigsegv("NULL src", &test8, SEGFAULT); handle(&test9); handle(&test10); handle(&test11);
	handle(&test12); handle(&test13); handle(&test14); handle(&test15); handle(&test16);
    handle(&test17); handle(&test18); handle(&test19); handle(&test20);
    return (0);
}
