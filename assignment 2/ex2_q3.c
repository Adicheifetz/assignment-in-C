// Course: Advanced C programming
// exercise 2, question 3
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
#define scanf_s scanf

// --------------------------------------- //
// Functions declration section:
// --------------------------------------- //

void decode(char *str);
// --------------------------------------- //
// Main section:
// --------------------------------------- //
int main()
{	
	char str1[] = "Hr(o Zjeno#";
	char str2[] = "H gmlw xmq(jo ojascyr vgpz xmqjcyzxia0 Vc bmqdn zjh gyrw acaf jghdox 0 np vmnko0 dvlwvfsf3 Mms hd xmq cmj-l lgjv3 H/k fmefq sm acz7";
	
	// Start Program:
	printf("Start Program\n");

	// call functions:
	decode(str1);
	decode(str2);

	// write output:
	printf("Output:\n");
	puts(str1);
	puts(str2);

	return 0;
}
// --------------------------- //


/// <summary>
/// The function receives a pointer to a string,
/// and decode it according to the assignment requirment
/// </summary>
/// <param>char *str - encoded string</param>
/// <returns>None</returns>
void decode(char* str)
{
	int counterW = -1, counterI = 1, i =0;

	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			counterI = 1;
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (str[i] + counterI <= 'z')
				str[i] = str[i] + counterI;
			else
				str[i] = str[i]+counterI -26*(((str[i] + counterI) - 'z')/26 +1);
			counterI = counterI * 2;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (str[i] + counterI <= 'Z')
				str[i] = str[i] + counterI;
			else
				str[i] = str[i] + counterI - 26 * (((str[i] + counterI) - 'Z') / 26 + 1);
			counterI = counterI * 2;
		}
		else
		{
			str[i] = str[i] + counterW;
			counterW--;
		}
		i++;
	}
	
}
// --------------------------- //
