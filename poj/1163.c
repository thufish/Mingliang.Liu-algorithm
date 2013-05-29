#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The matrix
char matrix[100][200]; 
// The size of the real input elements, [2, 100]
int size;

void init_matrix();

int main()
{
    int i, j;
    unsigned res[200];

    init_matrix();

    for (i = 0; i < 2 * size - 1; ++i)
        res[i] = matrix[size - 1][i];
    for (i = size - 2; i >= 0; --i)
        for (j = size - i - 1; j < size + i; j += 2)
            if (res[j - 1] > res[j + 1])
                res[j] = matrix[i][j] + res[j - 1];
            else
                res[j] = matrix[i][j] + res[j + 1];

    printf("%d", res[size - 1]);
    return 0;
}

void init_matrix()
{
    int i, j;

    scanf("%d", &size);
    memset(matrix, size * size * 2, 0);

    for (i = 0; i < size; ++i)
        for (j = 0; j < i + 1; ++j)
            scanf("%d", &matrix[i][size - i - 1 + 2 * j]);
}
