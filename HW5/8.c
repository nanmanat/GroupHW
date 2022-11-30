#include <stdio.h>
#define MAXLEN 100
typedef struct
{
    char id[MAXLEN];
    char name[MAXLEN];
    float score;
}grade;
int main()
{
    grade student[MAXLEN];
    
    FILE *fptr;
    FILE *fptr1;
    fptr = fopen("studentScore.txt","r");
    fptr1 = fopen("studentGradeReport.txt","w");
    
    
    int i, count = 0 ;
    float min , max , mean ;
    
    
    while (fscanf(fptr,"%s %s %f",student[count].id,student[count].name,&(student[count].score)) != EOF)
    {
       /* printf("%s %s %.2f\n",student[count].id,student[count].name,student[count].score);
        count++;*/
        if (student[count].score < 50 )
        {
            fprintf(fptr1, "Student ID: %s, Name: %s,\tScore %.2f \tgrade: F\n",student[count].id,student[count].name,student[count].score);
            count++;
        }
        else if (student[count].score >= 50 && student[count].score < 60)
        {
            fprintf(fptr1, "Student ID: %s, Name: %s,\tScore %.2f \tgrade: D\n",student[count].id,student[count].name,student[count].score);
            count++;
        }
        else if (student[count].score >= 60 && student[count].score < 70)
        {
            fprintf(fptr1, "Student ID: %s, Name: %s,\tScore %.2f \tgrade: C\n",student[count].id,student[count].name,student[count].score);
            count++;
        }
        else if (student[count].score >= 70 && student[count].score < 80)
        {
            fprintf(fptr1, "Student ID: %s, Name: %s,\tScore %.2f \tgrade: B\n",student[count].id,student[count].name,student[count].score);
            count++;
        }
        else if (student[count].score >= 80)
        {
            fprintf(fptr1, "Student ID: %s, Name: %s,\tScore %.2f \tgrade: A\n",student[count].id,student[count].name,student[count].score);
            count++;
        }
	}
	
    for(i = 0; i < count; i++)
	{
		mean = mean + student[i].score;
		if(min > student[i].score || min == 0)
		{
			min = student[i].score;
		}
		if(max < student[i].score);
		{
			max = student[i].score;
		}
	}
	mean = mean / count;
	fprintf(fptr1,"Min score ; %.2f\n",min);
	fprintf(fptr1,"Max score ; %.2f\n",max);
	fprintf(fptr1,"Mean score ; %.2f\n",mean);
    
}