#include <stdio.h>
#include <stdlib.h>

const char *MONTHS[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

const int MONTH_WIDTH = 9;
const int VALUE_WIDTH = 6;
const int DECIMAL_WIDTH = 2;
const int SUMMRAY_TITLE_WIDTH = 14;

float average(float*, int);

int main()
{
    float values[12];
    char in[32];
    float avg = 0;
    int min = 0;
    int max = 0;

    FILE* file = fopen("input.txt", "r");

    printf("2022 Monthly Sales Report\n");
    printf("%-*s %-*s\n", MONTH_WIDTH, "Month", VALUE_WIDTH + 2 + DECIMAL_WIDTH, "Sales");

    for(int i = 0; i < 12; i++)
    {
        if(!fgets(in, 32, file))
        {
            printf("Error reading file!");
            return -1;
        }
        values[i] = atof(in);
        min = values[i] < values[min] ? i : min;
        max = values[i] > values[max] ? i : max;
        avg += values[i];
        printf("%-*s $%*.*f\n", MONTH_WIDTH, MONTHS[i], VALUE_WIDTH, DECIMAL_WIDTH, values[i]);
    }

    printf("\nYear Summary\n");

    printf("%-*s $%*.*f (%s)\n", SUMMRAY_TITLE_WIDTH, "Minimum Sales", VALUE_WIDTH, DECIMAL_WIDTH, values[min], MONTHS[min]);
    printf("%-*s $%*.*f (%s)\n", SUMMRAY_TITLE_WIDTH, "Maximum Sales", VALUE_WIDTH, DECIMAL_WIDTH, values[max], MONTHS[max]);
    printf("%-*s $%*.*f\n", SUMMRAY_TITLE_WIDTH, "Average", VALUE_WIDTH, DECIMAL_WIDTH, avg/12);

    printf("\nSix-Month Moving Average Report\n");

    for(int i = 0; i + 5 < 12; i++)
    {
        printf("%-*s - %-*s $%*.*f\n", MONTH_WIDTH, MONTHS[i], MONTH_WIDTH, MONTHS[i+5], VALUE_WIDTH, DECIMAL_WIDTH, average(values+i, 6));
    }

    printf("\nSales Report (Highest to Lowest)\n");

    int used[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for(int i = 0; i < 12; i++)
    {
        max = -1;
        for(int j = 0; j < 12; j++)
        {
            if(used[j])
            {
                continue;
            }

            if(max == -1)
            {
                max = j;
                continue;
            }

            max = values[j] > values[max] ? j : max;
        }

        used[max] = 1;
        printf("%-*s $%*.*f\n", MONTH_WIDTH, MONTHS[max], VALUE_WIDTH, DECIMAL_WIDTH, values[max]);
    }
}

float average(float* values, int count)
{
    float out = 0;

    for(int i = 0; i < count; i++)
    {
        out += *(values + i);
    }

    return out / count;
}