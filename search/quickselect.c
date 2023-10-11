#include <stdio.h>

int main() {

	int arr[10] = {20, 15, 25, 40, 35, 45, 65, 70, 75, 80}; 
	int size = (int) sizeof(arr) / sizeof(arr[0]); 
	int second_min = quickselect(arr, 0, size - 1, 4);  

	printf("%d", second_min);
}

int quickselect(int* arr, int l, int h, int k) {
    
	if(l == h) return arr[h]; 
	
	int p = partition(arr, l, h);
	
	if(k < p) return quickselect(arr, l, p - 1, k); 
	if(k > p) return quickselect(arr, p + 1, h, k); 
	
	return arr[p]; 
}

int partition(int* arr, int p, int pivot) {
    
    int i = p;
    int x = arr[pivot];
	
    for (int j = p; j < pivot; j++) {
        if(arr[j] <= x) {
	    swap(i, j, arr);
	    i++;
	}
    }
    swap(i, pivot, arr);
    return i; 
}

void swap(int i, int j, int* arr){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
