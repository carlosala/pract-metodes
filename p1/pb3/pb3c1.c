#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float simpleOne (int, double*);
double doubleOne (int, double*);
float simpleTwo (int, double*);
double doubleTwo (int, double*);

int main () {
  int n = 100;
  double v[n];
  for (int i = 0; i < n; i++) {
    v[i] = 1000000 + i;
  }
  float rso = simpleOne(n, v);
  float rst = simpleTwo(n, v);
  double rdo = doubleOne(n, v);
  double rdt = doubleTwo(n, v);
  printf("Simple 1: %.8G\nSimple 2: %.8G\n", rso, rst);
  printf("Doble 1: %.16G\nDoble 2: %.16G\n", rdo, rdt);
  return 0;
}

float simpleOne (int n, double* x) {
  float xt0 = 0;
  float s0 = 0;
  for (int i = 0; i < n; i++) {
    xt0 += x[i];
  }
  float xt = xt0/n; 
  for(int i = 0; i < n; i++) {
    s0 += (x[i]-xt)*(x[i]-xt);
  }
  float s = s0/(n-1);
  return s;
}

double doubleOne (int n, double* x) {
  double xt0 = 0;
  double s0 = 0;
  for (int i = 0; i < n; i++) {
    xt0 += x[i];
  }
  double xt = xt0/n; 
  for(int i = 0; i < n; i++) {
    s0 += (x[i] - xt) * (x[i] - xt);
  }
  double s = s0/(n-1);
  return s;
}

float simpleTwo (int n, double* x) {
  float s;
  float x2 = 0;
  float x1 = 0;
  for(int i = 0; i < n; i++) {
    x2 += x[i] * x[i];
  }
  for(int i = 0; i < n; i++) {
    x1 += x[i];
  }
  x1 = (x1 * x1)/n;
  s = (x2 - x1)/(n - 1);
  return s;
}

double doubleTwo (int n, double* x) {
  double s;
  double x2 = 0;
  double x1 = 0;
  for(int i = 0; i < n; i++) {
    x2 += x[i] * x[i];
  }
  for(int i = 0; i < n; i++) {
    x1 += x[i];
  }
  x1 = (x1 * x1)/n;
  s = (x2 - x1)/(n - 1);
  return s;
}

