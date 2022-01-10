#include <math.h>
#include <stdio.h>

float simple(double);
double doble(double);

int main() {
  double x = 1.2e-5;
  float rs = simple(x);
  double rd = doble(x);
  printf("Simple: %.8G \nDoble: %.16G \n", rs, rd);
  return 0;
}

float simple(double x) {
  float result = 2 * sinf(x / 2) * sinf(x / 2) / (x * x);
  return result;
}

double doble(double x) {
  double result = 2 * sin(x / 2) * sin(x / 2) / (x * x);
  return result;
}
