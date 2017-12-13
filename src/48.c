#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 48. Rotate Image

void rotate(int **matrix, int matrixRowSize, int matrixColSize)
{
	int i, j;
	int preValue, nextValue;

	for (i = 0; i < ((matrixRowSize + 1) >> 1); i++)
	{
		for (j = i; j < (matrixColSize - i - 1); j++)
		{
			preValue = matrix[i][j];

			nextValue = matrix[j][matrixColSize - i - 1];
			matrix[j][matrixColSize - i - 1] = preValue;
			preValue = nextValue;

			nextValue = matrix[matrixRowSize - i - 1][matrixColSize - j - 1];
			matrix[matrixRowSize - i - 1][matrixColSize - j - 1] = preValue;
			preValue = nextValue;

			nextValue = matrix[matrixRowSize - j - 1][i];
			matrix[matrixRowSize - j - 1][i] = preValue;
			preValue = nextValue;

			matrix[i][j] = preValue;
		}
	}
}

int main()
{
	int i, j;

	int matrix[][6] = {{2, 29, 20, 26, 16, 28}, {12, 27, 9, 25, 13, 21}, {32, 33, 32, 2, 28, 14}, {13, 14, 32, 27, 22, 26}, {33, 1, 20, 7, 21, 7}, {4, 24, 1, 6, 32, 34}};
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 6; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	int *matrix_ext[6];
	for (i = 0; i < 6; i++)
	{
		matrix_ext[i] = (int *)matrix[i];
	}

	rotate((int **)matrix_ext, 6, 6);

	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 6; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");


	return 0;
}