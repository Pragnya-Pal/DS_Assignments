


#include <stdio.h>

int main()
{
    int a[20][20], b[20][20];
    int A[500][3], B[500][3];
    int SUM[1000][3], TRANS[500][3];
    int S[20] = {0}, T[20] = {0};
    int r, c, i, j, n1 = 0, n2 = 0;
    int k, p, q, x, y, z, pos;

    scanf("%d%d", &r, &c);

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &b[i][j]);

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                n1++;
                A[n1][0] = i;
                A[n1][1] = j;
                A[n1][2] = a[i][j];
                S[j]++;
            }

            if (b[i][j] != 0)
            {
                n2++;
                B[n2][0] = i;
                B[n2][1] = j;
                B[n2][2] = b[i][j];
            }
        }

    A[0][0] = r;
    A[0][1] = c;
    A[0][2] = n1;

    B[0][0] = r;
    B[0][1] = c;
    B[0][2] = n2;

    printf("A = %d %d %d\n", r, c, n1);
    for (i = 1; i <= n1; i++)
        printf("%d %d %d\n", A[i][0], A[i][1], A[i][2]);

    printf("B = %d %d %d\n", r, c, n2);
    for (i = 1; i <= n2; i++)
        printf("%d %d %d\n", B[i][0], B[i][1], B[i][2]);

    k = 1;
    for (i = 0; i < c; i++)
    {
        T[i] = k;
        k += S[i];
    }

    printf("S =");
    for (i = 0; i < c; i++)
        printf(" %d", S[i]);
    printf("\n");

    printf("T =");
    for (i = 0; i < c; i++)
        printf(" %d", T[i]);
    printf("\n");

    TRANS[0][0] = c;
    TRANS[0][1] = r;
    TRANS[0][2] = n1;

    k = 1;
    for (i = 0; i < c; i++)
        for (j = 1; j <= n1; j++)
            if (A[j][1] == i)
            {
                TRANS[k][0] = A[j][1];
                TRANS[k][1] = A[j][0];
                TRANS[k][2] = A[j][2];
                k++;
            }

    printf("TRANSPOSE = %d %d %d\n", c, r, n1);
    for (i = 1; i <= n1; i++)
        printf("%d %d %d\n", TRANS[i][0],
               TRANS[i][1], TRANS[i][2]);

    p = 1;
    q = 1;
    k = 1;

    while (p <= n1 && q <= n2)
    {
        x = A[p][0] * c + A[p][1];
        y = B[q][0] * c + B[q][1];

        if (x < y)
        {
            SUM[k][0] = A[p][0];
            SUM[k][1] = A[p][1];
            SUM[k][2] = A[p][2];
            p++;
            k++;
        }
        else if (x > y)
        {
            SUM[k][0] = B[q][0];
            SUM[k][1] = B[q][1];
            SUM[k][2] = B[q][2];
            q++;
            k++;
        }
        else
        {
            z = A[p][2] + B[q][2];

            if (z != 0)
            {
                SUM[k][0] = A[p][0];
                SUM[k][1] = A[p][1];
                SUM[k][2] = z;
                k++;
            }

            p++;
            q++;
        }
    }

    while (p <= n1)
    {
        SUM[k][0] = A[p][0];
        SUM[k][1] = A[p][1];
        SUM[k][2] = A[p][2];
        p++;
        k++;
    }

    while (q <= n2)
    {
        SUM[k][0] = B[q][0];
        SUM[k][1] = B[q][1];
        SUM[k][2] = B[q][2];
        q++;
        k++;
    }

    printf("SUM = %d %d %d\n", r, c, k - 1);
    for (i = 1; i < k; i++)
        printf("%d %d %d\n", SUM[i][0],
               SUM[i][1], SUM[i][2]);

    return 0;
}
