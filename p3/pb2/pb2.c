#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void inputData (int n, char*, double[n+1], double[n+1][n+1]);
double quoInc (double, double, double, double);
void difDiv (int n, double[n+1], double[n+1][n+1]);
double avPol (int n, double[n+1], double[n+1][n+1], double);

int main (int argc, char* argv[]) {
  if (argc != 2) {
    printf("El programa debe ejecutarse del siguiente modo: ./pb2 'nombrefichero.txt'\n");
    return 1;
  }
  char *fileName = argv[1];
  int n = atoi(fileName);
  double nod[n+1];
  double m[n+1][n+1];
  inputData(n, fileName, nod, m);
  difDiv(n, nod, m);
  double r = avPol(n, nod, m, 0);
  printf("%lf\n", r);
  return 0;
}

void inputData (int n, char *fileName, double nod[n+1], double m[n+1][n+1]) {
  FILE *fitxer;
  fitxer = fopen(fileName, "r");
  if (fitxer == NULL) {
    printf("El fitxer no s'ha pogut obrir.\n");
    return;
  }
  for (int i = 0; i <= n; i++) {
    fscanf(fitxer, "%lf %lf", &nod[i], &m[i][0]);
  }
  fclose(fitxer);
  return;
}

double quoInc (double f2, double f1, double x2, double x1) {
  double r = (f2 - f1) / (x2 - x1);
  return r;
}

void difDiv (int n, double nod[n+1], double m[n+1][n+1]) {
  for (int j = 1; j <= n; j++) {
    for (int i = 0; i <= n - j; i++) {
      m[i][j] = quoInc(m[i+1][j-1], m[i][j-1], nod[i+j], nod[i]);
    }
  }
  return;
}

double avPol (int n, double nod[n+1], double m[n+1][n+1], double x) {
  double r = 0;
  for (int i = 0; i <= n; i++) {
    double rp = m[0][i];
    for (int j = 0; j < i; j++) {
      rp = rp * (x - nod[j]);
    }
    r = r + rp;
  }
  return r;
}
