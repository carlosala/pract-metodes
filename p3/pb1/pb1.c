#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double func(double);
double quoInc(double, double, double, double);
void nodEq(int n, double[n + 1]);
void nodCh(int n, double[n + 1]);
void avNod(int n, double[n + 1], double[n + 1][n + 1]);
void difDiv(int n, double[n + 1], double[n + 1][n + 1]);
double avPol(int n, double[n + 1], double[n + 1][n + 1], double);
int plotErr(int n, double[n + 1], double[n + 1][n + 1], double[n + 1],
            double[n + 1][n + 1], double[2]);

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("El programa debe ejecutarse del siguiente modo: ./pb1 n\n");
    return 1;
  }
  int n = atoi(argv[1]);
  double ne[n + 1];
  double nc[n + 1];
  double me[n + 1][n + 1];
  double mc[n + 1][n + 1];
  double err[2];
  nodEq(n, ne);
  nodCh(n, nc);
  avNod(n, ne, me);
  avNod(n, nc, mc);
  difDiv(n, ne, me);
  difDiv(n, nc, mc);
  int exitCode = plotErr(n, ne, me, nc, mc, err);
  if (exitCode == 0) printf("%lf %lf\n", err[0], err[1]);
  return 0;
}

double func(double x) {
  double r = 1 / (1 + 25 * pow(x, 2));
  return r;
}

double quoInc(double f2, double f1, double x2, double x1) {
  double r = (f2 - f1) / (x2 - x1);
  return r;
}

void nodEq(int n, double nod[n + 1]) {
  double j = 0;
  for (int i = 0; i <= n; i++) {
    nod[i] = -1 + j * 2 / n;
    j++;
  }
  return;
}

void nodCh(int n, double nod[n + 1]) {
  double j = 0;
  for (int i = 0; i <= n; i++) {
    nod[i] = cos((2 * j + 1) * M_PI / ((n + 1) * 2));
    j++;
  }
  return;
}

void avNod(int n, double nod[n + 1], double m[n + 1][n + 1]) {
  for (int i = 0; i <= n; i++) {
    m[i][0] = func(nod[i]);
  }
  return;
}

void difDiv(int n, double nod[n + 1], double m[n + 1][n + 1]) {
  for (int j = 1; j <= n; j++) {
    for (int i = 0; i <= n - j; i++) {
      m[i][j] = quoInc(m[i + 1][j - 1], m[i][j - 1], nod[i + j], nod[i]);
    }
  }
  return;
}

double avPol(int n, double nod[n + 1], double m[n + 1][n + 1], double x) {
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

int plotErr(int n, double ne[n + 1], double me[n + 1][n + 1], double nc[n + 1],
            double mc[n + 1][n + 1], double err[2]) {
  FILE* data;
  data = fopen("out.txt", "w");
  if (data == NULL) {
    printf("No s'ha pogut crear/obrir el fitxer.\n");
    return 1;
  }
  for (int i = 0; i <= 180; i++) {
    double xk = -0.989 + 0.011 * i;
    double f = func(xk);
    double pe = avPol(n, ne, me, xk);
    double pc = avPol(n, nc, mc, xk);
    fprintf(data, "%lf %lf %lf %lf\n", xk, f, pe, pc);
    if (fabs(f - pe) > err[0]) err[0] = fabs(f - pe);
    if (fabs(f - pc) > err[1]) err[1] = fabs(f - pc);
  }
  return 0;
}
