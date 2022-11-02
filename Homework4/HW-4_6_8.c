#include <stdio.h>
#include <stdbool.h>

//Nanmanat Varisthanist 6509618200 22
//Group ID: 6

int isMagic(int size, int arr[size][size]);

int main()
{
    int size;
    char more = 'y';
    while (true)
    {
        if (more == 'y' || more == 'Y')
        {
            printf("Please enter size of the square (3-9): ");
            scanf("%d", &size);
                
            while(size < 3 || size > 9)
            {
                printf("Invalid Input!!\n\n");

                printf("Please enter size of the square (3-9): ");
                scanf("%d", &size);
            }

            int arr[size][size];

            printf("Enter nubmers 1 to %d into your square:\n", size * size);

            for(int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    scanf("%d", &arr[i][j]);
                }
            }

            int magic = isMagic(size, arr);
            
            if (magic != 0)
            {
                printf("Congratulations!! Your square is a magic square.\n"); 
                printf("The magic constant of this square is %d\n\n", magic);
                printf("Try more <y/n>? ");
                scanf(" %c", &more);
            }
            else
            {
                printf("Your square is not a magic square!!\n\n");
                printf("Try more <y/n>? ");
                scanf(" %c", &more);
            }
        }
        else if (more == 'n' || more == 'N')
        {
            printf("Bye\n");
            return 0;
        }
        else
        {
            printf("Try more <y/n>? ");
            scanf(" %c", &more);
        }
        
    }
}

int isMagic(int size, int arr[size][size])
{
    int constant = 0;
    int horizontal = 0, vertical = 0;
    int left = 0, right = 0;

    for (int j = 0; j < size; j++)
    {
        constant += arr[0][j];
    }

    for(int x = 0; x < size; x++)
    {
        for(int y = 0; y < size; y++)
        {
            for(int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (i != x && j != y)
                    {
                        if(arr[i][j] == arr[x][y])
                        {
                            return 0;
                        }
                    }
                    //Calculate horizontal and vertical
                    horizontal += arr[i][j];
                    vertical += arr[j][i];
                }

                if (horizontal != constant || vertical != constant)
                {
                    return 0;
                }
                horizontal = 0;
                vertical = 0;
            }
        }
    }


    //Calculate diagonal
    for (int i = 0; i < size; i++)
    {
        left += arr[i][i];
        right += arr[i][(size - 1) - i];
    }

    if (left != constant || right != constant)
    {
        return 0;
    }

    return constant;
}