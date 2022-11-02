#include <stdio.h>
//6509618184
//Teerajet Chanapha
int main()
{
	char  input;	          
	float num[7];
	printf("Enter any 7 number : ");
	scanf("%f",&num[7]);
	printf("################# MANU ##################\n");
	printf("A. Find the maximum number in the vector\n");
	printf("B. Find the minimum number in the vector\n");
	printf("C. find the total od number in the vector\n");
	printf("D. Sort number in the vector in the ascending order\n");
	printf("Q. Quit program\n");
	printf("Enter your choice <A, B, C, D or Q> :");

	do
	{
		scanf(" %c",&input);	
		if(input == 'A')
		{
			printf("7");
		}
	}
	while(input != 'Q');
	{
		printf("invalld");
	}
}