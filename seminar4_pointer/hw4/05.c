#include <stdio.h>
#include <math.h>

int solve_quadratic(double a, double b, double c, double* px1, double* px2) {
    double eps = 1e-10;


    if (fabs(a) < eps) {
        if (fabs(b) < eps) {
            return 0;
        }
        if (px1 != NULL) {
            *px1 = -c / b;
        }
        return 1;
    }

    double d = b * b - 4 * a * c;

    if (d < -eps) {
        return 0;
    } else if (fabs(d) <= eps) {
        if (px1 != NULL) {
            *px1 = -b / (2 * a);
        }
        return 1;
    } else {
        double sqrt_d = sqrt(d);
        if (px1 != NULL) {
            *px1 = (-b + sqrt_d) / (2 * a);
        }
        if (px2 != NULL) {
            *px2 = (-b - sqrt_d) / (2 * a);
        }
        return 2;
    }
}

//int main(void) {
    double x1 = 0, x2 = 0;
    int roots = solve_quadratic(1.0, -5.0, 6.0, &x1, &x2);
    printf("Количество корней: %d\n", roots);
    if (roots == 1) printf("x1 = %f\n", x1);
    if (roots == 2) printf("x1 = %f, x2 = %f\n", x1, x2);

    return 0;
}