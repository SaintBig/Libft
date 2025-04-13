#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Colors for printf
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define RESET   "\033[0m"

void test_ft_isalpha(void) {
    printf(YELLOW "\nTESTING ft_isalpha()\n" RESET);
    for (int c = -1; c <= 255; c++) {
        if ((ft_isalpha(c) != 0) != (isalpha(c) != 0)) {
            printf(RED "FAIL: ft_isalpha(%d) = %d, expected %s\n" RESET, 
                   c, ft_isalpha(c), (isalpha(c) ? "non-zero" : "zero"));
            return;
        }
    }
    printf(GREEN "ft_isalpha: OK!\n" RESET);
}

void test_ft_isdigit(void) {
    printf(YELLOW "\nTESTING ft_isdigit()\n" RESET);
    for (int c = -1; c <= 255; c++) {
        if ((ft_isdigit(c) != 0) != (isdigit(c) != 0)) {
            printf(RED "FAIL: ft_isdigit(%d) = %d, expected %s\n" RESET, 
                   c, ft_isdigit(c), (isdigit(c) ? "non-zero" : "zero"));
            return;
        }
    }
    printf(GREEN "ft_isdigit: OK!\n" RESET);
}

void test_ft_isalnum(void) {
    printf(YELLOW "\nTESTING ft_isalnum()\n" RESET);
    for (int c = -1; c <= 255; c++) {
        if ((ft_isalnum(c) != 0) != (isalnum(c) != 0)) {
            printf(RED "FAIL: ft_isalnum(%d) = %d, expected %s\n" RESET, 
                   c, ft_isalnum(c), (isalnum(c) ? "non-zero" : "zero"));
            return;
        }
    }
    printf(GREEN "ft_isalnum: OK!\n" RESET);
}

void test_ft_isprint(void) {
    printf(YELLOW "\nTESTING ft_isprint()\n" RESET);
    for (int c = -1; c <= 255; c++) {
        if ((ft_isprint(c) != 0) != (isprint(c) != 0)) {
            printf(RED "FAIL: ft_isprint(%d) = %d, expected %s\n" RESET, 
                   c, ft_isprint(c), (isprint(c) ? "non-zero" : "zero"));
            return;
        }
    }
    printf(GREEN "ft_isprint: OK!\n" RESET);
}

void test_ft_memset(void) {
    printf(YELLOW "\nTESTING ft_memset()\n" RESET);
    
    char str1[10] = "abcdefghi";
    char str2[10] = "abcdefghi";
    int c = 'x';
    size_t len = 5;

    ft_memset(str1, c, len);
    memset(str2, c, len);

    if (memcmp(str1, str2, 10) != 0) {
        printf(RED "FAIL: ft_memset() did not match memset()\n" RESET);
        printf("  ft_memset result: %.*s\n", 10, str1);
        printf("  memset result:    %.*s\n", 10, str2);
        return;
    }
    printf(GREEN "ft_memset: OK!\n" RESET);
}

void test_ft_bzero(void) {
    printf(YELLOW "\nTESTING ft_bzero()\n" RESET);
    
    char str1[10] = "abcdefghi";
    char str2[10] = "abcdefghi";
    size_t n = 5;

    ft_bzero(str1, n);
    bzero(str2, n);

    if (memcmp(str1, str2, 10) != 0) {
        printf(RED "FAIL: ft_bzero() did not match bzero()\n" RESET);
        printf("  ft_bzero result: %.*s\n", 10, str1);
        printf("  bzero result:    %.*s\n", 10, str2);
        return;
    }
    printf(GREEN "ft_bzero: OK!\n" RESET);
}

void test_ft_memcpy(void) {
    printf(YELLOW "\nTESTING ft_memcpy()\n" RESET);
    
    char src[10] = "123456789";
    char dst1[10] = {0};
    char dst2[10] = {0};
    size_t n = 5;

    ft_memcpy(dst1, src, n);
    memcpy(dst2, src, n);

    if (memcmp(dst1, dst2, 10) != 0) {
        printf(RED "FAIL: ft_memcpy() did not match memcpy()\n" RESET);
        printf("  ft_memcpy result: %.*s\n", 10, dst1);
        printf("  memcpy result:    %.*s\n", 10, dst2);
        return;
    }
    printf(GREEN "ft_memcpy: OK!\n" RESET);
}

