#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fptr;
    FILE *fptr1;
    
    fptr = fopen ("Original_list.txt","r");
    fptr1 = fopen ("Alphabetized.txt","w");
    
    
    char name[12][1000];
    int age[1000];
    int i = 0, j = 0 ;
    char temp[1000];
    int length = 6;
    
   /* while (fscanf(fptr, "%s %s %d",name[i],name[j],&age[i]) != EOF)
    {
        fprintf(fptr1,"%s %s %d\n",name[i],name[j],age[i]);
        i++;
    }*/
    while (fscanf(fptr1, "%s %s %d",name[i],name[j],&age[i]) != EOF)
    {
        for (int i = 0; i < 12; i++)
        {
            for (int j  = i + 1 ; i < 12 ; j++)
            {
                if (strcmp(name[i],name[j])>0)
                {
                    strcpy(temp,name[i]);
                    strcpy(name[i],name[j]);
                    strcpy(name[j],temp);
                }
            }
            
        }
        fprintf(fptr1,"%s %s %d\n",name[i],name[j],age[i]);
        i++;
    }
    

    
}