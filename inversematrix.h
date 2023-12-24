#pragma  once
/**
 * @brief �������� �������  
 * @param size ������ �������
*/
float** createMatrix(int size);
/**
 * @brief ������������ ������ ��� �������
 * @param mrx �������
 * @param size ������ �������
*/
void freeMatrix(float** mrx, int size);
/**
 * @brief ������������ ������ ��� �������
 * @param mrx �������
 * @param size ������ �������
*/
void stepwiseview(float** matrix, float** mrx, int size);
/**
 * @brief �����  �������� �������
 * @param mrx �������
 * @param size ������ �������
*/
void printMatrix(float** mrx, int size);
/**
 * @brief ���������� �������� �������
 * @param mrx ������� 
 * @param size ������ �������
*/
void inverseMatrix(float** matrix, int size);