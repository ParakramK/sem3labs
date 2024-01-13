#include <stdio.h>
#include <math.h>

#define f(x) pow(x,3) -4*x -9
#define e 0.0001

double falsePosition(double a, double b, int max_iter) {
    double fa = f(a);
    double fb = f(b);
    double c, fc;
    int iter = 0;
    printf("\nIteration\t a\t\t b\t\t c\t\t f(c)\n");
    do {
        c = (a * fb - b * fa) / (fb - fa);
        fc = f(c);
        printf("%d\t\t %f\t %f\t %f\t %f\n", iter, a, b, c, fc);
        if (fc * fa > 0) {
            a = c;
            fa = fc;
        } else {
            b = c;
            fb = fc;
        }
        iter++;
    } while (fabs(fc) > e && iter < max_iter);
    return c;
}

int main() {
    double x, y;
    do {
        printf("enter the initial guess x and y: ");
        scanf("%lf%lf", &x, &y);
        if (f(x) * f(y) < 0) {
            break;
        } else {
            printf("wrong guess try again");
        }
    } while (1);
    double root = falsePosition(x, y, 100);
    printf("The root is: %f\n", root);
    return 0;
}