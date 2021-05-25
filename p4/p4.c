#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define TOL 1.e-12

int sign (double);
void printArray (int n, double[n]);
double legRec (int, double);
double chRec (int, double);
double deriv (int, double(), double);
void newton (int n, double(), double[n]);
void coefLeg (int n, double[n], double[n]);
void coefCh (int n, double[n]);
double func1 (double);
double func2 (double);
double func3 (double);
double trapezium (int, double, double, double());
double calInt (int n, double[n], double[n], double());

int main (int argc, char* argv[]) {
  if (argc != 2) return 1;
  int n = atoi(argv[1]);
  if (n < 2) return 1;
  double legNod[n], chNod[n], legCo[n], chCo[n];
  newton(n, legRec, legNod);
  newton(n, chRec, chNod);
  coefLeg(n, legNod, legCo);
  coefCh(n, chCo);
  printf("Legendre nodes:\n");
  printArray(n, legNod);
  printf("Chebyshev nodes:\n");
  printArray(n, chNod);
  printf("Legendre coeficients:\n");
  printArray(n, legCo);
  printf("Chebyshev coeficients:\n");
  printArray(n, chCo);
  printf("Integrals 1, 2, 3 (Gaussiana & trapezium):\n");
  printf("%.16G %.16G\n", calInt(n, legCo, legNod, func1), trapezium(n, -1, 1, func1));
  printf("%.16G\n", calInt(n, chCo, chNod, func2));
  printf("%.16G %.16G\n", calInt(n, legCo, legNod, func3), trapezium(n, -1, 1, func3));
  return 0;
}

int sign (double x) {
  if (x > TOL) return 1;
  if (x < -TOL) return -1;
  return 0;
}

void printArray (int n, double x[n]) {
  for (int i = 0; i < n; i++) {
    printf("%.16G\n", x[i]);
  }
  printf("\n");
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

double deriv (int n, double func(), double x) {
  return n * (func(n-1, x) - x * (func(n, x)))/(1 - pow(x, 2));
}

void newton (int n, double func(), double r[n]) {
  int nn, acc = 0;
  if (n % 2 == 1) nn = (n - 1)/2;
  else nn = n/2;
  int s, sa = sign(func(n, 1/pow(n, 2)));
  for (int i = 1; i <= pow(n, 2); i++) {
    s = sign(func(n, i*1/pow(n, 2)));
    if (s != sa) {
      double x = (2 * i - 1)/(2 * pow(n, 2));
      for (int j = 0; j < 7; j++) {
        x = x - func(n, x)/deriv(n, func, x);
        if (n % 2 == 1) r[nn + acc + 1] = x;
        else r[nn + acc] = x;
        r[nn - acc - 1] = -x;
      }
      ++acc;
    }
    sa = s;
  }
  if (n % 2 == 1) r[nn] = 0;
}

void coefLeg (int n, double nod[n], double r[n]) {
  for (int i = 0; i < n; i++) {
    r[i] = 2/((1 - pow(nod[i], 2)) * pow(deriv(n, legRec, nod[i]), 2));
  }
}

void coefCh (int n, double r[n]) {
  for (int i = 0; i < n; i++) {
    r[i] = M_PI / n;
  }
}

double func1 (double x) {
  return 1./(1 + pow(x, 2));
}

double func2 (double x) {
  return pow(x, 8) - 2 * pow(x, 6) + 3 * pow(x, 4) - pow(x, 2) + 5;
}

double func3 (double x) {
  return fabs(x);
}

double trapezium (int n, double a, double b, double func()) {
  double r = 0;
  double h = (b - a)/n;
  double sp = 0;
  for (int i = 1; i < n; i++) {
    sp += func(a + i * h);
  }
  r = h * (func(a) + func(b) + 2 * sp)/2;
  return r;
}

double calInt(int n, double coef[n], double nod[n], double func()) {
  double r = 0;
  for (int i = 0; i < n; i++) {
    r += coef[i] * func(nod[i]);
  }
  return r;
}
