#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double doble(double);

int main() {
  double b = pow(200 + sqrt(40000 - 1. / 27), 1. / 3) +
             pow(200 - sqrt(40000 - 1. / 27), 1. / 3);
  printf("Arrel: %.16G\n", b);
  printf("Resultat: %.16G\n", doble(b));
  return 0;
}

double doble(double x) {
  double r = pow(x, 3) - x - 400;
  return r;
}
