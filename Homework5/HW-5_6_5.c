#include <stdio.h>
#include <string.h>
#include <math.h>

//Nanmanat Varisthanist 6509618200 22
//Group ID: 6

#define RATE_10 7.99;
#define RATE 1.99;

float charges_all(float hour);
float charges_avg(float hour, float total);
float round_money(float money);

int main()
{
    int date, year, id[10], i = 0;
    float hour[10];
    float total[10];
    float avg[10];

    FILE *usage = fopen("usage.txt", "r");
    FILE *charges = fopen("charges.txt", "w");

    fscanf(usage, "%d %d", &date, &year);

    while(fscanf(usage, "%d %f", &id[i], &hour[i]) != EOF)
    {
        i++;
    }

    for (int i = 0; i < 10; i++)
    {
        total[i] = charges_all(hour[i]);
        avg[i] = charges_avg(hour[i], total[i]);
    }

    fprintf(charges, "Charges for %d/%d\n", date, year);

    for (int i = 0; i < 10; i++)
    {
        fprintf(charges, "%d %.1f %.2f %.2f\n", id[i], hour[i], total[i], avg[i]);
    }

    fclose(usage);
    fclose(charges);
}

float charges_all(float hour)
{
    float total = 0;

    if (hour <= 10 && hour > 0)
    {
        total = RATE_10;
    }
    else
    {
        total = RATE_10;
        for (int i = 0; i < hour - 10; i++)
        {
            total += RATE;
        }
    }
    return round_money(total);
}

float charges_avg(float hour, float total)
{
    return round_money(total / hour);
}

float round_money(float money)
{
    if ((int)(money * 1000) % 10 >= 5)
    {
        return (float)((int)(money * 100) + 1) / 100;
    }
    else
    {
        return (money * 100) / 100;
    }
}
