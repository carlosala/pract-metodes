#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double newtonDoble(double, double, int);
double func(double);
double deriv(double);

int main() {
  double r = newtonDoble(2, 1.e-15, 20);
  printf("Resultat: %.16G\n", r);
  return 0;
}

double newtonDoble(double x0, double tol, int nmax) {
  double x = x0;
  double xn = 0;
  for (int i = 0; i < nmax; i++) {
    xn = x - func(x) / deriv(x);
    if (fabs(xn - x) < tol) {
      printf("Iteracions: %d\n", i + 1);
      return xn;
    }
    x = xn;
  }
  printf("nmax insuficient.\n");
  return xn;
}

double func(double x) {
  double r = pow(x, 3) - x - 400;
  return r;
}

double deriv(double x) {
  double r = 3 * pow(x, 2) - 1;
  return r;
}
