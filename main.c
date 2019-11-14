#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int ** buff;
    int m;
    int n;
};


void view(struct Matrix * matrix)
{
    for (int i = 0; i < matrix -> m; i++)
    {
        for(int j = 0; j < matrix ->n; j++)
        {
            printf("%d ", matrix -> buff[i][j]);
        }
        printf("\n");
    }
}


struct Matrix * matrix_init(int M, int N, int zero)
{
    struct Matrix * matrix = (struct Matrix *)calloc(1, sizeof(struct Matrix));
    matrix -> m = M;
    matrix -> n = N;
    matrix -> buff =  (int**)calloc(matrix -> m, sizeof(int));
    for (int i = 0; i < matrix -> m; i++)
    {
        matrix ->buff[i] = (int*)calloc(matrix -> n, sizeof(int));
        for(int j = 0; j < matrix -> n; j++)
        {
            if (zero == 1)
                matrix -> buff[i][j] = 0;
            else
                scanf("%d", &(matrix -> buff[i][j]));
        }
    }
    return matrix;
}


struct Matrix * matrix_dot(struct Matrix * m1, struct Matrix * m2)
{
    if (m1 -> n != m2 -> m)
    {
        printf("Error! Incompatible sizes!\n");
        return 0;
    }
    else
    {
        struct Matrix * result = matrix_init((m1 -> m), (m2 -> n), 1);
        for (int i = 0; i < (m1 -> m); i++)
        { 
            for (int k = 0; k < (m2 -> n); k++)
            {
                for (int j = 0; j < (m1 -> n); j++)
                {
                   result -> buff[i][k] = result ->buff[i][k]  + (m1 -> buff[i][j]) * (m2 -> buff[j][k]); 
                }
            }
        }
        return result;
    }
    return 0;
}

int main()
{
    int M1, N1, M2, N2;
    scanf("%d%d", &M1, &N1);
    scanf("%d%d", &M2, &N2);
    struct Matrix * matrix1 = matrix_init(M1, N1, 0);
    struct Matrix * matrix2 = matrix_init(M2, N2, 0);
    printf("Matrix A\n");
    view(matrix1);
    printf("Matrix B\n");
    view(matrix2);
    printf("Result C\n");
    view(matrix_dot(matrix1, matrix2));
    return 0;
}
