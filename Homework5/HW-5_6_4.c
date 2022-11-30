#include <stdio.h>
#include <string.h>

//Nanmanat Varisthanist 6509618200 22
//Group ID: 6

int main()
{
    FILE *file = fopen("Original_list.txt", "r");

    char name_list[6][100];
    char age[6][3];
    int i = 0, l = 0;

    while(fgets(name_list[i], 100, file))
    {
        for (int j = 0; j < strlen(name_list[i]); j++)
        {
            if (name_list[i][j] == ' ' && name_list[i][j - 1] != ',')
            {
                for (int k = j + 1; k < strlen(name_list[i]); k++)
                {
                    if (name_list[i][k] != '\n')
                    {
                        age[i][l] = name_list[i][k];
                        l++;
                    }
                }
                age[i][2] = '\0';
                name_list[i][j] = '\0';
                l = 0;
                break;
            }
        }
        i++;
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = i; j < 6; j++)
        {
            if(strcmp(name_list[i], name_list[j]) > 0)
            {
                char temp[100];
                char temp_age[3];
                strcpy(temp, name_list[i]);
                strcpy(name_list[i], name_list[j]);
                strcpy(name_list[j], temp);

                strcpy(temp_age, age[i]);
                strcpy(age[i], age[j]);
                strcpy(age[j], temp_age);
            }
        }
    }

    fclose(file);

    file = fopen("Alphabetized_list.txt", "w");

    for (int i = 0; i < 6; i++)
    {
        fprintf(file, "%s ", name_list[i]);
        fprintf(file, "%s\n", age[i]);
    }

    fclose(file);
}
