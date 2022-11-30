#include <stdio.h>
#include <string.h>

//Nanmanat Varisthanist 6509618200

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
