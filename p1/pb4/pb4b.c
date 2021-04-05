#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float simple (int);
double doble (int);

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

float simple (int k) {
  float S = 0;
  float p = k;
  for (int j = 0; j < k; j++) {
    S += 1./(p * p);
    p--;
  }
  return S;
}

double doble (int k) {
  double S = 0;
  double p = k;
  for (int j = 0; j < k; j++) {
    S += 1./(p * p);
    p--;
  }
  return S;
}
