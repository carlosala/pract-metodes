#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float simpleOne(int, double*);
double doubleOne(int, double*);
float simpleTwo(int, double*);
double doubleTwo(int, double*);

int main(int argc, char* argv[]) {
  if (argc < 3) {
    printf(
        "ERROR: Minimo dos numeros. Ejecute el programa de la siguiente "
        "manera. ./pb3a n1 n2...\n");
    return 1;
  }
  int n = argc - 1;
  double v[n];
  for (int i = 0; i < n; i++) {
    v[i] = atof(argv[i + 1]);
  }
  float rso = simpleOne(n, v);
  float rst = simpleTwo(n, v);
  double rdo = doubleOne(n, v);
  double rdt = doubleTwo(n, v);
  printf("Simple 1: %.8G\nSimple 2:%.8G\n", rso, rst);
  printf("Doble 1: %.16G\nDoble 2:%.16G\n", rdo, rdt);
  return 0;
}

float simpleOne(int n, double* x) {
  float xt0 = 0;
  float s0 = 0;
  for (int i = 0; i < n; i++) {
    xt0 += x[i];
  }
  float xt = xt0 / n;
  for (int i = 0; i < n; i++) {
    s0 += (x[i] - xt) * (x[i] - xt);
  }
  float s = s0 / (n - 1);
  return s;
}

double doubleOne(int n, double* x) {
  double xt0 = 0;
  double s0 = 0;
  for (int i = 0; i < n; i++) {
    xt0 += x[i];
  }
  double xt = xt0 / n;
  for (int i = 0; i < n; i++) {
    s0 += (x[i] - xt) * (x[i] - xt);
  }
  double s = s0 / (n - 1);
  return s;
}

float simpleTwo(int n, double* x) {
  float s;
  float x2 = 0;
  float x1 = 0;
  for (int i = 0; i < n; i++) {
    x2 += x[i] * x[i];
  }
  for (int i = 0; i < n; i++) {
    x1 += x[i];
  }
  x1 = (x1 * x1) / n;
  s = (x2 - x1) / (n - 1);
  return s;
}

double doubleTwo(int n, double* x) {
  double s;
  double x2 = 0;
  double x1 = 0;
  for (int i = 0; i < n; i++) {
    x2 += x[i] * x[i];
  }
  for (int i = 0; i < n; i++) {
    x1 += x[i];
  }
  x1 = (x1 * x1) / n;
  s = (x2 - x1) / (n - 1);
  return s;
}
