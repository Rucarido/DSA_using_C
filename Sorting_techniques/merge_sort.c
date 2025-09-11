#include <stdio.h>

void merge(int arr[], int s, int e) {
    
    int i = s;
    int mid = (s + e) / 2;
    int j = mid+1;
    
    int temp[e - s + 1]; //temporary array to merge both halves
    int k = 0; //keep track of index of temp
    
    //loop to iterate over both the halves and append to the temp array in order
    while (i <= mid && j <= e) { 
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }
    
    //loop to copy the remaining elements of the first half if it exists
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    //loop to copy the remaining elements of the second half if it exists
    while (j <= e) {
        temp[k++] = arr[j++];
    }
    
    //loop to copy the merged array into the original array
    k = 0;
    for (int idx = s; idx <= e; idx++) {
        arr[idx] = temp[k++];
    }
    
    return;
}

void mergeSort(int arr[], int s, int e) {
    
    if (s >= e) {
        return;
    }
    
    int mid = (s + e) / 2; //split the array into exactly two halves
    mergeSort(arr, s, mid); //recursive sort on the first half
    mergeSort(arr, mid + 1, e); //recursive sort on the second half
    merge(arr, s, e); //merge both the halves in order
}

int main() {
    
    int n; scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    mergeSort(arr, 0, n-1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }


    return 0;
}

