#include <stdio.h>
typedef struct
{
    char id[100];
    char name[100];
    float score[100];
}grade;
int main()
{
    FILE *fptr;
    FILE *fptr1;
    fptr = fopen("studentScore.txt","r");
    fptr1 = fopen("studentGradeReport.txt","w");
    
    int i = 0 ;
    grade student;
    
     while (fscanf(fptr, "%s %s %f",student.id[i],student.name[i],&student.score[i]) != EOF)
     {
        if (student.score[i] < 50 )
        {
            fprintf(fptr1, "Student ID: %s, Name: %s, Score %.2f grade: F",student.id[i],student.name[i],student.score[i]);
            i++;
        }
        if (student.score[i] >= 50 && student.score[i] < 60)
        {
            fprintf(fptr1, "Student ID: %s, Name: %s, Score %.2f grade: D",student.id[i],student.name[i],student.score[i]);
            i++;
        }
        if (student.score[i] >= 60 && student.score[i] < 70)
        {
            fprintf(fptr1, "Student ID: %s, Name: %s, Score %.2f grade: C",student.id[i],student.name[i],student.score[i]);
            i++;
        }if (student.score[i] >= 70 && student.score[i] < 80)
        {
            fprintf(fptr1, "Student ID: %s, Name: %s, Score %.2f grade: B",student.id[i],student.name[i],student.score[i]);
            i++;
        }
        if (student.score[i] >= 50)
        {
            fprintf(fptr1, "Student ID: %s, Name: %s, Score %.2f grade: A",student.id[i],student.name[i],student.score[i]);
            i++;
        }
        
     }
    



}