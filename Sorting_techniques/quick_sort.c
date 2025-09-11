#include <stdio.h>

int partition(int arr[], int s, int e) {
    
    int pivot = arr[e]; //choose pivot element
    int first = s-1; 
    
    //s-1 is the one pointer and another pointer is used to iterate over the array

    for (int i = s; i < e; i++) {
	//if an element lesser than the pivot element is found, swap the element with 1st pointer + 1th index
        if (arr[i] < pivot) { 
            int temp = arr[first+1];
            arr[first+1] = arr[i];
            arr[i] = temp;
            first++;
        }
    }
    //swap the 1st pointer + 1th location with pivot element to put it in its correct position
    int temp = arr[first+1];
    arr[first+1] = pivot;
    arr[e] = temp;
    
    return first+1; //returns the position of pivot element
}

void quickSort(int arr[], int s, int e) {
    
    if (s >= e) {
        return;
    }
    
    int idx = partition(arr, s, e); //partition the array w.r.t the pivot element position into two parts
    quickSort(arr, s, idx-1); //quicksort first half of the array before pivot element
    quickSort(arr, idx+1, e); //quicksort second half of the array after pivot element
    
}

int main() {
	
    int n; scanf("%d", &n);
    int arr[n]; 
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    quickSort(arr, 0, n-1);
    for (int i = 0 ; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


