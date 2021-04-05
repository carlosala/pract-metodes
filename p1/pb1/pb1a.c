#include<stdio.h>
#include<math.h>

float simple (double);
double doble (double);

int main () {
  double x = 1.2e-5;
  float rs = simple(x);
  double rd = doble(x);
  printf("Simple: %.8G \nDoble: %.16G \n", rs, rd);
  return 0;
}

float simple (double x) {
  float result = (1-cosf(x))/(x*x);
  return result;
}

double doble (double x) {
  double result = (1-cos(x))/(x*x);
  return result;
}
