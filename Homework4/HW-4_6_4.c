#include <stdio.h>
#include <stdbool.h>

//Nanmanat Varisthanist 6509618200 22
//Group ID: 6

void mergeArray(int size, float firstArray[], float secondArray[], int firstArraySize, int secondArraySize, float *finalArray);

int main()
{
    int firstArraySize, secondArraySize, finalArraySize;
    printf("Enter length of first array: ");
    scanf("%d", &firstArraySize);
    float firstArray[firstArraySize];
    printf("Enter %d numbers\n", firstArraySize);
    for (int i = 0; i < firstArraySize; i++)
    {
        scanf("%f", &firstArray[i]);
    }

    printf("Enter length of Second array: ");
    scanf("%d", &secondArraySize);
    float secondArray[secondArraySize];
    printf("Enter %d numbers\n", secondArraySize);
    for (int i = 0; i < secondArraySize; i++)
    {
        scanf("%f", &secondArray[i]);
    }

    if (firstArraySize < secondArraySize)
    {
        finalArraySize = secondArraySize + firstArraySize;
        for (int i = 0; i < firstArraySize; i++)
        {
            for (int j = 0; j < secondArraySize; j++)
            {
                if (firstArray[i] == secondArray[j])
                {
                    finalArraySize--;
                }
            }
        }
    }
    else
    {
        finalArraySize = secondArraySize + firstArraySize;
        for (int i = 0; i < secondArraySize; i++)
        {
            for (int j = 0; j < firstArraySize; j++)
            {
                if (secondArray[i] == firstArray[j])
                {
                    finalArraySize--;
                }
            }
        }
    }

    float finalArray[finalArraySize];

    mergeArray(finalArraySize, firstArray, secondArray, firstArraySize, secondArraySize, finalArray);

    for (int i = 0; i < finalArraySize; i++)
    {
        for (int j = i; j < finalArraySize; j++)
        {
            if (finalArray[i] > finalArray[j])
            {
                float temp = finalArray[i];
                finalArray[i] = finalArray[j];
                finalArray[j] = temp;
            }
        }
    }

    for (int i = 0; i < finalArraySize; i++)
    {
        printf("%.1f ", finalArray[i]);
    }
    printf("\n");
}

void mergeArray(int size, float firstArray[], float secondArray[], int firstArraySize, int secondArraySize, float *finalArray)
{

    bool duplicate = false;

    if(secondArraySize > firstArraySize)
    {
        for (int i = 0; i < secondArraySize; i++)
        {
            finalArray[i] = secondArray[i];
        }
        for (int i = 0; i < firstArraySize; i++)
        {
            for (int j = 0; j < secondArraySize; j++)
            {
                if (firstArray[i] == secondArray[j])
                {
                    duplicate = true;
                }
            }
            if (!duplicate)
            {
                finalArray[secondArraySize + i] = firstArray[i];
            }
            duplicate = false;
        }
    }
    else
    {
        for (int i = 0; i < firstArraySize; i++)
        {
            finalArray[i] = firstArray[i];
        }
        for (int i = 0; i < secondArraySize; i++)
        {
            for (int j = 0; j < firstArraySize; j++)
            {
                if (secondArray[i] == firstArray[j])
                {
                    duplicate = true;
                }
            }
            if (!duplicate)
            {
                finalArray[(firstArraySize - 1) + i] = secondArray[i];
            }
            duplicate = false;
        }
    }
}