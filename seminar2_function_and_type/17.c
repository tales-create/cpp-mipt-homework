#include <stdio.h>
#include <math.h>

int main()
{
    double x1, y1, r1;
    double x2, y2, r2;

    if (scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2) == 6)
    {
        double dx = x2 - x1;
        double dy = y2 - y1;
        double d = sqrt(dx * dx + dy * dy);

        double sum_r = r1 + r2;
        double diff_r = fabs(r1 - r2);
        double eps = 1e-5;


        if (fabs(d - sum_r) < eps || fabs(d - diff_r) < eps)
        {
            printf("Touch\n");
        }

        else if (d > sum_r || d < diff_r)
        {
            printf("Do not intersect\n");
        }

        else
        {
            printf("Intersect\n");
        }
    }

    return 0;
}