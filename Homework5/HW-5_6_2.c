#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//Nanmanat Varisthanist 6509618200 22
//Group ID: 6

void fact_cal(char *answer, int number);
int cal_digit(int number);

int main()
{
    int number;
    char answer[100];

    printf("Enter an integer between 0 and 9 or -1 ot quit => ");
    scanf("%d", &number);
    if (number == -1)
    {
        return 0;
    }
    
    while(number < 0 || number > 9)
    {
        if (number == -1)
        {
            return 0;
        }
        printf("Invalid entry\n");
        printf("Enter an integer between 0 and 9 or -1 ot quit => ");
        scanf("%d", &number);
    }

    while (number != -1)
    {

        fact_cal(answer, number);

        printf("%s\n", answer);

        printf("Enter an integer between 0 and 9 or -1 ot quit => ");
        scanf("%d", &number);

        if (number == -1)
        {
            return 0;
        }
        
        while(number < 0 || number > 9)
        {
            if (number == -1)
            {
                return 0;
            }
            printf("Invalid entry\n");
            printf("Enter an integer between 0 and 9 or -1 ot quit => ");
            scanf("%d", &number);
        }
    }
}

void fact_cal(char *answer, int number)
{
    int product = 1;
    
    answer[0] = '*';
    answer[1] = ' ';
    answer[2] = number + '0';
    answer[3] = '!';
    answer[4] = ' ';
    answer[5] = '=';
    answer[6] = ' ';

    int minus = 0;

    if (number == 0)
    {
        answer[7] = '1';
        answer[8] = ' ';
        answer[9] = '*';
        answer[10] = '\0';
        return;
    }

    for (int i = 0; i < 100; i+=4)
    {
        if (number - minus != 1)
        {
            answer[7 + i] = number - minus + '0';
            answer[7 + i + 1] = ' ';
            answer[7 + i + 2] = 'x';
            answer[7 + i + 3] = ' ';
            product *= number - minus;
            minus++;
        }
        else
        {
            answer[7 + i] = number - minus + '0';
            answer[7 + i + 1] = ' ';
            answer[7 + i + 2] = '=';
            answer[7 + i + 3] = ' ';
            product *= number - minus;
            int digit = cal_digit(product);
            int multiplier = pow(10, digit);
            for (int j = 0; j <= digit; j++)
            {
                answer[7 + i + 4 + j] = ((product / multiplier) % 10) + '0';
                multiplier /= 10;
            }
            answer[7 + i + 4 + digit + 1] = ' ';
            answer[7 + i + 4 + digit + 2] = '*';
            answer[7 + i + 4 + digit + 3] = '\0';
            break;
        }
    }
}

int cal_digit(int number)
{
    int i = 0;
    while (true)
    {
        number /= 10;
        if (number == 0)
        {
            return i;
        }
        i++;
    }
}