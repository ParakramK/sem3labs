#include <stdio.h>
#include <math.h>

#define f(x) pow(x,3) -4*x -9
#define e 0.0001

float bisMethod(float x0, float x1) {
    float x2, f2;
    int step = 1;
    printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    do {
        float f0 = f(x0);
        x2 = (x0 + x1) / 2;
        f2 = f(x2);
        printf("%d\t\t%f\t%f\t%f\t%f\n", step, x0, x1, x2, f2);
        if (f0 * f2 < 0) {
            x1 = x2;
        } else {
            x0 = x2;
        }
        step++;
    } while (fabs(f2) > e);
    return x2;
}

int main() {
    float x0, x1;
    do {
        printf("\nEnter two initial guesses:\n");
        scanf("%f%f", &x0, &x1);

        if (f(x0) * f(x1) > 0.0) {
            printf("Incorrect Initial Guesses.\n");
        }
    } while (f(x0) * f(x1) > 0.0);
    printf("\nRoot is: %f\n", bisMethod(x0, x1));
    return 0;
}
