#include <stdio.h>

void shellSort(int array[], int size)
{
    int i, j;
    int gap;

    for (gap=size/2; gap>0; gap/=2){
        for (i=gap; i<size; i++){
            int temp = array[i];

            j = i;
            while (j-gap>=0 && array[j-gap]>temp){
                array[j] = array[j-gap];
                j-=gap;
            }

            array[j] = temp;
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

    shellSort(arr, 10);

    for (int i=0; i<10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
