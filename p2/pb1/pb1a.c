#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main () {
  float as = powf(20 + sqrtf(32397)/9, 1./3) + powf(20 - sqrtf(32397)/9, 1./3);
  double ad = pow(20 + sqrt(32397)/9, 1./3) + pow(20 - sqrt(32397)/9, 1./3);
  float rs = powf(as, 3) - as - 40;
  double rd = pow(ad, 3) - ad - 40;
  printf("Simple: %.8G\n", rs);
  printf("Doble: %.16G\n", rd);
  return 0;
}
