
#include <stdio.h>

void add(int a[10][10], int b[10][10], int r1, int c1, int r2, int c2)
{
    int i, j;

    if (r1 != r2 || c1 != c2) {
        printf("Cannot add: A is %d x %d, B is %d x %d\n",
               r1, c1, r2, c2);
        return;
    }

    printf("A + B:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++)
            printf("%d%s", a[i][j] + b[i][j],
                   j == c1 - 1 ? "\n" : " ");
    }
}

void subtract(int a[10][10], int b[10][10],
              int r1, int c1, int r2, int c2)
{
    int i, j;

    if (r1 != r2 || c1 != c2) {
        printf("Cannot subtract: A is %d x %d, B is %d x %d\n",
               r1, c1, r2, c2);
        return;
    }

    printf("A - B:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++)
            printf("%d%s", a[i][j] - b[i][j],
                   j == c1 - 1 ? "\n" : " ");
    }
}

void multiply(int a[10][10], int b[10][10],
              int r1, int c1, int r2, int c2)
{
    int i, j, k, sum;

    if (c1 != r2) {
        printf("Cannot multiply: A is %d x %d, B is %d x %d\n",
               r1, c1, r2, c2);
        return;
    }

    printf("A x B (%d x %d):\n", r1, c2);

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            sum = 0;
            for (k = 0; k < c1; k++)
                sum += a[i][k] * b[k][j];

            printf("%d%s", sum, j == c2 - 1 ? "\n" : " ");
        }
    }
}

void transpose(int a[10][10], int r, int c, char name)
{
    int i, j;

    printf("Transpose of %c (%d x %d):\n", name, c, r);

    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++)
            printf("%d%s", a[j][i], j == r - 1 ? "\n" : " ");
    }
}

int main()
{
    int a[10][10], b[10][10];
    int r1, c1, r2, c2, i, j;
    char cmd[10];

    scanf("%d %d", &r1, &c1);

    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    scanf("%d %d", &r2, &c2);

    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);

    while (scanf("%9s", cmd) == 1) {
        if (cmd[0] == 'A' && cmd[1] == '\0')
            add(a, b, r1, c1, r2, c2);
        else if (cmd[0] == 'S' && cmd[1] == '\0')
            subtract(a, b, r1, c1, r2, c2);
        else if (cmd[0] == 'M' && cmd[1] == '\0')
            multiply(a, b, r1, c1, r2, c2);
        else if (cmd[0] == 'T' && cmd[1] == 'A')
            transpose(a, r1, c1, 'A');
        else if (cmd[0] == 'T' && cmd[1] == 'B')
            transpose(b, r2, c2, 'B');
    }

    return 0;
}
