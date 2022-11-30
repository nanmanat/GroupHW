#include <stdio.h>
#include <string.h>
float findTax(char type, float cost);

typedef struct
{
    int ID;
    char name[20];
    char type;
    float cost;
    float tax;
    float netPrice;
} Goods;

int main()
{
    Goods myGoods[100];
    FILE *fptr = fopen("goods.txt", "r");
    FILE *fptr1 = fopen("Report.txt", "w");

    int i = 0;
    fprintf(fptr1, "ID   Name\t\t\tType\t Cost\t    Tax   NetPrice\n");

    while(fscanf(fptr, "%d %s %c %f", &(myGoods[i].ID), myGoods[i].name, &(myGoods[i].type), &(myGoods[i].cost)) != EOF)
    {
        i++;
    }

    for (int i = 0; i < 12; i++)
    {
        myGoods[i].tax = findTax(myGoods[i].type, myGoods[i].cost);
        myGoods[i].netPrice = myGoods[i].cost + myGoods[i].tax;
    }

    for (int i = 0; i < 12; i++)
    {
        if (strlen(myGoods[i].name) <= 6)
        {
            fprintf(fptr1, "%d %s\t\t\t%c%12.2f%10.2f%11.2f\n", myGoods[i].ID, myGoods[i].name, myGoods[i].type, myGoods[i].cost, myGoods[i].tax, myGoods[i].netPrice);
        }
        else if (strlen(myGoods[i].name) <= 10)
        {
            fprintf(fptr1, "%d %s\t\t%c%12.2f%10.2f%11.2f\n", myGoods[i].ID, myGoods[i].name, myGoods[i].type, myGoods[i].cost, myGoods[i].tax, myGoods[i].netPrice);
        }
        else
        {
            fprintf(fptr1, "%d %s\t%c%12.2f%10.2f%11.2f\n", myGoods[i].ID, myGoods[i].name, myGoods[i].type, myGoods[i].cost, myGoods[i].tax, myGoods[i].netPrice);
        }
    }
}

float findTax(char chr, float price)
{
    if (chr == 'A')
    {
        return price * 0.1;
    }
    else if (chr == 'B')
    {
        return price * 0.15;
    }
    else if (chr == 'C')
    {
        return price *0.2;
    }
    else if (chr == 'D')
    {
        return price * 0.4;
    }

    return 0;
}
