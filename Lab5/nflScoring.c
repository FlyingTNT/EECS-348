#include <stdio.h>

void printScores(int);

int main()
{
    int input = -1;

    while(1)
    {
        printf("\nInput 0 or 1 to STOP\n");
        printf("Input an NFL score: ");
        scanf("%d", &input);

        if(input < 2)
        {
            break;
        }

        printScores(input);
    }
}

void printScores(int score)
{
    printf("\nPossible NFL Scores:\n");
    int as;
    int bs;
    int cs;
    int ds;
    int es;
    for(int a = 0; (as = a * 8) <= score; a++)
    {
        for(int b = 0; as + (bs = b * 7) <= score; b++)
        {
            for(int c = 0; as + bs + (cs = c * 6) <= score; c++)
            {
                for(int d = 0; as + bs + cs + (ds = d * 3) <= score; d++)
                {
                    for(int e = 0; as+bs+cs+ds+(es=e*2) <= score; e++)
                    {
                        if(as+bs+cs+ds+es == score)
                        {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", a, b, c, d, e);
                        }
                    }
                }
            }
        }
    }
}