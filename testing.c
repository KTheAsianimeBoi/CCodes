#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int** matrixMultiplication(int** first, int** second, int m,int n, int p) {
	int** result = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++) {
		result[i] = (int*)malloc(p * sizeof(int));
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			result[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			for (int k = 0; k < n; k++) {
				result[i][j] += first[i][k] * second[k][j];
			}
		}
	}

	return result;
}


int main() {
	int m, n,p;
	scanf("%d %d", &m, &n);
	int** first = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++) {
		first[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &first[i][j]);
		}
	}

	scanf("%d %d", &n, &p);
	int** second = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		second[i] = (int*)malloc(p * sizeof(int ));
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			scanf("%d", &second[i][j]);
		}
	}

	int** result = matrixMultiplication(first, second, m,n,p);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}

	return 0;
}