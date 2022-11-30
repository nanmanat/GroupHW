#include <stdio.h>
#include <string.h>

//Nanmanat Varisthanist 6509618200

typedef struct
{
    char id[15];
    char name[10];
    float score;
    char grade;
} studentScores;

int main()
{
    FILE *file = fopen("studentScores.txt", "r");

    studentScores data[10];

    int i = 0;

    while(fscanf(file, "%s %s %f", data[i].id, data[i].name, &data[i].score) != EOF)
    {
        i++;
    }

    float min = data[0].score;
    float max = data[0].score;
    float average = 0;

    for (int i = 0; i < 10; i++)
    {
        if (min > data[i].score)
        {
            min = data[i].score;
        }
        if (max < data[i].score)
        {
            max = data[i].score;
        }

        if (data[i].score >= 80)
        {
            data[i].grade = 'A';
        }
        else if (data[i].score >= 70)
        {
            data[i].grade = 'B';
        }
        else if (data[i].score >= 60)
        {
            data[i].grade = 'C';
        }
        else if (data[i].score >= 50)
        {
            data[i].grade = 'D';
        }
        else if (data[i].score < 50)
        {
            data[i].grade = 'F';
        }

        average = data[i].score;
    }

    average /= 10;

    fclose(file);

    file = fopen("studentGradeReport.txt", "w");

    for (int i = 0; i < 10; i++)
    {
        fprintf(file, "Student ID: %s, Name: %s,\tScore %.2f, Grade: %c\n", data[i].id, data[i].name, data[i].score, data[i].grade);
    }

    fprintf(file, "Minimum Score: %.2f\nMaximum Score: %.2f\nAverage Score: %.2f", min, max, average);

    fclose(file);
}
