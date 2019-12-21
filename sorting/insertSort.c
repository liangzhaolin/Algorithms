#include <stdio.h>

void insertSort(int array[], int size)
{
    int i, j, temp;

    for (i=1; i<size; i++){
        temp = array[i];

        while (j>0 && array[j-1]>temp){
            array[j] = array[j-1];
            j--;
        }
        array[j] = temp;
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {23,3,17,2,11,29,13,5,19,7};

    for (int i=0; i<10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertSort(arr, 10);

    for (int i=0; i<10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
