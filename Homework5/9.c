#include <stdio.h>
#include <string.h>

//Nanmanat Varisthanist 6509618200

typedef struct
{
    int ID;
    char name[20];
    char type;
    float cost;
    float tax;
    float netPrice;
} Goods;

float findTax(char type, float cost);

int main()
{
    FILE *file = fopen("good.txt", "r");
    FILE *report = fopen("Report.txt", "w");

    Goods myGoods[100];

    int i = 0;

    while(fscanf(file, "%d %s %c %f", &myGoods[i].ID, myGoods[i].name, &myGoods[i].type, &myGoods[i].cost) != EOF)
    {
        i++;
    }

    for (int i = 0; i < 12; i++)
    {
        myGoods[i].tax = findTax(myGoods[i].type, myGoods[i].cost);
        myGoods[i].netPrice = myGoods[i].cost + myGoods[i].tax;
    }

    fprintf(report, "ID   Name\t\t\tType\t Cost\t    Tax   NetPrice\n");

    for (int i = 0; i < 12; i++)
    {
        if (strlen(myGoods[i].name) <= 6)
        {
            fprintf(report, "%d %s\t\t\t%c%12.2f%10.2f%11.2f\n", myGoods[i].ID, myGoods[i].name, myGoods[i].type, myGoods[i].cost, myGoods[i].tax, myGoods[i].netPrice);
        }
        else if (strlen(myGoods[i].name) <= 10)
        {
            fprintf(report, "%d %s\t\t%c%12.2f%10.2f%11.2f\n", myGoods[i].ID, myGoods[i].name, myGoods[i].type, myGoods[i].cost, myGoods[i].tax, myGoods[i].netPrice);
        }
        else
        {
            fprintf(report, "%d %s\t%c%12.2f%10.2f%11.2f\n", myGoods[i].ID, myGoods[i].name, myGoods[i].type, myGoods[i].cost, myGoods[i].tax, myGoods[i].netPrice);
        }
    }

    fclose(file);
    fclose(report);
}

float findTax(char type, float cost)
{
    if (type == 'A')
    {
        return (cost * 10) / 100;
    }
    else if (type == 'B')
    {
        return (cost * 15) / 100;
    }
    else if (type == 'C')
    {
        return (cost * 20) / 100;
    }
    else if (type == 'D')
    {
        return (cost * 40) / 100;
    }

    return 0;
}
