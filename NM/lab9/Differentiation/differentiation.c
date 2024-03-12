#include <stdio.h>
// Tabulated data points
double x[] = { 1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6 }; // x values
double y[] = { 7.989, 8.403, 8.781, 9.129, 9.451, 9.750, 10.031 }; // y values


// Numerical differentiation using forward difference
double forwardDifference1storder(int index) {
    double h = x[index + 1] - x[index];
    return (-3 * y[index] + 4 * y[index + 1] - y[index + 2]) / (2 * h);
}
double forwardDifference2ndorder(int index) {
    double h = x[index + 1] - x[index];
    return (2 * y[index] - 5 * y[index + 1] + 4 * y[index + 2] - y[index + 3]) / (h * h);
}


// Numerical differentiation using backward difference
double backwardDifference1storder(int index) {
    double h = x[index + 1] - x[index];
    return (3 * y[index] - 4 * y[index - 1] + y[index - 2]) / (2 * h);
}
double backwardDifference2ndorder(int index) {
    double h = x[index + 1] - x[index];
    return (2 * y[index] - 5 * y[index - 1] + 4 * y[index - 2] - y[index - 3]) / (h * h);
}


// Numerical differentiation using central difference
double centralDifference1storder(int index) {
    double h = x[index + 1] - x[index];
    return (y[index + 1] - y[index - 1]) / (2 * h);
}
double centralDifference2ndorder(int index) {
    double h = x[index + 1] - x[index];
    return (y[index + 1] - 2 * y[index] + y[index - 1]) / (h * h);
}

int main() {
    int index;
    double result;
    printf("Enter the index to find derivative of:");
    scanf("%d", &index);
    if (index == 0 || 1 || 2) {
        result = forwardDifference1storder(index);
        printf("Numerical Differentiation 1st order: %f\n", result);
        result = forwardDifference2ndorder(index);
        printf("Numerical Differentiation 2nd order: %f\n", result);
    } else if (index == 4 || 5 || 6) {
        result = backwardDifference1storder(index);
        printf("Numerical Differentiation 1st order: %f\n", result);
        result = backwardDifference2ndorder(index);
        printf("Numerical Differentiation 2nd order: %f\n", result);
    } else {
        result = centralDifference1storder(index);
        printf("Numerical Differentiation 1st order: %f\n", result);
        result = centralDifference2ndorder(index);
        printf("Numerical Differentiation 2nd order: %f\n", result);
    }
    return 0;
}
