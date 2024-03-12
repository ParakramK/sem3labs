#include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
  int fact = 1;
  for (int i = 1; i <= n; i++) {
    fact *= i;
  }
  return fact;
}

float newtonBackwardInterpolation(int n, float x[], float y[], float x0) {
  float y0 = y[n - 1]; // Start with the last element of y[]
  float u = (x0 - x[n - 1]) / (x[1] - x[0]);
  float backward[n - 1][n - 1];

  // Calculate backward difference table
  for (int j = 0; j < n - 1; j++) {
    for (int i = n - 1; i > j; i--) {
      if (j == 0) {
        backward[i - 1][j] = y[i] - y[i - 1];
      } else {
        backward[i - 1][j] = backward[i][j - 1] - backward[i - 1][j - 1];
      }
    }
  }

  printf("Backward Difference Table:\n");
  printf("\n");
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < i + 1; j++) {
      printf("%.4f\t", backward[i][j]);
    }
    printf("\n");
  }

  // Applying Newton's Backward Interpolation formula
  for (int j = 1; j < n; j++) {
    float term = (u * backward[n - 2][j - 1]) / factorial(j);
    y0 += term;
    u *= (x0 - x[n - 1 - j]) / (x[1] - x[0]);
  }

  return y0;
}

int main() {
  int n; // Number of data points
  printf("Enter the number of data points: ");
  scanf("%d", &n);
  float x[n], y[n];

  // Taking input for x and y arrays
  for (int i = 0; i < n; i++) {
    printf("Enter x[%d] and y[%d]: ", i, i);
    scanf("%f %f", &x[i], &y[i]);
  }

  float x0;
  printf("Enter the value of x for which y is to be found: ");
  scanf("%f", &x0);

  float y0 = newtonBackwardInterpolation(n, x, y, x0);

  printf("The value of y at x = %.2f is %.2f\n", x0, y0);

  return 0;
}
