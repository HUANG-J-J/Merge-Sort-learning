#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define length 10

void InitARR(int*& arr, int len) {
	arr = (int*)calloc(len, sizeof(int));

	for (int i = 0; i < len; i++) {
		if (arr)
			arr[i] = rand() % 100;
	}
}

void PrintARR(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
}

void swap(int& a, int& b) {
	int flag = a;
	a = b;
	b = flag;
}
void Merge(int* arr1, int low, int mid, int high) {
	static int arr2[length];
	int i = 0, j = 0, k = 0;
	for (i = low; i <= high; i++) {
		arr2[i] = arr1[i];
	}
	for (i = low, j = mid + 1, k = i; i <= mid && j <= high;) {
		if (arr2[i] < arr2[j]) {
			arr1[k++] = arr2[i++];
		}
		else {
			arr1[k++] = arr2[j++];
		}
	}
	while(i<=mid)
		arr1[k++] = arr2[i++];
	while(j<=high)
		arr1[k++] = arr2[j++];
}

void MergeSort(int* arr, int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		MergeSort(arr, low, mid);
		MergeSort(arr, mid+1, high);
		Merge(arr, low, mid, high);
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int* ARR = NULL;
	//int ARR[length] = { 5,1,3,10,6,9,4,7,2,8 };
	int i = 0;
	InitARR(ARR, length);
	PrintARR(ARR, length);
	printf("\n\n---------MergeSort---------\n\n");
	MergeSort(ARR, 0, length - 1);
	PrintARR(ARR, length);

	return 0;
}