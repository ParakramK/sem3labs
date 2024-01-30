#include <stdio.h>
#include <math.h>
#define N 3 // number of variables

int main() {
    float A[N][N + 1] = { {3, 2,-4, 3},
                        {2, 3, 3, 15},
                        {5,-3, 1, 14} };
    float x[N];
    float max, temp, ratio;
    // Gaussian elimination with partial pivoting
    for (int i = 0; i < N; i++) {
        max = fabs(A[i][i]);
        int max_row = i;
        for (int j = i + 1; j < N; j++) {
            if (fabs(A[j][i]) > max) {
                max = fabs(A[j][i]);
                max_row = j;
            }
        }
        if (max_row != i) {
            for (int k = 0; k < N + 1; k++) {
                temp = A[i][k];
                A[i][k] = A[max_row][k];
                A[max_row][k] = temp;
            }
        }
        // perform Gaussian elimination
        for (int j = i + 1; j < N; j++) {
            ratio = A[j][i] / A[i][i];
            for (int k = i; k < N + 1; k++) {
                A[j][k] -= ratio * A[i][k];
            }
        }
    }
    // back-substitution
    for (int i = N - 1; i >= 0; i--) {
        x[i] = A[i][N];
        for (int j = i + 1; j < N; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
    // print the solution
    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %.2f\n", i, x[i]);
    }

    return 0;
}
