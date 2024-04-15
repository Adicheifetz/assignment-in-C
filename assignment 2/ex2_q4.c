// Course: Advanced C programming
// exercise 2, question 4
// file name: ex2_q3.c

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
#include<string.h>
#define scanf_s scanf
#define PATH1 "c:\\temp\\file1.txt"
#define PATH2 "c:\\temp\\file2.txt"
#define PATH3 "c:\\temp\\file3.txt"


// --------------------------------------- //
// Functions declration section:
// --------------------------------------- //

int memoryReport(char* filename);
// --------------------------------------- //
// Main section:
// --------------------------------------- //
int main()
{
	int total1, total2, total3;
	// Start Program:
	printf("Start Program\n");

	// call functions:
	total1 = memoryReport(PATH1);
	total2 = memoryReport(PATH2);
	total3 = memoryReport(PATH3);

	// write output:
	printf("Output:\n");
	printf("First file required %d bytes\n", total1);
	printf("Second file required %d bytes\n", total2);
	printf("Third file required %d bytes\n", total3);

	return 0;
}
// --------------------------- //


/// <summary>
/// The function receives a pointer to a string, representing a path to a file.
/// The function output all varibles declerations and their size in byte.
/// </summary>
/// <param>char *filename - valid path to a file</param>
/// <returns>total bytes required</returns>

int findBit(char* str,int n)
{
	int i;
				str[n] = '\0';

				if (n == 3)
				{
					return sizeof(int);
				}
				else if (n == 4)
				{
					if (str[0] == 'c')
						return sizeof(char);
					else
						return sizeof(long);
				}
				else if (n == 5)
					if (str[0] == 'f')
						return sizeof(float);
					else
						return sizeof(short);
				else if (n == 6)
					return sizeof(double);
				else if (n == 8)
					return sizeof(unsigned int);
			}


int memoryReport(char* filename)
{
	char c,c1='a';
	char str[200];
	int j, n = 0, sizebit, num = 0,num2=0, counter = 0;
	FILE* f = fopen(filename, "r");
	if (!f)
		return NULL;
	while ((c = fgetc(f))!= EOF)
	{
		
		if (c == '\t')
			c = fgetc(f);
		if (c=='*')
			c1 = c;
		if(c  != ' ' && c >= 'a' && c <= 'z')
		{
			str[n++] = c;
		}
		else
		{
			str[n] = '\0';
			sizebit = findBit(str,n);
			if (str[0] == 'u')
			{
				while ((c=getc(f))!='t')
				{

				}
				c=getc(f);
			}
			if (str[0] == 'l')
			{
				n = 0;
				if (c1 != 'a')
					str[n++] = c;
				while ((c = fgetc(f)) != ';' && c != ','&& c!=' ')
				{
					if (c == '\t')
						c = fgetc(f);
					if (c != ' ')
						str[n++] = c;
				}
				if (str[0] == 'l' && str[1] == 'o' && str[2] == 'n' && str[3] == 'g' && str[4] == '\0')
				{
					sizebit = sizeof(long long);
					n = 0;
				}
				else
				{
					str[n] = '\0';
					if (str[0] == '*')
					{
						if (str[n - 1] == ']')
						{
							n = 0;
							n++;
							while (str[n] != '[')
							{
								printf("%c", str[n]);
								n++;
							}
							n++;
							while (str[n] != ']')
							{
								num = num * 10 + str[n] - '0';
								n++;
							}

							printf(" requires %d bytes\n", num * 4);
							counter += 4 * num;
							num = 0;
						}
						else
						{
							for (j = 0; j < strlen(str) - 1; j++)
							{
								str[j] = str[j + 1];
							}
							str[j] = '\0';
							printf("%s requires 4 bytes\n", str);
							counter += 4;
						}

					}
					else if (str[n - 1] == ']')
					{
						n = 0;
						while (str[n] != '[')
						{
							printf("%c", str[n]);
							n++;
						}
						n++;
						while (str[n] != ']')
						{
							num = num * 10 + str[n] - '0';
							n++;
						}
						n++;
						if (str[n] == '[')
						{
							n++;
							while (str[n] != ']')
							{
								num2 = num2 * 10 + str[n] - '0';
								n++;
							}
							printf(" requires %d bytes\n", num * num2 * sizebit);
							counter += sizebit * num * num2;
							num = 0;
							num = 0;
						}
						else
						{
							printf(" requires %d bytes\n", num * sizebit);
							counter += sizebit * num;
							num = 0;
						}

					}
					else
					{
						printf("%s requires % d bytes\n", str, sizebit);
						counter += sizebit;
					}
					n = 0;
					c1 = 'a';
					
				}
			}


			n = 0;
			if (c1 != 'a')
				str[n++] = c;
			while ( (c = fgetc(f))!='\n' && c != ';')
			{
				
				if (c != ' ')
					str[n++] = c;
				while ((c = fgetc(f)) != ',' && c!= ';' )
				{
					if (c == '\t')
						c = fgetc(f);
					if (c != ' ')
						str[n++] = c;
				}
				str[n] = '\0';
				if (str[0] == '*')
				{
					if (str[n - 1] == ']')
					{
						n = 0;
						n++;
						while (str[n] != '[')
						{
							printf("%c", str[n]);
							n++;
						}
						n++;
						while (str[n] != ']')
						{
							num = num * 10 + str[n] - '0';
							n++;
						}

						printf(" requires %d bytes\n", num * 4);
						counter += 4 * num;
						num = 0;
					}
					else
					{
						for (j = 0; j < strlen(str) - 1; j++)
						{
							str[j] = str[j + 1];
						}
						str[j] = '\0';
						printf("%s requires 4 bytes\n", str);
						counter += 4;
					}

				}
				else if (str[n - 1] == ']')
				{
					n = 0;
					while (str[n] != '[')
					{
						printf("%c", str[n]);
						n++;
					}
					n++;
					while (str[n] != ']')
					{
						num = num * 10 + str[n] - '0';
						n++;
					}
					n++;
					if (str[n] == '[')
					{
						n++;
						while (str[n] != ']')
						{
							num2 = num2 * 10 + str[n] - '0';
							n++;
						}
						printf(" requires %d bytes\n", num * num2 * sizebit);
						counter += sizebit * num * num2;
						num = 0;
						num2 = 0;
					}
					else
					{
						printf(" requires %d bytes\n", num * sizebit);
						counter += sizebit * num;
						num = 0;
					}
				}
				else
				{
					printf("%s requires % d bytes\n", str, sizebit);
					counter += sizebit;
				}
				n = 0;
				c1 = 'a';
			}
		}
	}
	return counter;
}
// --------------------------- //
