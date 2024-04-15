// Course: Advanced C programming
// exercise 1, question 2
// file name: ex1_q2.c
#define _CRT_SECURE_NO_WARNINGS
// --------------------------- //
// include package section:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// --------------------------- //
//
//	Assigned by:
//		Student1_Adi_Cheifetz #207934050
//		Student2_Gil_Assenhaym #322632019
//
// --------------------------- //

// structs and function declarations section:
typedef struct point
{
	int x, y;
}point;

typedef struct polygon
{
	int n;
	point* points;
	double scope;
}polygon;

void scanPoint(point* p);
polygon* createPolygon();
double distance(point* p1, point* p2);
double calculateScope(point* points, int n);
int addPoint(polygon* poly);
int removePoint(polygon* poly, int idx);
void freeMemory(polygon* poly);

// --------------------------- //

int main()
{
	int i, n, idx;
	polygon *poly;

	// Start Program:
	printf("Start Program\n");

	// call functions:
	poly = createPolygon();
	printf("How many points to add: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("Point #%d: \n", i + 1);
		addPoint(poly);
	}

	printf("Enter index value to remove, invalid index to stop: ");	
	do
	{
		for (i = 0; i < poly->n; i++)
		{
			printf("(%d,%d)\n", poly->points[i].x, poly->points[i].y);
		}
		scanf("%d", &idx);
	} while (removePoint(poly, idx));
	
	// write output:
	printf("Output: Scope of polygon: %.2lf\n", poly->scope);
	//freeMemory(poly);

	for (i = 0; i < poly->n; i++)
	{
		printf("(%d,%d)\n", poly->points[i].x, poly->points[i].y);
	}

	return 0;
}
// --------------------------- //


/// <summary>
/// Function scan a point in the plane,
/// Used as auxiliary function for createPolygon.
/// </summary>
/// <param>point* p - pointer to p</param>
/// <returns>None</returns>
void scanPoint(point* p)
{

	printf(" please enter numbers for point first  x then y\n");
	scanf("%d  %d", &p->x, &p->y);
}
// --------------------------- //


/// <summary>
/// Function allocate an empty polygon.
/// </summary>
/// <returns>New allocated polygon</returns>
polygon* createPolygon()
{
	polygon* pol1 = (polygon*)malloc(sizeof(polygon));

	if (!pol1)
		return NULL;

	pol1->n = 0;
	pol1->points = NULL;
	pol1->scope = 0.0;

	return pol1;
}
// --------------------------- //


/// <summary>
/// Function calculates distance between 2 adjacent points  
/// </summary>
/// <param>point* p1 - pointer to the first point</param>
/// <param>point* p2 - pointer to the second point</param>
/// <returns>The Euclidean distance between p1 and p2</returns>
double distance(point* p1, point* p2)
{
	double distan;
	distan = sqrt(pow((p1->x) - (p2->x), 2) + pow((p1->y) - (p2->y), 2));
	return distan;
}
// --------------------------- //


/// <summary>
/// Function calculates and returns the Scope of a polygon.
/// </summary>
/// <param>point* points - array of points</param>
/// <param>int n - size of the array</param>
/// <returns>The Scope of a polygon</returns>
double calculateScope(point* points, int n)
{
	if (n < 3)
		return 0;
	double sum = 0;
	int i;
	for (i = 0; i < n - 1; i++)
	{
		sum = sum + distance(points + i, points + i + 1);
	}
	sum += distance(points, points + n-1);
	return sum;
}
// --------------------------- //


/// <summary>
/// Function add a new point at the end of the polygon,
/// and update the scope falue.
/// </summary>
/// <param>polygon* poly - pointer to polygon</param>
/// <returns>1- success, 0- failure</returns>
int addPoint(polygon* poly)
{
	poly->n++;
	poly->points = (point*)realloc(poly->points,poly->n* sizeof(point));
	if (!poly->points)
		return 0;
	scanPoint(poly->points + poly->n - 1);
	poly->scope = calculateScope(poly->points, poly->n);
	return 1;
}
// --------------------------- //


/// <summary>
/// Function remove a point from the polygon,
/// at spesific index.
/// </summary>
/// <param>polygon* poly - pointer to polygon</param>
/// <param>int idx - the index to remove</param>
/// <returns>1- success, 0- failure</returns>
	int removePoint(polygon * poly, int idx)
	{

		int i;
		if (idx < 0 || poly->n <= idx)
			return 0;
		for (i = idx; i < poly->n - 1; i++)
			poly->points[i] = poly->points[i+1];

		poly->n = poly->n - 1;
		poly->points = (point*)realloc(poly->points, poly->n * sizeof(point));
		if (!poly->points)
			return 0;
		poly->scope = calculateScope(poly->points, poly->n);
		return 1;
	}
    
// --------------------------- //


/// <summary>
/// Function free alocated memory. 
/// </summary>
/// <param>polygon* poly - pointer to polygon</param>
/// <returns>None</returns>
void freeMemory(polygon* poly)
{
	free(poly->points);
	free(poly);

}
 //--------------------------- //