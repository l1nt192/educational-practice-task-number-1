#pragma  once
/**
 * @brief создание матрицы  
 * @param size размер матрицы
*/
float** createMatrix(int size);
/**
 * @brief Освобождение памяти для матрицы
 * @param mrx матрица
 * @param size размер матрицы
*/
void freeMatrix(float** mrx, int size);
/**
 * @brief Освобождение памяти для матрицы
 * @param mrx матрица
 * @param size размер матрицы
*/
void stepwiseview(float** matrix, float** mrx, int size);
/**
 * @brief Вывод  обратной матрицы
 * @param mrx матрица
 * @param size размер матрицы
*/
void printMatrix(float** mrx, int size);
/**
 * @brief Вычисление обратной матрицы
 * @param mrx матрица 
 * @param size размер матрицы
*/
void inverseMatrix(float** matrix, int size);