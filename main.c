#include <stdio.h>
#include <stdlib.h>
#include "inversematrix.h"

int main() 
{
    int size = 0;
    printf("Enter the size of the matrix: ");
    scanf_s("%d", &size);
    float** matrix = (float**)malloc(size * sizeof(float*));
    if (matrix == NULL) 
    {
        printf("Failed to allocate memory for matrix.\n");
        return 0;
    }
    for (int i = 0; i < size; i++) 
    {
        matrix[i] = (float*)malloc(size * sizeof(float));
        if (matrix[i] == NULL) {
            printf("Failed to allocate memory for matrix row.\n");
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return 0;
        }
    }
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i] == NULL) {
                printf("Invalid matrix row pointer.\n");
                for (int x = 0; x < size; x++) 
                {
                    free(matrix[x]);
                }
                free(matrix);
                return 0;
            }
            scanf_s("%f", matrix[i] + j);
        }
    }
    inverseMatrix(matrix, size);
    for (int i = 0; i < size; i++) 
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}