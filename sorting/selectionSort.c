#include <stdio.h>

void selectionSort(int array[], int size)
{
    int i, j, min;

    for (i=0; i<size-1; i++){
        min = i;

        for (j=i+1; j<size; j++){
            if (array[min] > array[j]){
                min = j;
            }
        }

        if (min != i){
            int temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {23,3,17,2,11,29,13,5,19,7};

    for (int i=0; i<10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    selectionSort(arr, 10);

    for (int i=0; i<10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
