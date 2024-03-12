#include <stdio.h>
// Function defining the ODE: dy/dx = f(x, y)
double f(double x, double y) {
    return x + y;
}
// RK4 method implementation
void rk4Method(double x0, double y0, double h, double xn) {
    double x = x0;
    double y = y0;
    printf("x\t\t y\n");
    while (x <= xn) {
        printf("%lf\t %lf\n", x, y);
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2.0, y + k1 / 2.0);
        double k3 = h * f(x + h / 2.0, y + k2 / 2.0);
        double k4 = h * f(x + h, y + k3);
        y = y + (k1 + 2.0 * (k2 + k3) + k4) / 6.0;
        x = x + h;
    }
}
int main() {
    double x0 = 0.0;
    double y0 = 1.0;
    double h = 0.1;
    double xn = 1;
    rk4Method(x0, y0, h, xn);
    return 0;
}