/* void test_ft_memmove(void) {
    printf(YELLOW "\nTESTING ft_memmove()\n" RESET);
    
    // Test overlapping regions (src < dst)
    char str1[20] = "123456789";
    char str2[20] = "123456789";
    size_t len = 5;

    ft_memmove(str1 + 3, str1, len);
    memmove(str2 + 3, str2, len);

    if (memcmp(str1, str2, 20) != 0) {
        printf(RED "FAIL: ft_memmove() did not match memmove() (src < dst)\n" RESET);
        printf("  ft_memmove result: %s\n", str1);
        printf("  memmove result:    %s\n", str2);
        return;
    }

    // Test overlapping regions (dst < src)
    char str3[20] = "123456789";
    char str4[20] = "123456789";

    ft_memmove(str3, str3 + 3, len);
    memmove(str4, str4 + 3, len);

    if (memcmp(str3, str4, 20) != 0) {
        printf(RED "FAIL: ft_memmove() did not match memmove() (dst < src)\n" RESET);
        printf("  ft_memmove result: %s\n", str3);
        printf("  memmove result:    %s\n", str4);
        return;
    }

    printf(GREEN "ft_memmove: OK!\n" RESET);
} */

void test_ft_strlen(void) {
    printf(YELLOW "\nTESTING ft_strlen()\n" RESET);
    char *str = "Hello, 42!";
    size_t len = strlen(str);
    size_t ft_len = ft_strlen(str);
    if (len != ft_len) {
        printf(RED "FAIL: ft_strlen(\"%s\") = %zu, expected %zu\n" RESET, str, ft_len, len);
        return;
    }
    printf(GREEN "ft_strlen: OK!\n" RESET);
}

void test_ft_strlcpy(void) {
    printf(YELLOW "\nTESTING ft_strlcpy()\n" RESET);

    char src[] = "Hello";
    char dst1[10] = {0};
    char dst2[10] = {0};
    size_t dstsize = sizeof(dst1);
    size_t ret1, ret2;

    ret1 = ft_strlcpy(dst1, src, dstsize);
    ret2 = strlcpy(dst2, src, dstsize);

    if (ret1 != ret2 || strcmp(dst1, dst2) != 0) {
        printf(RED "FAIL: ft_strlcpy()\n" RESET);
        printf("  ft_strlcpy returned: %zu, dst: \"%s\"\n", ret1, dst1);
        printf("  strlcpy returned:    %zu, dst: \"%s\"\n", ret2, dst2);
        return;
    }
    printf(GREEN "ft_strlcpy: OK!\n" RESET);
}

void test_ft_strlcat(void) {
    printf(YELLOW "\nTESTING ft_strlcat()\n" RESET);

    char src[] = "World";
    char dst1[20] = "Hello";
    char dst2[20] = "Hello";
    size_t dstsize = sizeof(dst1);
    size_t ret1, ret2;

    ret1 = ft_strlcat(dst1, src, dstsize);
    ret2 = strlcat(dst2, src, dstsize);

    if (ret1 != ret2 || strcmp(dst1, dst2) != 0) {
        printf(RED "FAIL: ft_strlcat()\n" RESET);
        printf("  ft_strlcat returned: %zu, dst: \"%s\"\n", ret1, dst1);
        printf("  strlcat returned:    %zu, dst: \"%s\"\n", ret2, dst2);
        return;
    }
    printf(GREEN "ft_strlcat: OK!\n" RESET);
}

void test_ft_toupper(void) {
    printf(YELLOW "\nTESTING ft_toupper()\n" RESET);

    for (int c = -1; c <= 255; c++) {
        if ((ft_toupper(c) != 0) != (toupper(c) != 0)) {
            printf(RED "FAIL: ft_toupper(%d) = %d, expected %d\n" RESET,
                   c, ft_toupper(c), toupper(c));
            return;
        }
    }
    printf(GREEN "ft_toupper: OK!\n" RESET);
}

void test_ft_tolower(void) {
    printf(YELLOW "\nTESTING ft_tolower()\n" RESET);

    for (int c = -1; c <= 255; c++) {
        if ((ft_tolower(c) != 0) != (tolower(c) != 0)) {
            printf(RED "FAIL: ft_tolower(%d) = %d, expected %d\n" RESET,
                   c, ft_tolower(c), tolower(c));
            return;
        }
    }
    printf(GREEN "ft_tolower: OK!\n" RESET);
}

