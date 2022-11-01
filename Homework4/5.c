#include <stdio.h>
#include <stdbool.h>

//Nanmanat Varisthanist 6509618200

int get_problem();
void get2_pt();
void get_pt_slope();
float *slope_intcpt_from2_pt(float x1, float y1, float x2, float y2);
float intcpt_from_pt_slope(float x1, float y1, float slope);
void display2_pt(float x1, float y1, float x2, float y2);
void display_pt_slope(float x1, float y1, float slope);
void display_slope_intcpt(float slope, float b);

float answer[2];

int main()
{
    char another = 'Y';

    while(true)
    {
        if (another == 'Y')
        {
            int choice = get_problem();
            if (choice == 1)
            {
                get2_pt();
            }
            else if (choice == 2)
            {
                get_pt_slope();
            }
            printf("Do another conversion (Y or N) ");
            scanf(" %c", &another);
        }
        else if(another == 'N')
        {
            return 0;
        }
        else
        {
            printf("Do another conversion (Y or N) ");
            scanf(" %c", &another);
        }
    }
}

int get_problem()
{
    int choice;
    printf("Select the form that you would like to convert to slope_intercept form\n");
    printf("\t1) Two-point form (you know two points on the line)\n");
    printf("\t2) Point-slope form (you know the line's slope and one point\n");

    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
    } while (choice != 1 && choice != 2);

    return choice;
}

void get2_pt()
{
    float x1, y1, x2, y2;
    printf("Enter the x-y coordinates of the first point: ");
    scanf("%f %f", &x1, &y1);
    printf("Enter the x-y coordinates of the second point: ");
    scanf("%f %f", &x2, &y2);

    float * answer;

    answer = slope_intcpt_from2_pt(x1, y1, x2, y2);

    display2_pt(x1, y1, x2, y2);
    display_slope_intcpt(answer[0], answer[1]);
}

void get_pt_slope()
{
    float x1, y1;
    float slope;
    printf("Enter the slope: ");
    scanf("%f", &slope);
    printf("Enter the x-y coordinates of the point: ");
    scanf("%f %f", &x1, &y1);
    float b = intcpt_from_pt_slope(x1, y1, slope);

    display_pt_slope(x1, y1, slope);
    display_slope_intcpt(slope, b);
}

float *slope_intcpt_from2_pt(float x1, float y1, float x2, float y2)
{
    answer[0] = (y2 - y1) / (x2 - x1);

    answer[1] = answer[0] * (0 - x1) + y1;

    return answer;
}

float intcpt_from_pt_slope(float x1, float y1, float slope)
{
    float b;

    b = slope * (0 - x1) + y1;

    return b;
}

void display2_pt(float x1, float y1, float x2, float y2)
{
    printf("Two-point form\n");
    printf("\t\t(%.2f - %.2f)\n", y2, y1);
    printf("\tm = \t--------------\n");
    printf("\t\t(%.2f - %.2f)\n", x2, x1);
}

void display_pt_slope(float x1, float y1, float slope)
{
    printf("Point-slope form\n");
    printf("\ty - %.2f = %.2f(x - %.2f)\n", y1, slope, x1);
}

void display_slope_intcpt(float slope, float b)
{
    printf("Slope-intercept form\n");
    printf("\ty = %.2fx + %.2f\n", slope, b);
}