#include <stdio.h>
int recursive(int number);

int main()
{
    int number,sum;
    
    scanf("%d", &number);
    sum = recursive(number);
    printf("Result: %d", sum);
}

int recursive(int number)
{
    if (number <= 0)
    {
        return 0;
    }
    else if (number > 0)
    {
        return recursive(number - 1) + 2;
    }
}
