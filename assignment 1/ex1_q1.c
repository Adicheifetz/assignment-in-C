// Course: Advanced C programming
// exercise 1, question 1
// file name: ex1_q1.c
#define _CRT_SECURE_NO_WARNINGS
// --------------------------- //
// include package section:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --------------------------- //
//
//	Assigned by:
//		Student1_Adi_Cheifetz #207934050
//		Student2_Gil_Assenhaym #322632019
//
// --------------------------- //

// function declarations section:
int* scanArray(int*);
void printArray(int*, int);
int arrangeArray(int**, int);

// --------------------------- //

// main section:
// DO NOT CHANGE the following function:
int main()
{
	int* arr, n, k;

	// Start Program:
	printf("Start Program\n");

	// call functions:
	arr = scanArray(&n);
	k = arrangeArray(&arr, n);

	// write output:
	printf("Output:\n");
	printf("Size of k: %d\n", k);
	printf("Sorted array:\n");
	printArray(arr, n);
	free(arr);

	return 0;
}
// --------------------------- //


// DO NOT CHANGE the following function:
int* scanArray(int* n)
{
	int i;
	int* arr;

	printf("Enter array size: ");
	scanf("%d", n);

	arr = (int*)malloc(sizeof(int) * (*n));
	for (i = 0; i < *n; ++i)
	{
		printf("Enter value #%d: ", i + 1);
		scanf("%d", arr + i);
	}

	return arr;
}
// --------------------------- //


// DO NOT CHANGE the following function:
void printArray(int* arr, int n)
{
	int i;
	printf("{");
	for (i = 0; i < n; ++i)
		printf("%d%s", arr[i], i == n - 1 ? "" : ", ");
	printf("}\n");
}
// --------------------------- //

/// <summary>
/// Combine the two groups using realloc and memcpy only. 
/// </summary>
/// <param>int **arr - Address of the array pointer</param>
/// <param>int n - Size of the array</param>
/// <returns>Size of the first group</returns>
int arrangeArray(int** arr, int n)
{
	int first = 0, last = n - 1, mid, chaek = *arr[first], k=0;
	while (first <= last)
	{
		mid = (last - first) / 2 + first;
		if ((*arr)[mid] > (*arr)[mid + 1])
		{
			k = mid + 1;
			break;
		}
		else if (chaek > (*arr)[mid])
			last = mid - 1;
		else
			first = mid + 1;
	}

	*arr = (int*)realloc(*arr,(k + n) * sizeof(int));
	if (!arr)
		return NULL;
	memcpy((*arr + n), *arr, k * sizeof(int));
	memcpy((*arr), *arr + k, n * sizeof(int));
	*arr = (int*)realloc(*arr, (n) * sizeof(int));
	if (!arr)
		return NULL;

	return k;
}
// --------------------------- //