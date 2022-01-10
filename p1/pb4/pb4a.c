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
  int x = atoi(argv[1]);

  printf("Simple: %.8G\n", simple(x));
  printf("Doble: %.16G\n", doble(x));

  return 0;
}

float simple(int k) {
  float S = 0;
  float p = 0;
  for (int j = 0; j < k; j++) {
    p++;
    S += 1 / (p * p);
  }
  return S;
}

double doble(int k) {
  double S = 0;
  double p = 0;
  for (int j = 0; j < k; j++) {
    p++;
    S += 1.0 / (p * p);
  }
  return S;
}
