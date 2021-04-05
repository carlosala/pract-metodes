#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double pb3 (double, double, int);
double func (double);
double deriv (double);
double segDeriv (double);
double g (double);

int main () {
  double r = pb3(5, 1.e-15, 10);
  printf("Resultat: %.16G\n", r);
  return 0;
}

double pb3 (double x0, double tol, int nmax) {
  double x = x0;
  double xn;
  double eb;
  double e = fabs(g(x));
  for (int i = 0; i < nmax; i++) {
    xn = x - g(x);
    if (fabs(xn - x) < tol) {
      printf("Iteracions doble: %d\n", i + 1);
      return xn;
    }
    eb = e;
    e = fabs(g(x));
    x = xn;
    printf("%.16G\n%.16G\n%.16G\n%.16G\n%.16G\n\n", e/eb, e/pow(eb, 2), e/pow(eb, 3), e/pow(eb, 4), e/pow(eb, 5));
  }
  printf("nmax insuficient.\n");
  return xn;
}

double func (double x) {
  double r = pow(x, 3) - x - 400;
  return r;
}

double deriv (double x) {
  double r = 3 * pow(x, 2) - 1;
  return r;
}

double segDeriv (double x) {
  double r = 6 * x;
  return r;
}

double g (double xn){
  double r = 2 * func(xn) * deriv(xn)/(2 * pow(deriv(xn), 2) - func(xn) * segDeriv(xn));
  return r;
}
