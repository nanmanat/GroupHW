#include <stdio.h>
#include <math.h>
//Teerajet Chanpha
//6509618184
float revenue(int t)
{
    double R = 203.265 * pow(1.071, t);
    int Year;
    Year = t + 1984;
	printf("Year %d = %.3f (million dollar)\n", Year, R);
    
	return R;
}
float predict(double income)
{
	float current = 0;
	int i;
	for (i = 0 ; current <= income ; i++ )
		current = revenue(i);

    return i + 1984;
}
int main()
{
    double t;
    t = predict(1000);
}