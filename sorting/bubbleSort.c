#include <stdio.h>

void bubbleSort(int array[], int size)
{
    int i, j;

    for (i=0; i<size; i++){
        for (j=0; j<size-i-1; j++){
            if (array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp; 
            }
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

    bubbleSort(arr, 10);

    for (int i=0; i<10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
