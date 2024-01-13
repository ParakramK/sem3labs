#include<stdio.h>
#include<math.h>
#define EPSILON 0.000001 //define your error here
double f(double x) {
    // function here
    return x * log10(x) - 1.2;
}
double f_prime(double x) {
    // derivative of your function here
    return 0.43429 + log10(x);
}
double newton_raphson(double x) {
    double x_next = x;
    double fx, fpx;
    int iter = 1;
    printf("iter\tx\t\tf(x)\n");
    while (1) {
        fx = f(x_next);
        fpx = f_prime(x_next);
        printf("%d\t%lf\t%lf\n", iter, x_next, fx);
        if (fabs(fx) < EPSILON) {
            break;
        }
        x_next = x_next - fx / fpx;
        iter++;
    }
    return x_next;
}
int main() {
    double x;
    printf("Enter initial guess x: ");
    scanf("%lf", &x);
    printf("The root is: %lf\n", newton_raphson(x));
    return 0;
}