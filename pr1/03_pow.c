#include <stdio.h>
#include <math.h>

int main()
{
    long double x, y;
    if (scanf("%Lf%Lf", &x, &y) == 2)
    {
        printf("%Lf\n", powl(x, y));
    }
    else
    {
        printf("Ошибка во вводе данных\n");
    }

    return 0;
}