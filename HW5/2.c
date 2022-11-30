#include <stdio.h>
#include<string.h>
void fact_calc(int n,char *pstr);
int main()
{
	int number,result;
    char s[1000];
	while(number != -1)
	{
		printf("Enter an integer between 0 and 9 or -1 to quit => ");
		scanf("%d",&number);
		if(number < -1 || number > 9)
			printf("Invalid Entry\n");
		else if (number != -1)
		{
			fact_calc(number,s);
			printf("%s\n",s);
		}
	}
}
void fact_calc(int n,char *pstr)
{
	int factor = 1;
	char ch[99];
	for(int i = n; i > 0; i--)
	{
		factor =  factor * i;
	}
	if(n > 1)
		sprintf(pstr, "* %d! = %d ",n,n);
	else
		sprintf(pstr,"* %d!",n);
	for(int i = n-1; i>0; i--)
	{
		sprintf(ch, "x %d ",i);
		strcat(pstr,ch);
	}
	sprintf(ch, " = %d *",factor);
	strcat(pstr,ch);
}