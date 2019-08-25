#include<stdio.h>
#define ARR_LEN 10

void bubbleSort(int *, int);

int main() {
	int arr[ARR_LEN];
	int i;
	for(i=0; i<ARR_LEN; i++) {
		if(i % 2 == 0) {
			arr[i] = i;
		} else {
			arr[i] = -i;
		}
	}
	bubbleSort(arr, ARR_LEN);
	for(i=0; i<ARR_LEN; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}
	return 0;	
}

void bubbleSort(int *arr, int length) {
	int i, j;
	for(i=0; i<length-1; i++) {
		for(j=length-1; j>i; j--) {
			if(arr[j] < arr[j-1]) {
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}
}
