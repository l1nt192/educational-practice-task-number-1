#include <stdio.h>
#include <stdlib.h>

// Функция создает квадратную матрицу
float** createMatrix(int size) 
{
    float** mrx = (float**)malloc(size * sizeof(float*));
    if (mrx == NULL) {
        printf("Failed to allocate memory for identity matrix.\n");
        return NULL;
    }

    for (int i = 0; i < size; i++) 
    {
        mrx[i] = (float*)malloc(size * sizeof(float));
        if (mrx[i] == NULL) {
            printf("Failed to allocate memory for identity matrix row.\n");
            for (int j = 0; j < i; j++) {
                free(mrx[j]);
            }
            free(mrx);
            return NULL;
        }
        for (int j = 0; j < size; j++) {
            mrx[i][j] = (i == j) ? 1 : 0;
        }
    }

    return mrx;
}

// Освобождение памяти для матрицы
void freeMatrix(float** mrx, int size) 
{
    if (mrx == NULL) {
        return;
    }

    for (int i = 0; i < size; i++) 
    {
        free(mrx[i]);
    }
    free(mrx);
}

// Привеодит матрицу к ступенчатому виду
void stepwiseview(float** matrix, float** mrx, int size)
{
    for (int k = 0; k < size; k++) 
    {
        float p = matrix[k][k];

        for (int j = 0; j < size; j++) 
        {
            matrix[k][j] /= p;
            mrx[k][j] /= p;
        }

        for (int i = 0; i < size; i++) 
        {
            if (i != k) 
            {
                float factor = matrix[i][k] / matrix[k][k];
                for (int j = 0; j < size; j++) {
                    matrix[i][j] -= factor * matrix[k][j];
                    mrx[i][j] -= factor * mrx[k][j];
                }
            }
        }
    }
}

// Вывод  квадратной матрицы
void printMatrix(float** identityMatrix, int size) 
{
    if (identityMatrix == NULL) 
    {
        printf("Invalid matrix pointer.\n");
        return;
    }

    printf("Inverse matrix:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) 
        {
            printf("%.2f ", identityMatrix[i][j]);
        }
        printf("\n");
    }
}

// Счет квадратной матрицы
void inverseMatrix(float** matrix, int size) 
{
    if (matrix == NULL) 
    {
        return;
    }

    float** identityMatrix = createMatrix(size);
    if (identityMatrix == NULL) 
    {
        return;
    }

    stepwiseview(matrix, identityMatrix, size);
    printMatrix(identityMatrix, size);

    freeMatrix(identityMatrix, size);
}