void test_ft_strchr(void) {
    printf(YELLOW "\nTESTING ft_strchr()\n" RESET);

    const char *str = "Hello World";
    int c = 'o';
    char *res1 = ft_strchr(str, c);
    char *res2 = strchr(str, c);

    if (res1 != res2) {
        printf(RED "FAIL: ft_strchr(\"%s\", '%c') = %p, expected %p\n" RESET,
               str, c, (void *)res1, (void *)res2);
        return;
    }

    // Test for non-existent character
    c = 'z';
    res1 = ft_strchr(str, c);
    res2 = strchr(str, c);
    if (res1 != res2) {
        printf(RED "FAIL: ft_strchr(\"%s\", '%c') = %p, expected %p\n" RESET,
               str, c, (void *)res1, (void *)res2);
        return;
    }

    printf(GREEN "ft_strchr: OK!\n" RESET);
}

void test_ft_strrchr(void) {
    printf(YELLOW "\nTESTING ft_strrchr()\n" RESET);
    
    const char *str = "test string";
    int c = 't';
    char *res1 = ft_strrchr(str, c);
    char *res2 = strrchr(str, c);
    
    if (res1 != res2) {
        printf(RED "FAIL: ft_strrchr(\"%s\", '%c') = %p, expected %p\n" RESET,
               str, c, (void*)res1, (void*)res2);
        return;
    }
    printf(GREEN "ft_strrchr: OK!\n" RESET);
}

void test_ft_strncmp(void) {
    printf(YELLOW "\nTESTING ft_strncmp()\n" RESET);
    
    const char *s1 = "test";
    const char *s2 = "test2";
    size_t n = 4;
    int res1 = ft_strncmp(s1, s2, n);
    int res2 = strncmp(s1, s2, n);
    
    if ((res1 < 0 && res2 < 0) || (res1 > 0 && res2 > 0) || (res1 == 0 && res2 == 0)) {
        printf(GREEN "ft_strncmp: OK!\n" RESET);
    } else {
        printf(RED "FAIL: ft_strncmp(\"%s\", \"%s\", %zu) = %d, expected %d\n" RESET,
               s1, s2, n, res1, res2);
    }
}

void test_ft_memchr(void) {
    printf(YELLOW "\nTESTING ft_memchr()\n" RESET);
    
    const char str[] = "test string";
    int c = ' ';
    size_t n = sizeof(str);
    void *res1 = ft_memchr(str, c, n);
    void *res2 = memchr(str, c, n);
    
    if (res1 != res2) {
        printf(RED "FAIL: ft_memchr() = %p, expected %p\n" RESET, res1, res2);
        return;
    }
    printf(GREEN "ft_memchr: OK!\n" RESET);
}

void test_ft_memcmp(void) {
    printf(YELLOW "\nTESTING ft_memcmp()\n" RESET);
    
    const char s1[] = "test";
    const char s2[] = "test2";
    size_t n = 4;
    int res1 = ft_memcmp(s1, s2, n);
    int res2 = memcmp(s1, s2, n);
    
    if ((res1 < 0 && res2 < 0) || (res1 > 0 && res2 > 0) || (res1 == 0 && res2 == 0)) {
        printf(GREEN "ft_memcmp: OK!\n" RESET);
    } else {
        printf(RED "FAIL: ft_memcmp() = %d, expected %d\n" RESET, res1, res2);
    }
}

void test_ft_strnstr(void) {
    printf(YELLOW "\nTESTING ft_strnstr()\n" RESET);

    struct test_case {
        const char *haystack;
        const char *needle;
        size_t len;
        const char *expected;
    } tests[] = {
        {"Hello world", "world", 11, "world"},
        {"Hello world", "world", 5, NULL},
        {"Hello world", "", 11, "Hello world"},
        {"Hello world", "Hello", 11, "Hello world"},
        {"Hello world", "lo w", 11, "lo world"},
        {"Hello world", "goodbye", 11, NULL},
        {"", "needle", 0, NULL},
        {"short", "too long", 4, NULL},
        {"abc", "abc", 3, "abc"},
        {"abc", "abc", 2, NULL},
        {NULL, NULL, 0, NULL} // Sentinel
    };

    for (int i = 0; tests[i].haystack != NULL; i++) {
        char *result = ft_strnstr(tests[i].haystack, tests[i].needle, tests[i].len);
        if ((result == NULL && tests[i].expected != NULL) ||
            (result != NULL && tests[i].expected == NULL) ||
            (result != NULL && strncmp(result, tests[i].expected, strlen(tests[i].expected)) != 0)) {
            printf(RED "FAIL: ft_strnstr(\"%s\", \"%s\", %zu) = %s, expected %s\n" RESET,
                   tests[i].haystack, tests[i].needle, tests[i].len, 
                   result ? result : "NULL", 
                   tests[i].expected ? tests[i].expected : "NULL");
            return;
        }
    }
    printf(GREEN "ft_strnstr: OK!\n" RESET);
}

