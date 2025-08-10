#include <stdio.h>
#include <string.h>

//Converts the HH/MM string to integer
int parseInt(char val[]) {
    
    int min = 0;
    for (int i = 0; i < strlen(val); i++) {
        min = min * 10 + ((int) val[i] - '0');
    }
    
    return min;
}

//Function to take the HH and MM part and convert them to integer and process the data into "times" array
void convertToMin(char dur[][6], int times[], int n) {
    
    for (int i = 0; i < n; i++) {
        char HH[3]; strncpy(HH, dur[i], 2); HH[2] = '\0';
        char MM[3]; strncpy(MM, dur[i]+3, 2); MM[2] = '\0';
        int hour = parseInt(HH) * 60;
        int min = parseInt(MM);
        times[i] = hour+min;
    }
    
}

int partition(int times[], int s, int e) {
    
    int pivot = times[e];
    int i = s-1;
    
    for (int j = s; j < e; j++) {
        if (times[j] < pivot) {
            int temp = times[i+1];
            times[i+1] = times[j];
            times[j] = temp;
            i++;
        }
    }
    int temp = times[i+1];
    times[i+1] = pivot;
    times[e] = temp;
    
    return i+1;
}

void quickSort(int times[], int s, int e) {
    
    if (s >= e) {
        return;
    }
    
    int idx = partition(times, s, e);
    quickSort(times, s, idx-1);
    quickSort(times, idx+1, e);
}

int main() {
    
    int n; scanf("%d", &n);
    char dur[n][6];
    
    for (int i = 0; i < n; i++) {
        scanf(" %s", dur[i]);
    }
    
    int times[n]; convertToMin(dur, times, n);
    
    quickSort(times, 0, n-1);
    
    int min = 1440;

    //Finding the least difference in time
    for (int i = 1; i < n; i++) {
        if (times[i] - times[i-1] < min) {
            min = times[i] - times[i-1];
        }
    }
    
    //Displaying the result of minimum value b/w min and 1440-min since the output requires it in that way 
    min = (min > (1440-min)) ? 1440-min : min;
    printf("The time difference is: %d", min);
    
    return 0;
}
