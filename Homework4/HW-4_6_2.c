#include <Stdio.h>
#include <math.h>

//Teerajet Chanpha 6509618184 20
//Group ID: 6

int main()
{
	float Area = 0;
	int num,a,x,y;
	int i,j,n;
	printf("Enter N: ");
	scanf("%d", &n);
	float int_x[n],int_y[n];
	for (i = 0 ; i < n ; i++)
	{	
		printf("x%d,y%d:",i,i);
		scanf("%f %f", &int_x[i],&int_y[i]);
		
	}
	for (j = 0 ; j < n ; j++)
	{
		Area  = Area + ((int_x[j+1])+int_x[j])*((int_y[j+1])-int_y[j]);
	}
	Area = fabs(Area)*0.5;
	printf("%.2f",Area);
}