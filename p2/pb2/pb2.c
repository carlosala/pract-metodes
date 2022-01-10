#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double pb2(double, double, int);
double func(double);
double deriv(double);
double bn(double, double);

int main() {
  double r = pb2(6, 1.e-15, 10);
  printf("Resultat: %.16G\n", r);
  return 0;
}

double pb2(double x0, double tol, int nmax) {
  double x = x0;
  double xn;
  double b = 1 / deriv(x0);
  double eb;
  double e = func(x) * b;
  for (int i = 0; i < nmax; i++) {
    xn = x - func(x) * b;
    if (fabs(xn - x) < tol) {
      printf("Iteracions doble: %d\n", i + 1);
      return xn;
    }
    b = bn(b, xn);
    eb = e;
    e = b * func(x);
    x = xn;
    printf("%.16G\n%.16G\n%.16G\n\n", e / eb, e / pow(eb, 2), e / pow(eb, 3));
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

double bn(double b, double xn) {
  double r = b * (2 - deriv(xn) * b);
  return r;
}
