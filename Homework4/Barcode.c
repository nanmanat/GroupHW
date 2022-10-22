#include <stdio.h>
//Teerajet Chanpha
int main()
{
	char barcode[12];
	long int i,j;
	long int OddSum = 0,EvenSum = 0,lastnum = 0 ;
	printf("Enter your barcode :");
	for (i = 0 ; i < 12 ; i++ )
		scanf("%c",&barcode[i]);
	for( j = 1 ; j < 12 ; j++)
	{
		if(( j  % 2) == 0)
			EvenSum = EvenSum + barcode[j - 1]  - 48;
		else if ( j  % 2 != 0)
			OddSum = OddSum + barcode[j - 1]  - 48;
	}
	OddSum = OddSum * 3;
	EvenSum = EvenSum + OddSum;
	lastnum = EvenSum % 10;
	if(lastnum != 0)
		lastnum = 10 - (EvenSum % 10);
	else if (lastnum == 0)
		lastnum = 0;	
	if(lastnum == barcode[11] - 48)
		printf("Result is validated");
	else 
		printf("Result is error in barcode");
}