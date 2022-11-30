#include <stdio.h>
#include <string.h>

//Nanmanat Varisthanist 6509618200

int main()
{
    char WORD[9][10] = {"chair", "dairy", "boss", "circus", "fly", "dog", "church", "clue", "dish"};

    for (int i = 0; i < 9; i++)
    {
        if (WORD[i][strlen(WORD[i]) - 1] == 'y')
        {
            WORD[i][strlen(WORD[i]) - 1] = 'i';
            WORD[i][strlen(WORD[i])] = 'e';
            strcat(WORD[i], "s");
        }
        else if (WORD[i][strlen(WORD[i]) - 1] == 's' || WORD[i][strlen(WORD[i]) - 1] == 'h')
        {
            WORD[i][strlen(WORD[i])] = 'e';
            strcat(WORD[i], "s");
        }
        else
        {
            WORD[i][strlen(WORD[i])] = 's';
            strcat(WORD[i], "\0");
        }
    }

    for (int i = 0; i < 9; i++)
    {
        printf("%s\n", WORD[i]);
    }
}
