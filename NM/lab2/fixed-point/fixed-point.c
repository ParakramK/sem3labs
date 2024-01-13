#include <stdio.h>
#include <math.h>

#define e 0.0001

double f(double x) {
    // Define your function here
    return pow(x, 3) + pow(x, 2) - 1;
}
double g(double x) {
    // Define your g(x) function here
    return 1 / sqrt(x + 1);
}
int main() {
    double x0, x;
    int iterations;
    printf("Enter initial guess x0: ");
    scanf("%lf", &x0);
    printf("Enter maximum iterations: ");
    scanf("%d", &iterations);
    for (int i = 1; i <= iterations; i++) {
        x = g(x0);
        printf("Iteration %d: x = %lf, f(x) = %lf\n", i, x, f(x));
        if (fabs(x - x0) < e) {
            printf("Converged to solution x = %lf after %d iterations.\n", x, i);
            return 0;
        }
        x0 = x;
    }
    printf("Failed to converge within %d iterations.\n", iterations);
    return 0;
}