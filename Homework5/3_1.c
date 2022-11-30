#include <stdio.h>
#include <string.h>

//Nanmanat Varisthanist 6509618200

int hydroxide(char *WORD);

int main()
{
    char WORD[6][7] = {"KOH", "H2O2", "NaCl", "NaOH", "C9H8O4", "MgOH"};

    for (int i = 0; i < 6; i++)
    {
        if (hydroxide(WORD[i]) == 1)
        {
            printf("%s\n", WORD[i]);
        }
    }

}

int hydroxide(char *WORD)
{
    if(WORD[strlen(WORD) - 1] == 'H' && WORD[strlen(WORD) - 2] == 'O')
    {
        return 1;
    }
    return 0;
}
