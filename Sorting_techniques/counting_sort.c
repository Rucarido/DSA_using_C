// Online C compiler to run C program online
#include <stdio.h>

int main() {
    
    int n; scanf("%d", &n);
    int arr[n]; int max = -1;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    //count arr having the size of maximum element + 1 is initialised to 0
    int count[max + 1];
    for (int i = 0; i < max+1; i++) {
        count[i] = 0;
    }
	
    //counting freq of element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    //updating the count arr to its prefix sum so that it helps in placing the elements of input array in the correct index of output array
    for (int i = 1; i <= max; i++) {
        count[i] = count[i-1] + count[i]; //prefix sum
    }
    
    int output[n];
    //loop from back so as to preserve the order of same elements in the input array
    for (int i = n-1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i]; //place the element in output array
        count[arr[i]]--; //decrement its frequency
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ", output[i]);
    }

    return 0;
}
