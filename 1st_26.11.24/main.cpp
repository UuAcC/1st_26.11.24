#include <malloc.h>
#include <stdio.h>

void radixSort(int* arr, int n) {
	int* tmp = (int*)malloc(sizeof(int) * n);
	int* counts = (int*)malloc(sizeof(int) * 256);
	int* indexes = (int*)malloc(sizeof(int) * 256);
	for (int iter = 0;iter < 4;iter++) {
		indexes[0] = 0;
		for (int i = 0;i < 256;i++) { counts[i] = 0; }
		for (int i = 0;i < n;i++) {
			unsigned char* p = (unsigned char*)&arr[i];
			counts[p[iter]]++;
		}
		for (int i = 1;i < 256;i++) {
			indexes[i] = indexes[i - 1] + counts[i - 1];
		}
		for (int i = 0;i < n;i++) {
			unsigned char* p = (unsigned char*)&arr[i];
			tmp[indexes[p[iter]]] = arr[i];
			indexes[p[iter]]++;
		}
		for (int i = 0;i < n;i++) { arr[i] = tmp[i]; }
	}
	free(tmp); free(counts); free(indexes);
}

int main() {
	int n = 10;
	int arr[10] = { 1, 7, 8, 16, 782342, 532, 999, 4, 6, 34 };
	radixSort(arr, n);
	for (int i = 0;i < n;i++) { printf(" %d ", arr[i]); }
	return 0;
}