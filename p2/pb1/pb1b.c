#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float newtonSimple (double, double, int);
double newtonDoble (double, double, int);

int main () {
  float s1 = newtonSimple(2, 1.e-8, 10);
  float d2 = newtonDoble(2, 1.e-15, 10);
  printf("Simple e-8: %.8G\n", s1);
  printf("Doble e-15: %.16G\n", d2);
  return 0;
}

float newtonSimple (double x0, double tol, int nmax) {
  float x = x0;
  float xn = 0;
  for (int i = 0; i < nmax; i++) {
    xn = x - (powf(x, 3) - x - 40)/(3 * powf(x, 2) - 1);
    if (fabsf(xn - x) < tol) {
      printf("Iteracions simple: %d\n", i + 1);
      return xn;
    }
    x = xn;
  }
  printf("nmax insuficient.\n");
  return xn;
}

double newtonDoble (double x0, double tol, int nmax) {
  float x = x0;
  float xn = 0;
  for (int i = 0; i < nmax; i++) {
    xn = x - (pow(x, 3) - x - 40)/(3 * pow(x, 2) - 1);
    if (fabs(xn - x) < tol) {
      printf("Iteracions doble: %d\n", i + 1);
      return xn;
    }
    x = xn;
  }
  printf("nmax insuficient.\n");
  return xn;
}
