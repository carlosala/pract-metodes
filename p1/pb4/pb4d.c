#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float simple(int);
double doble(int);

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("ERROR: Ejecute el programa de la siguiente manera: ./pb4a n\n");
    return 1;
  }
  int n = atoi(argv[1]);
  printf("Simple: %.8G\n", simple(n));
  printf("Doble: %.16G\n", doble(n));
  return 0;
}

float simple(int n) {
  int sign = 1;
  float x = 0;
  float r0 = 0;
  for (int i = 0; i < n; i++) {
    r0 += sign / (powf(3, x) * (2 * x + 1));
    sign = -sign;
    x++;
  }
  float r = 2 * powf(r0, 2);
  return r;
}

double doble(int n) {
  int sign = 1;
  double x = 0;
  double r0 = 0;
  for (int i = 0; i < n; i++) {
    r0 += sign / (pow(3, x) * (2 * x + 1));
    sign = -sign;
    x++;
  }
  double r = 2 * pow(r0, 2);
  return r;
}
