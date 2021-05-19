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

int main (int argc, char* argv[]) {
  if (argc != 2) return 1;
  int n = atoi(argv[1]);
  if (n < 2) return 1;
  double legNod[n], chNod[n];
  newton(n, legRec, legNod);
  newton(n, chRec, chNod);
  printArray(n, legNod);
  printArray(n, chNod);
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
  double r = n * (func(n-1, x) - x * (func(n, x)))/(1 - pow(x, 2));
  return r;
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
