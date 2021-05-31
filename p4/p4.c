#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define TOL 1.e-12

int sign (double);
void printArray (int n, double[n]);
double legRec (int, double);
double chRec (int, double);
double deriv (int, double(), double);
void newtonCoef (int n, double(), double[n], double[n]);
double func1 (double);
double func2 (double);
double func3 (double);
double trapezium (int, double, double, double());
double calInt (int n, double(), double[n], double[n], double());

int main (int argc, char* argv[]) {
  if (argc != 2) return 1;
  int n = atoi(argv[1]);
  if (n < 2) return 1;
  double legNod[n], chNod[n], legCoef[n], chCoef[n];
  newtonCoef(n, legRec, legNod, legCoef);
  newtonCoef(n, chRec, chNod, chCoef);
  printf("Legendre nodes:\n");
  printArray(n, legNod);
  printf("Chebyshev nodes:\n");
  printArray(n, chNod);
  printf("Legendre coeficients:\n");
  printArray(n, legCoef);
  printf("Chebyshev coeficients:\n");
  printArray(n, chCoef);
  printf("Integrals 1, 2, 3 (Legendre Chebyshev Trapezium):\n");
  printf("%.16G %.16G %.16G\n", calInt(n, legRec, legCoef, legNod, func1), calInt(n, chRec, chCoef, chNod, func1), trapezium(n, -1, 1, func1));
  printf("%.16G %.16G\n", calInt(n, legRec, legCoef, legNod, func2), calInt(n, chRec, chCoef, chNod, func2));
  printf("%.16G %.16G %.16G\n", calInt(n, legRec, legCoef, legNod, func3), calInt(n, chRec, chCoef, chNod, func3), trapezium(n, -1, 1, func3));
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

double deriv (int n, double met(), double x) {
  return n * (met(n-1, x) - x * (met(n, x)))/(1 - pow(x, 2));
}

void newtonCoef (int n, double met(), double nod[n], double coef[n]) {
  int nn, acc = 0;
  if (n % 2 == 1) nn = (n - 1)/2;
  else nn = n/2;
  int s, sa = sign(met(n, 1/pow(n, 2)));
  for (int i = 1; i <= pow(n, 2); i++) {
    s = sign(met(n, i/pow(n, 2)));
    if (s != sa) {
      double x = (2 * i - 1)/(2 * pow(n, 2));
      for (int j = 0; j < 7; j++) {
        x = x - met(n, x)/deriv(n, met, x);
        if (n % 2 == 1) nod[nn + acc + 1] = x;
        else nod[nn + acc] = x;
        nod[nn - acc - 1] = -x;
      }
      ++acc;
    }
    sa = s;
  }
  if (n % 2 == 1) nod[nn] = 0;
  if (met == legRec) {
    for (int i = 0; i < n; i++) {
      coef[i] = 2/((1 - pow(nod[i], 2)) * pow(deriv(n, legRec, nod[i]), 2));
    }
  } else if (met == chRec) {
    for (int i = 0; i < n; i++) {
      coef[i] = M_PI / n;
    }
  }
}

double func1 (double x) {
  return 1/(1 + pow(x, 2));
}

double func2 (double x) {
  return (pow(x, 8) - 2 * pow(x, 6) + 3 * pow(x, 4) - pow(x, 2) + 5)/sqrt(1-pow(x, 2));
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

double calInt(int n, double met(), double coef[n], double nod[n], double func()) {
  double r = 0;
  if (met == legRec) {
    for (int i = 0; i < n; i++) {
      r += coef[i] * func(nod[i]);
    }
  } else {
    for (int i = 0; i < n; i++) {
      r += coef[i] * func(nod[i]) * sqrt(1-pow(nod[i], 2));
    }
  }
  return r;
}
