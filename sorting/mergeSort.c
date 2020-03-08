#include <stdio.h>
#include <stdlib.h>

void merge(int array[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;

    int *temp = (int *)malloc((high-low+1)*sizeof(int));

    while (i<=mid && j<=high)
    {
        if (array[i] < array[j]){
            temp[k++] = array[i++];
        }
        else {
            temp[k++] = array[j++];
        }
    }

    while (i <= mid){
        temp[k++] = array[i++];
    }

    while (j <= high){
        temp[k++] = array[j++];
    }

    for (i=low, j=0; j<high-low+1; i++, j++){
        array[i] = temp[j];
    }

    free(temp);
}

void mergeSort(int array[], int low, int high)
{
    if (low < high){
        int mid = (low + high)/2;

        mergeSort(array, low, mid);
        mergeSort(array, mid+1, high);
        merge(array, low, mid, high);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {23,3,17,2,11,29,13,5,19,7};

    for (int i=0; i<10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr, 0, 9);

    for (int i=0; i<10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
