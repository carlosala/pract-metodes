#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double secantDoble (double, double, double, int);
double func (double);
double deriv (double);

int main () {
  double r = secantDoble(2, 8, 1.e-15, 20);
  printf("Resultat: %.16G\n", r);
  return 0;
}
double secantDoble (double x0,double y0, double tol, int nmax) {
  double x = x0;
  double y = y0;
  double fx = func(x0);
  double fy = func(y0);
  double z, fz;
  for (int i = 0; i < nmax; i++) {
    z = x - fx * (y-x)/(fy - fx);
    fz = func(z);
    if (fabs(fz) < tol) {
      printf("Iteracions: %d\n", i + 1);
      return z;
    }
    x = y;
    y = z;
    fx = fy;
    fy = fz;
  }
  printf("nmax insuficient.\n");
  return z;
}

double func (double x) {
  double r = pow(x, 3) - x - 400;
  return r;
}
