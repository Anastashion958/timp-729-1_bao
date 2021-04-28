#include <stdio.h>
 
int main()
{
    double a, b;
    if(scanf("%lf%lf", &a, &b) == 2)
    {
        printf("%lf\n", (a + b));
    }
    else
    {
        printf("Ошибка во вводе данных\n");
    }
    
    return 0;
}