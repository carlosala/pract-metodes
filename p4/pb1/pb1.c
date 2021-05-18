#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define TOL 1.e-12

int sign (double);
double legRec (int, double);
double chRec (int, double);
double deriv (int, double(), double);
void findNewtonNodes (int n, double(), double[n]);
void newton (int n, double(), double[n], double[n]);

int main (int argc, char* argv[]) {
  if (argc != 2) return 1;
  int n = atoi(argv[1]);
  if (n < 2) return 1;
  double legBis[n], legNod[n];
  double chBis[n], chNod[n];
  findNewtonNodes(n, legRec, legBis);
  findNewtonNodes(n, chRec, chBis);
  newton(n, legRec, legBis, legNod);
  newton(n, chRec, chBis, chNod);
  for (int i = 0; i < n; i++) {
    printf("%.16G %.16G %.16G\n", legBis[i], legNod[i], legRec(n, legNod[i]));
  }
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%.16G %.16G %.16G\n", chBis[i], chNod[i], chRec(n, chNod[i]));
  }
}

int sign (double x) {
  if (x > TOL) return 1;
  if (x < -TOL) return -1;
  return 0;
}

double legRec (int n, double x) {
  double p = 1;
  double pn = x;
  double pr;
  for (int i = 1; i < n; i++) {
    pr = ((2 * i + 1) * x * pn - i * p)/(i + 1);
    p = pn;
    pn = pr;
  }
  return pn;
}

double chRec (int n, double x) {
  double p = 1;
  double pn = x;
  double pr;
  for (int i = 1; i < n; i++) {
    pr = 2 * x * pn - p;
    p = pn;
    pn = pr;
  }
  return pn;
}

double deriv (int n, double func(int, double), double x) {
  double r = n * (func(n-1, x) - x * (func(n, x)))/(1 - pow(x, 2));
  return r;
}

void findNewtonNodes (int n, double func(int, double), double r[n]) {
  int acc;
  if (n % 2 == 1) acc = (n + 1)/2;
  else acc = n/2;
  int s;
  int sa = sign(func(n, 0));
  for (int i = 1; i <= pow(n, 2); i++) {
    s = sign(func(n, i*1./pow(n, 2)));
    if (s != sa && s != 0 && sa != 0) {
      int si = sign(func(n, (2 * i - 1)/(2 * pow(n, 2))));
      if (si != sa) r[acc] = (4 * i - 3)/(4 * pow(n, 2));
      else r[acc] = (4 * i - 1)/(4 * pow(n, 2));
      ++acc;
    }
    sa = s;
  }
  if (n % 2 == 1) {
    for (int i = 0; i < (n - 1)/2; i++) {
      r[(n-1)/2-1-i] = - r[(n-1)/2+1+i];
      r[(n-1)/2] = 0;
    }
  } else {
    for (int i = 0; i < n/2; i++) {
      r[n/2 - 1 - i] = - r[n/2 + i];
    }
  }
}

void newton (int n, double func(int, double), double nod[n], double r[n]) {
  int nn;
  if (n % 2 == 1) {
    nn = (n - 1)/2;
    r[nn] = 0;
  }
  else nn = n/2;
  for (int i = 0; i < nn; i++) {
    double x = nod[i], xn;
    for (int j = 0; j < 7; j++) {
      xn = x - func(n, x)/deriv(n, func, x);
      x = xn;
      r[i] = x;
    }
  }
  for (int i = 0; i < nn; i++) {
    r[n-i-1] = - r[i];
  }
}
