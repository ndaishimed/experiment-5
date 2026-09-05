#include <stdio.h>
void bucketSort(float arr[], int n){
    float buckets[10][100];
    int count[10] = {0};
    int i, j, k;
    float temp;
    for (i = 0; i < n; i++){
        int index = (int)(arr[i] * 10);
        buckets[index][count[index]] = arr[i];
        count[index]++;
    }
    for (i = 0; i < 10; i++){
        for (j = 1; j < count[i]; j++){
            temp = buckets[i][j];
            k = j - 1;
            while (k >= 0 && buckets[i][k] > temp){
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = temp;
        }
    }
    k = 0;
    for (i = 0; i < 10; i++){
        for (j = 0; j < count[i]; j++){
            arr[k] = buckets[i][j];
            k++;
        }
    }
}

int main(){
    float arr[100];
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements (between 0 and 1):\n", n);
    for (i = 0; i < n; i++){
        scanf("%f", &arr[i]);
    }
    bucketSort(arr, n);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++){
        printf("%.2f ", arr[i]);
    }
    return 0;
}
