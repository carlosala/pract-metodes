#include <math.h>
#include <stdio.h>

double ak(double, double);
double bk(double, double);
double ck(double, double);
double sk(double, double, int);
double pk(double, int);

int main() {
  double r = pk(1.e-13, 10);
  printf("Resultat: %.16G\n", r);
  return 0;
}
double pk(double tol, int nmax) {
  double a = 1;
  double b = 1 / sqrt(2);
  double s = 0.5;
  double p = 2 * pow(a, 2) / s;
  double an = ak(a, b);
  double bn = bk(a, b);
  double cn = ck(an, bn);
  double sn = sk(s, cn, 1);
  double pn;
  for (int i = 1; i <= nmax; i++) {
    pn = 2 * pow(an, 2) / sn;
    printf("%.16G\n%.16G\n%.16G\n\n", fabs((pn - M_PI) / (p - M_PI)),
           fabs((pn - M_PI) / pow(p - M_PI, 2)),
           fabs((pn - M_PI) / pow(p - M_PI, 3)));
    if (fabs(pn - p) < tol) {
      printf("Iteracions: %d\n", i);
      return pn;
    }
    p = pn;
    a = an;
    b = bn;
    s = sn;
    an = ak(a, b);
    bn = bk(a, b);
    cn = ck(an, bn);
    sn = sk(s, cn, i + 1);
  }
  printf("nmax insuficient.\n");
  return pn;
}

double ak(double a, double b) {
  double r = (a + b) / 2;
  return r;
}

double bk(double a, double b) {
  double r = sqrt(a * b);
  return r;
}

double ck(double an, double bn) {
  double r = pow(an, 2) - pow(bn, 2);
  return r;
}

double sk(double s, double cn, int k) {
  double r = s - pow(2, k) * cn;
  return r;
}
