#include <stdio.h>
#include <stdbool.h>

//Nanmanat Varisthanist 6509618200 22
//Teerajet Chanpha 6509618184 20
//Group ID: 6

int odd(char barcode[]);
int even(char barcode[]);
bool checkDigit(int evenSum, char barcode[]);

int main()
{
    int oddSum, evenSum;
    char barcode[12];

    printf("Enter you barcode: ");
    for(int i = 0; i < 12; i++)
    {
        scanf("%c", &barcode[i]);
    }

    oddSum = odd(barcode);
    evenSum = even(barcode) + oddSum;

    if(checkDigit(evenSum, barcode))
    {
        printf("Result is validated\n");
    }
    else
    {
        printf("Result is error in barcode\n");
    }
}

int odd(char barcode[])
{
    int sum = 0;
    for (int i = 1; i <= 11; i++)
    {
        if (i % 2 != 0)
        {
            sum += barcode[i - 1] - 48;
        }
    }
    return sum * 3;
}

int even(char barcode[])
{
    int sum = 0;
    for (int i = 1; i <= 11; i++)
    {
        if (i % 2 == 0)
        {
            sum += barcode[i - 1] - 48;
        }
    }
    return sum;
}

bool checkDigit(int evenSum, char barcode[])
{
    int lastDigit = evenSum % 10;
    if (lastDigit != 0)
    {
        lastDigit = 10 - (evenSum % 10);
    }
    if (lastDigit == barcode[11] - 48)
    {
        return true;
    }
    else
    {
        return false;
    }
    return true;
}