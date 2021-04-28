#include <stdio.h>

int main()
{
int n = 0, i = 0;
double x = 0, min = 0;

if ((scanf("%d", &n) == 1))
{
for (i = 0; i < n; i++)
{
    if (scanf("%lf", &x) == 1)
    {
        if(i == 0)
        {
            min = x;
        }

        if(x < min)
        {
            min = x;
        }
    }
    else
    {
    printf("Ошибка ввода\n");
    break;
    } 
}
printf("%lf\n",min);
}
else
{
printf("Ошибка ввода\n");
}

return 0;
}