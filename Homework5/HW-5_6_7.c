#include <stdio.h>
#include <string.h>

//Nanmanat Varisthanist 6509618200 22
//Group ID: 6

typedef struct
{
    int site_id_num;
    int wind_speed;
    int day_of_month;
    int temperature;
} measured_data_t;

int main()
{
    FILE *file = fopen("data.txt", "r");
    int station[5] = {0, 0, 0, 0, 0};
    int station_temp[5] = {0, 0, 0, 0, 0};

    measured_data_t data[70];

    int i = 0;

    while(fscanf(file, "%d %d %d %d", &data[i].site_id_num, &data[i].day_of_month, &data[i].wind_speed, &data[i].temperature) != EOF)
    {
        i++;
    }

    int min, max;

    for (int j = 0; j < 5; j++)
    {
        min = data[14 * j].temperature;
        max = data[14 * j].temperature;
        for (int i = 14 * j; i < (14 * j) + 14; i++)
        {
            if (min > data[i].temperature)
            {
                min = data[i].temperature;
            }
            if (max < data[i].temperature)
            {
                max = data[i].temperature;
            }
            station[j] += data[i].wind_speed;
        }
        station_temp[j] = max - min;
        station[j] /= 14;
    }

    int wind_speed = station[0];
    int temperature = station_temp[0];
    int index_speed = 0;
    int index_temp = 0;
    for (int i = 0; i < 5; i++)
    {
        if (wind_speed < station[i])
        {
            wind_speed = station[i];
            index_speed = i;
        }

        if (temperature < station_temp[i])
        {
            temperature = station_temp[i];
            index_temp = i;
        }
        
    }

    printf("%d\n%d\n", data[index_speed * 14].site_id_num, data[index_temp * 14].site_id_num);

    fclose(file);
}
