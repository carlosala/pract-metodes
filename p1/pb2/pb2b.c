#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float simple (double, double, double);
double doble (double, double, double);

int main(int argc, char* argv[]) {
  if (argc != 4) {
    printf("ERROR: Ejecute el programa de la siguiente manera: ./pb2a a b c\n");
    return 1;
  }
  double a = atof(argv[1]);
  double b = atof(argv[2]);
  double c = atof(argv[3]);
  printf("Simple: %.8G \n", simple(a, b, c));
  printf("Doble: %.16G \n", doble(a, b, c));
  return 0;
}

float simple (double x, double y, double z) {
  if (y * y < 4 * x * z) {
    printf("Discriminante < 0.\n");
    return 0;
  }
  else {
    float r = (-2 * z)/(y + sqrtf(y * y + 4 * x * z));
    return r;
  }
}

double doble (double x, double y, double z) {
  if (y * y < 4 * x * z) {
    printf("Discriminante < 0.\n");
    return 0;
  }
  else {
    double r = (-2 * z)/(y + sqrt(y * y + 4 * x * z));
    return r;
  }
}
