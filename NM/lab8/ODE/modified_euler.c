#include <stdio.h>

// Function defining the ODE: dy/dx = f(x, y)
double f(double x, double y) {
    return x + y;
}

void modifiedEulerMethod(double x0, double y0, double h, double xn) {
    double x = x0;
    double y = y0;
    printf("x\t\t y\n");
    while (x <= xn) {
        printf("%lf\t %lf\n", x, y);
        double slope1 = f(x, y);
        double slope2 = f(x + h, y + h * slope1);
        y = y + (h / 2.0) * (slope1 + slope2);
        x = x + h;
    }
}
int main() {
    double x0 = 0.0;
    double y0 = 1.0;
    double h = 0.1;
    double xn = 1.0;
    modifiedEulerMethod(x0, y0, h, xn);
    return 0;
}
