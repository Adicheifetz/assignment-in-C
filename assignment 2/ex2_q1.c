// Course: Advanced C programming
// exercise 2, question 1
// file name: ex2_q1.c

// --------------------------- //
//
//	Assigned by:
//		Student1_Full_Name #ID
//		Student2_Full_Name #ID
//
// --------------------------- //

// --------------------------------------- //
// Include and definition package section:
// --------------------------------------- //
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define scanf_s scanf
#define ROWS 4
#define COLS 4
// --------------------------------------- //
// Types declration section:
// --------------------------------------- //
typedef struct fraction
{
	int num, numerator, denominator;
} fraction;
// --------------------------------------- //
// Functions declration section:
// --------------------------------------- //

fraction ** createMatrix(int rows, int cols);
fraction ** matrixAverageNeighbor(int A[][COLS], int rows, int cols);
fraction neighborFractionAverage(int A[][COLS], int i, int j, int rows, int cols);
void printMatrix(fraction** B, int rows, int cols);
void freeMatrix(fraction** B, int rows);
/** DECLARE HERE ONE FUNCTION ACCORDING TO YOUR NEEDS **/
// --------------------------------------- //
// Main section:
// --------------------------------------- //
int main()
{	
	fraction** B;
	int A[ROWS][COLS] = {
		{5, 12, 6, 8},
		{4, 7, 0, 9},
		{13, 20, 8, 2},
		{18, 0, 2, 6}
	};
	
	// Start Program:
	printf("Start Program\n");

	// call functions:
	B = matrixAverageNeighbor(A, ROWS, COLS);

	// write output:
	printf("Output:\n");
	printMatrix(B, ROWS, COLS);

	// free matrix:
	//freeMatrix(B, ROWS);

	return 0;
}
// --------------------------- //

/// <summary>
/// This code required one extra important function.
/// Think hard about what it should be.
/// </summary>
/// <params>You decide</params>
/// <returns>You decide</returns>

int checking(int i, int j, int rows, int cols)
{
	if (i == -1 || i >= rows)
		return 0;
	else if (j == -1 || j >= cols)
		return 0;
	else
		return 1;
}
// --------------------------- //

/// <summary>
/// This function allocate a dynamic matrix from type fraction.
/// </summary>
/// <param>int rows - the number of rows in the matrix</param>
/// <param>int cols - the number of colums in the matrix</param>
/// <returns>allocated empty matrix B from type fraction</returns>
fraction** createMatrix(int rows, int cols)
{
	fraction** B;
	int i, j;
	B = (fraction**)malloc(rows* sizeof(fraction*));
	for (i = 0; i < rows; i++)
		B[i] = (fraction*)malloc(rows* sizeof(fraction));

	return B;
}
// --------------------------- //

/// <summary>
/// The function receives a static matrix 
/// and for each cell in the matrix calculates 
/// the average of its neighbors.  
/// </summary>
/// <param>int A[][COLS] - the static matrix</param>
/// <param>int rows - the number of rows in the matrix</param>
/// <param>int cols - the number of colums in the matrix</param>
/// <returns>matrix B from type fraction</returns>
fraction** matrixAverageNeighbor(int A[][COLS], int rows, int cols)
{
	fraction** B;
	int i, j;
	B = createMatrix(rows, cols);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
			B[i][j] = neighborFractionAverage(A, i, j, rows, cols);
	}
	return B;
}
// --------------------------- //

/// <summary>
/// The function receives a static matrix, and a cell value,
/// and calculates the average of its neighbors.  
/// </summary>
/// <param>int A[][COLS] - the static matrix</param>
/// <param>int i - the cell row number in matrix</param>
/// <param>int j - the cell colum number in the matrix</param>
/// <param>int rows - the number of rows in the matrix</param>
/// <param>int cols - the number of colums in the matrix</param>
/// <returns>value from type fraction</returns>
fraction neighborFractionAverage(int A[][COLS], int i, int j, int rows, int cols)
{
	double sum = 0;
	int count = 0,num=1;
	int n;
	fraction F;
	if (checking(i-1, j-1, rows, cols))
	{
		sum += A[i-1][j-1];
		count++;
	}
	if (checking(i - 1, j, rows, cols))
	{
		sum += A[i - 1][j];
		count++;
	}if (checking(i - 1, j + 1, rows, cols))
	{
		sum += A[i - 1][j + 1];
		count++;
	}if (checking(i, j + 1, rows, cols))
	{
		sum += A[i][j + 1];
		count++;
	}if (checking(i + 1, j + 1, rows, cols))
	{
		sum += A[i + 1][j + 1];
		count++;
	}if (checking(i + 1, j , rows, cols))
	{
		sum += A[i + 1][j];
		count++;
	}
	if (checking(i+1, j - 1, rows, cols))
	{
		sum += A[i + 1][j - 1];
		count++;
	}
	if (checking(i, j - 1, rows, cols))
	{
		sum += A[i][j - 1];
		count++;
	}

	F.num = sum / count;
	F.numerator = sum - count * F.num;
	F.denominator = count;

	if (F.numerator != 0 &&(F.denominator % F.numerator) == 0)
	{
		F.denominator = F.denominator / F.numerator;
		F.numerator = 1;
	}
	else
	{
		for (n = 2; n < F.numerator * F.numerator; n++)
		{
			if (F.numerator % n == 0 && F.denominator % n == 0)
			{
				F.numerator = F.numerator / n;
				F.denominator = F.denominator / n;
				break;
			}
		}
	}
	return F;

}
// --------------------------- //


/// <summary>
/// The function receives a dynamic matrix from type fraction,
/// and print the matrix as double varibles.  
/// </summary>
/// <param>fraction** B - the dynamic matrix</param>
/// <param>int rows - the number of rows in the matrix</param>
/// <param>int cols - the number of colums in the matrix</param>
/// <returns>None</returns>
void printMatrix(fraction** B, int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
				printf("%.2lf   ", B[i][j].num+(double)B[i][j].numerator/B[i][j].denominator);
		}
		printf("\n");

	}
}
// --------------------------- //


/// <summary>
/// The function receives a dynamic matrix from type fraction,
/// and free all allocated memory.  
/// </summary>
/// <param>fraction** B - the dynamic matrix</param>
/// <param>int rows - the number of rows in the matrix</param>
/// <returns>None</returns>
void freeMatrix(fraction** B, int rows)
{
	int i,j;
	for (i = 0; i < rows; i++)
	{
		free(B[i]);
	}
}
// --------------------------- //
