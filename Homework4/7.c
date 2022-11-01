#include <stdio.h>
#include <stdbool.h>

//Nanmanat Varisthanist 6509618200]

float findMax(float vector[]);
float findMin(float vector[]);
float findSum(float vector[]);
void sortVector(float *vector);

int main()
{
    float vector[7];
    

    for (int i = 0; i < 7; i++)
    {
        printf("Enter 7 numbers into the vector: ");
        scanf("%f", &vector[i]);
    }

    while(true)
    {
        char choice;

        printf("################## MENU ##################\n");
        printf("A. Find the maximum number in the vector\n");
        printf("B. Find the minimum number in the vector\n");
        printf("C. Find the total of numbers in the vector\n");
        printf("D. Sort numbers in the vector in the ascending order\n");
        printf("Q. Quit Program\n");

        printf("Enter your choice <A, B, C, D or Q> : ");
        scanf(" %c", &choice);

        while(choice != 'A' && choice != 'a' && choice != 'B' && choice != 'b' && choice != 'C' && choice != 'c' && choice != 'D' && choice != 'd' && choice != 'Q' && choice != 'q')
        {
            printf("Invalid Choice!!\n");
            printf("Enter your choice <A, B, C, D or Q> : ");
            scanf(" %c", &choice);
        }

        if (choice == 'A' || choice == 'a')
        {
            printf("------------------------------------------------\n");
            printf("The maximum number in the vector is %.2f\n", findMax(vector));
            printf("------------------------------------------------\n");
        }
        else if (choice == 'B' || choice == 'b')
        {
            printf("------------------------------------------------\n");
            printf("The minimum number in the vector is %.2f\n", findMin(vector));
            printf("------------------------------------------------\n");
        }
        else if (choice == 'C' || choice == 'c')
        {
            printf("------------------------------------------------\n");
            printf("The total of numbers in the vector is %.2f\n", findSum(vector));
            printf("------------------------------------------------\n");
        }
        else if (choice == 'D' || choice == 'd')
        {
            sortVector(vector);
            printf("------------------------------------------------\n");
            printf("The total of numbers in the vector is ");
            for (int i = 0; i < 7; i++)
            {
                printf("%.2f ", vector[i]);
            }
            printf("\n");
            printf("------------------------------------------------\n");
        }
        else if (choice == 'Q' || choice == 'q')
        {
            printf("------------------------------------------------\n");
            printf("Bye !!!\n");
            printf("------------------------------------------------\n");
            return 0;
        }
    }
}

float findMax(float vector[])
{
    float max = vector[0];

    for (int i = 1; i < 7; i++)
    {
        if (vector[i] > max)
        {
            max = vector[i];
        }
    }

    return max;
}

float findMin(float vector[])
{
    float min = vector[0];

    for (int i = 1; i < 7; i++)
    {
        if (vector[i] < min)
        {
            min = vector[i];
        }
    }

    return min;
}

float findSum(float vector[])
{
    float sum = 0;
    for (int i = 0; i < 7; i++)
    {
        sum += vector[i];
    }

    return sum;
}

void sortVector(float *vector)
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = i; j < 7; j++)
        {
            if (vector[j] < vector[i])
            {
                float temp = vector[i];
                vector[i] = vector[j];
                vector[j] = temp;
            }
        }
    }
}
