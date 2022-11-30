#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Nanmanat Varisthanist 6509618200 22
//Group ID: 6

int search(char COLOR_CODES[][7], char band[]);

int main()
{
    char COLOR_CODES[10][7] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white"};
    char choice = 'y';

    while (choice == 'y' || choice == 'Y')
    {   
        char band1[10];
        char band2[10];
        char band3[10];

        printf("Enter the colors of the resistor's three bands, beginning with the band nearest the end. Type the colors i lowercase leters only, NO CAPS.\n");
        printf("Band 1 => ");
        scanf("%s", band1);
        printf("Band 2 => ");
        scanf("%s", band2);
        printf("Band 3 => ");
        scanf("%s", band3);

        int ohms;

        while (true)
        {
            if(search(COLOR_CODES, band1) == -1)
            {
                printf("Invalid color: %s\n", band1);
                break;
            }
            else if(search(COLOR_CODES, band2) == -1)
            {
                printf("Invalid color: %s\n", band2);
                break;
            }
            else if(search(COLOR_CODES, band3) == -1)
            {
                printf("Invalid color: %s\n", band3);
                break;
            }

            ohms = (search(COLOR_CODES, band1)) * 10;
            ohms += search(COLOR_CODES, band2);

            int time = search(COLOR_CODES, band3);

            if (time == 0)
            {
                printf("Resistance value: %d kilo-ohms\n", ohms);
            }
            else
            {
                for(int i = 0; i < time; i++)
                {
                    ohms *= 10;
                }
                printf("Resistance value: %d kilo-ohms\n", ohms/1000);
            }
            break;
        }

        do
        {
            printf("Do you want to decode another resistor?\n");
            printf("=> ");
            scanf(" %c", &choice);
        } while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
    }
}

int search(char COLOR_CODES[][7], char band[])
{
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(band, COLOR_CODES[i]) == 0)
        {
            return i;
        }
    }

    return -1;
}