void test_ft_strdup(void) {
    printf(YELLOW "\nTESTING ft_strdup()\n" RESET);
    char *str = "Duplicate me!";
    char *dup = strdup(str);
    char *ft_dup = ft_strdup(str);
    if (strcmp(dup, ft_dup) != 0) {
        printf(RED "FAIL: ft_strdup(\"%s\") = \"%s\", expected \"%s\"\n" RESET, str, ft_dup, dup);
        free(dup);
        free(ft_dup);
        return;
    }
    free(dup);
    free(ft_dup);
    printf(GREEN "ft_strdup: OK!\n" RESET);
}

void test_ft_substr(void) {
    printf(YELLOW "\nTESTING ft_substr()\n" RESET);
    char *str = "Hello, 42!";
    char *sub = ft_substr(str, 7, 2);
    if (strcmp(sub, "42") != 0) {
        printf(RED "FAIL: ft_substr(\"%s\", 7, 2) = \"%s\", expected \"42\"\n" RESET, str, sub);
        free(sub);
        return;
    }
    free(sub);
    printf(GREEN "ft_substr: OK!\n" RESET);
}

void test_ft_strjoin(void) {
    printf(YELLOW "\nTESTING ft_strjoin()\n" RESET);
    char *s1 = "Hello, ";
    char *s2 = "42!";
    char *joined = ft_strjoin(s1, s2);
    if (strcmp(joined, "Hello, 42!") != 0) {
        printf(RED "FAIL: ft_strjoin(\"%s\", \"%s\") = \"%s\", expected \"Hello, 42!\"\n" RESET, s1, s2, joined);
        free(joined);
        return;
    }
    free(joined);
    printf(GREEN "ft_strjoin: OK!\n" RESET);
}

void test_ft_split(void) {
    printf(YELLOW "\nTESTING ft_split()\n" RESET);
    char *str = "Hello,World,42";
    char **split = ft_split(str, ',');
    if (strcmp(split[0], "Hello") != 0 || strcmp(split[1], "World") != 0 || strcmp(split[2], "42") != 0) {
        printf(RED "FAIL: ft_split(\"%s\", ',') incorrect\n" RESET, str);
        for (int i = 0; split[i]; i++) free(split[i]);
        free(split);
        return;
    }
    for (int i = 0; split[i]; i++) free(split[i]);
    free(split);
    printf(GREEN "ft_split: OK!\n" RESET);
}

/* void test_ft_lstnew(void) {
    printf(YELLOW "\nTESTING ft_lstnew()\n" RESET);
    int content = 42;
    t_list *node = ft_lstnew(&content);
    if (node == NULL || *(int *)node->content != 42) {
        printf(RED "FAIL: ft_lstnew() did not create node correctly\n" RESET);
        free(node);
        return;
    }
    free(node);
    printf(GREEN "ft_lstnew: OK!\n" RESET);
} */

int main(void) {
    printf(BLUE "\n=== LIBFT TESTER ===\n" RESET);

    // Part 1: Libc functions
    test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isprint();
    test_ft_strlen();
	test_ft_memset();
	test_ft_bzero();
	test_ft_memcpy();
	//test_ft_memmove();
	test_ft_strlcpy();
	test_ft_strlcat();
	test_ft_toupper();
	test_ft_tolower();
	test_ft_strchr();
	test_ft_strrchr();
	test_ft_strncmp();
	test_ft_memchr();
	test_ft_memcmp();
	test_ft_strnstr();
    test_ft_strdup();

    // Part 2: Additional functions
    test_ft_substr();
    test_ft_strjoin();
    test_ft_split();

    // Bonus: Linked List functions
    //test_ft_lstnew();

    printf(BLUE "\n=== TESTS COMPLETE ===\n" RESET);
    return (0);
}