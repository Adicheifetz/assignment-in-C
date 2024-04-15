#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct rectangle {
	int xTopSmall;
	int yTopSmall;
	int xButtomRight;
	int yButtomRight;
}rectangle;
typedef struct recElement {
	rectangle Rect;
	struct recElement* next;
}recElement;

int validateRectangle(rectangle* rec);
rectangle scanRectangle();
recElement* createElement();
recElement* createRectList();
rectangle findSmallest(recElement* head);
void printRectangle(rectangle* rec);
void printList(recElement* head);
void freeList(recElement* head);

rectangle scanRectangle()
{
	rectangle r1;
	printf("enter points");
	scanf("%d", &r1.xTopSmall);
	scanf("%d", &r1.yTopSmall);
	scanf("%d", &r1.xButtomRight);
	scanf("%d", &r1.yButtomRight);
	while (validateRectangle(&r1) == 0)
	{
		printf("erorr enter points");
		scanf("%d", &r1.xTopSmall);
		scanf("%d", &r1.yTopSmall);
		scanf("%d", &r1.xButtomRight);
		scanf("%d", &r1.yButtomRight);
	}
	return r1;
}

int validateRectangle(rectangle* rec)
{
	if (rec->xButtomRight == rec->xTopSmall && rec->yTopSmall == rec->yButtomRight)
		return 2;
	else if (rec->xTopSmall >= rec->xButtomRight || rec->yButtomRight >= rec->yTopSmall)
		return 0;
	else
		return 1;
}

recElement* createElement()
{
	int ch;
	rectangle r2 = scanRectangle();
	ch = validateRectangle(&r2);
	if (ch == 1)
	{
		recElement* r1 = (recElement*)malloc(sizeof(recElement));
		if (!r1)
			return NULL;
		r1->Rect = r2;
		return r1;
	}
	else
		return NULL;
}

recElement* createRectList()
{
	recElement* ptr = NULL;
	recElement* r1 = (recElement*)malloc(sizeof(recElement));
	r1 = createElement();
	if (!r1)
		return NULL;
	r1->next = NULL;
	ptr = r1;
	while (ptr != NULL)
	{
		ptr->next = createElement();
		ptr = ptr->next;
	}

	free(ptr);
	ptr = NULL;

	return r1;
}

rectangle findSmallest(recElement* head)
{
	rectangle Min;
	if (head == NULL)
	{
		Min.xButtomRight = 0;
		Min.xTopSmall = 0;
		Min.yButtomRight = 0;
		Min.yTopSmall = 0;
		return Min;
	}
	else
	{
		Min.xTopSmall = head->Rect.xTopSmall;
		Min.yTopSmall = head->Rect.yTopSmall;
		Min.xButtomRight = head->Rect.xButtomRight;
		Min.yButtomRight = head->Rect.yButtomRight;
		head = head->next;
		while (head != NULL)
		{
			if (Min.xTopSmall > head->Rect.xTopSmall)
				Min.xTopSmall = head->Rect.xTopSmall;
			if (Min.yTopSmall < head->Rect.yTopSmall)
				Min.yTopSmall = head->Rect.yTopSmall;
			if (Min.xButtomRight < head->Rect.xButtomRight)
				Min.xButtomRight = head->Rect.xButtomRight;
			if (Min.yButtomRight > head->Rect.yButtomRight)
				Min.yButtomRight = head->Rect.yButtomRight;
			head = head->next;
		}
		return Min;
	}
}

void printRectangle(rectangle* rec)
{
	printf("[(%d,%d)(%d,%d)]", rec->xTopSmall, rec->yTopSmall, rec->xButtomRight, rec->yButtomRight);

}

void printList(recElement* head)
{
	while (head != NULL)
	{
		printRectangle(head);
		printf("->");
		head = head->next;
	}
	printf("NULL");
}
void freeList(recElement* head)
{
	recElement* node = NULL;
	while (head != NULL)
	{
		node = head->next;
		free(head);
		head = node;
	}

}
int main()
{
	rectangle rec;
	recElement* head = NULL;

	// Start Program:
	printf("Start Program\n");

	// call functions:
	head = createRectList();

	printf("\n\nRectangle list:\n");
	printList(head);

	rec = findSmallest(head);

	printf("\n\nFilling rectangle:\n");
	printRectangle(&rec);


	printf("\n\n");

	return 0;
}
