#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float simple1(float x, float y, float z);
float simple2(float x, float y, float z);
double doble1(double x, double y, double z);
double doble2(double x, double y, double z);

int main(int argc, char* argv[]) {
  if (argc != 4) {
    printf("ERROR: Ejecute el programa de la siguiente manera: ./pb2a a b c\n");
    return 1;
  }
  double a = atof(argv[1]);
  double b = atof(argv[2]);
  double c = atof(argv[3]);
  printf("Simple: Positivo: %.8G  Negativo: %.8G.\n", simple1(a, b, c),
         simple2(a, b, c));
  printf("Doble: Positivo: %.16G  Negativo: %.16G.\n", doble1(a, b, c),
         doble2(a, b, c));
  return 0;
}

float simple1(float x, float y, float z) {
  if (y * y < 4 * x * z) {
    printf("Discriminante < 0.\n");
    return 0;
  } else {
    float r = (-y + sqrtf(y * y - 4 * x * z)) / (2 * x);
    return r;
  }
}

float simple2(float x, float y, float z) {
  if (y * y < 4 * x * z) {
    printf("Discriminante < 0.\n");
    return 0;
  } else {
    float r = (-y - sqrtf(y * y - 4 * x * z)) / (2 * x);
    return r;
  }
}

double doble1(double x, double y, double z) {
  if (y * y < 4 * x * z) {
    printf("Discriminante < 0.\n");
    return 0;
  } else {
    double r = (-y + sqrt(y * y - 4 * x * z)) / (2 * x);
    return r;
  }
}

double doble2(double x, double y, double z) {
  if (y * y < 4 * x * z) {
    printf("Discriminante < 0.\n");
    return 0;
  } else {
    double r = (-y - sqrt(y * y - 4 * x * z)) / (2 * x);
    return r;
  }
}
