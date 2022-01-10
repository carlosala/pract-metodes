#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double bisecDoble(double, double, double, double);
double func(double);

int main() {
  double r = bisecDoble(2, 8, 1.e-15, 1.e-15);
  printf("Resultat: %.16G\n", r);
  return 0;
}

double bisecDoble(double a0, double b0, double tolx, double tolf) {
  double fa = func(a0);
  double fb = func(b0);
  if (fabs(fa) < tolf) return fa;
  if (fabs(fb) < tolf) return fb;
  double a = a0;
  double b = b0;
  double m;
  double fm;
  int i = 0;
  while (b - a > tolx) {
    m = (a + b) / 2;
    fm = func(m);
    if (fabs(fm) < tolf) {
      printf("Iteracions: %d\n", i);
      return m;
    }
    if (fa * fm < 0) {
      b = m;
      fb = fm;
    } else {
      a = m;
      fa = fm;
    }
    i++;
  }
  return (a + b) / 2;
}

double func(double x) {
  double r = pow(x, 3) - x - 400;
  return r;
}
