#include <stdio.h>
#include <math.h>

double gamma(double x)
{
    const double step = 1e-2;
    const double eps = 1e-10;

    double sum = 0.0;
    double t = 0.0;

    double f_t = pow(t, x - 1.0) * exp(-t);

    while (1)
    {
        double t_next = t + step;
        double f_next = pow(t_next, x - 1.0) * exp(-t_next);

        double area = (f_t + f_next) / 2.0 * step;

        if (area <= eps)
        {
            break;
        }

        sum += area;
        t = t_next;
        f_t = f_next;
    }

    return sum;
}

int main()
{
    double x;
    if (scanf("%lf", &x) == 1)
    {
        printf("%g\n", gamma(x));
    }
    return 0;
}