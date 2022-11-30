#include <stdio.h>
#include <string.h>

//Nanmanat Varisthanist 6509618200 22
//Teerajet Chanpha 6509618184 20
//Group ID: 6

int recursive(int number);

int main()
{
    int number;

    scanf("%d", &number);

    printf("Answer: %d\n", recursive(number));
}

int recursive(int number)
{
    if (number <= 0)
    {
        return 0;
    }
    else
    {
        return recursive(number - 1) + 2;
    }
}
