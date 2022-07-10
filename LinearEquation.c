#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

void printMatrix(double** a, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%.2lf ", a[i][j]);
		}
		printf("\n");
	}
}
  int rowToSwap(double** a, int i, int size) {
	{
		int rowToSwap;
		double max = a[i][i];
		double maxCopy = max;
		for (int m = i + 1; m < size; m++) {
			if (fabs(a[m][i]) > max) {
				max = a[m][i];
				rowToSwap = m;
			}
		}
		if (max != maxCopy) {
			return rowToSwap;
		}
		else {
			return i;
		}
	}
}

void rowSwapping(double** a,double*b, int i, int j, int size) {
	for (int k = 0; k < size; k++) {
		double temp = a[i][k];
		a[i][k] = a[j][k];
		a[j][k] = temp;
	}

	double temp2 = b[i];
	b[i] = b[j];
	b[j] = temp2;

}

int main() {
	int size;
	scanf("%d", &size);
	double** a = (double**)malloc(size * sizeof(double*));
	for (int i = 0; i < size; i++) {
		a[i] = (double*)malloc(4 * sizeof(double));
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			scanf("%lf", &a[i][j]);
		}
	}
	double* b = (double*)malloc(sizeof(double) * size);
	for (int i = 0; i < size; i++) {
		scanf("%lf", &b[i]);
	}

	for (int k = 0; k < size-1; k++) {
		for (int i = k + 1; i < size; i++) {
			int swap = rowToSwap(a, k, size);
			if (swap != k) {
				rowSwapping(a, b, k, swap, size);
			}
			double r = a[i][k] / a[k][k];
			for (int j = k; j < size; j++) {
				a[i][j] -= a[k][j] * r;
			}
			b[i] -= b[k] * r;
		}
	}

	for (int i = size-1; i >= 0; i--) {
		for (int j = i + 1; j < size; j++)
		{
			b[i] -= a[i][j] * b[j];
		}
		b[i] /= a[i][i];
	}
	for (int i = 0; i < size; i++) {
		printf("%.2lf ", b[i]);
	}

	return 0;
}