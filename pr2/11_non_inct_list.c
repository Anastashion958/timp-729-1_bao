#include <stdio.h>

int main()
{
int n = 0, i = 0;
double x = 0, x1 = 0;
int b = 1;

if ((scanf("%d", &n) == 1))
{
for (i = 0; i < n; i++)
{
    if (scanf("%lf", &x) == 1)
    {
        if(i != 0)
        {
            if(x1 < x)
            {
                b = 0;
                break;
            }
        }
    }
    else
    {
    printf("Ошибка ввода\n");
    break;
    } 
    x1 = x;
}
printf("%d\n", b);
}
else
{
printf("Ошибка ввода\n");
}

return 0;
}