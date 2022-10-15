#include <stdio.h>
#include <math.h>

//Nanmanat Varisthanist 6509618200

float revenue(int t);
float predict(double profit);

int main()
{
    double t = predict(1000);
}

float predict(double profit)
{
    float current = 0;
    int i = 0;
    while (current <= profit)
    {
        current = revenue(i);
        i++;
    }

    return i + 1984;
}

float revenue(int t)
{
    double R = 203.265 * pow(1.071, t);
    printf("Year %d = %.3f\n", t + 1984, R);

    return R;
}