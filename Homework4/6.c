#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//Nanmanat Varisthanist 6509618200

int get_problem();
int get_rate_drop_factor();
int get_kg_rate_conc();
int get_units_conc();
int fig_drops_min(float rate, float tubing);
int fig_ml_hr(int hour);
int by_weight(float rate, float weight, float concentration);
int by_units(float rate, float unit);

int main()
{
    while(true)
    {
        int problem = get_problem();

        if (problem == 1)
        {
            printf("The drop rate per minute is %d.\n", get_rate_drop_factor());
        }
        else if (problem == 2)
        {
            int hour;
            printf("Enter number of hours: ");
            scanf("%d", &hour);
            printf("The rate in milliliters per hour is %d.\n", fig_ml_hr(hour));
        }
        else if (problem == 3)
        {
            printf("The rate in milliliters per hour is %d.\n", get_kg_rate_conc());
        }
        else if (problem == 4)
        {
            printf("The rate milliliters per hour is %d.\n", get_units_conc());
        }
        else if (problem == 5)
        {
            return 0;
        }
    }
}

int get_problem()
{
    int problem;
    printf("Enter the number of the problem you wish to solve.\n");
    printf("\tGIVEN A MEDICAL ORDER IN\t\tCALCULATE RATE IN\n");
    printf("(1)\tml/hr & tubing drop factor\t\tdrop / min\n");
    printf("(2)\t1 L for n hr\t\t\t\tml / hr\n");
    printf("(3)\tmg/kg/hr & concentration in mg/ml\tml / hr\n");
    printf("(4)\tunits/hr & concentration in units/ml\tml / hr\n");
    printf("(5)\tQUIT\n");
    printf("Problem: ");
    scanf("%d", &problem);
    return problem;
}

int get_rate_drop_factor()
{
    float rate, tubing;
    printf("Enter rate in ml/hr: ");
    scanf("%f", &rate);
    printf("Enter tubing's drop factor(drop/ml): ");
    scanf("%f", &tubing);
    return fig_drops_min(rate, tubing);
}

int fig_drops_min(float rate, float tubing)
{
    return round((rate / 60) * tubing);
}

int fig_ml_hr(int hour)
{
    return 1000 / hour;
}

int get_kg_rate_conc()
{
    float rate, weight, concentration;
    printf("Enter rate in mg/kg/hr: ");
    scanf("%f", &rate);
    printf("Enter patient weight in kg: ");
    scanf("%f", &weight);
    printf("Enter concentration in mg/ml: ");
    scanf("%f", &concentration);
    return by_weight(rate, weight, concentration);
}

int by_weight(float rate, float weight, float concentration)
{
    return round(rate * concentration * weight);
}

int get_units_conc()
{
    float rate, unit;
    printf("Enter rate in units/hr: ");
    scanf("%f", &rate);
    printf("Enter concentration in units/ml: ");
    scanf("%f", &unit);
    return by_units(rate, unit);
}

int by_units(float rate, float unit)
{
    return round(rate / unit);
}