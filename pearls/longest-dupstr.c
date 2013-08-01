#define MAX_LEN 1000

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int pstrcmp(const void *v1, const void *v2) {
    char **s1 = (char **)v1;
    char **s2 = (char **)v2;
    return strcmp(*s1, *s2);
}

unsigned commlen(const char *s1, const char *s2) {
    int len = 0;
    while (*s1 && (*s1++ == *s2++))
        len++;
    return len;
}

int main() {
    char C[MAX_LEN], *A[MAX_LEN];
    char ch;
    unsigned i, maxi, len, max_len = 0, n = 0;

    // input
    while ((ch = getchar()) != EOF) {
        A[n] = &C[n];
        C[n++] = ch;
    }
    A[n] = &C[n];
    C[n] = '\0';

    // sort
    qsort(A, n, sizeof(char *), pstrcmp);

    // max len
    for (i = 0; i < n; i++) {
        len = commlen(A[i], A[i + 1]);
        if (len > max_len) {
            max_len = len;
            maxi = i;
        }
    }

    printf("%.*s\n", max_len, A[maxi]);

    return 0;
}
