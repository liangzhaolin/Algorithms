#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int array[], int left, int right)
{
    int temp = array[left];

    while (left < right)
    {
        while (left<right && array[right]>temp){
            right--;
        }
        array[left] = array[right];

        while (left<right && array[left]<temp){
            left++;
        }
        array[right] = array[left];
    }

    array[left] = temp;

    return left;    
}

void quickSort(int array[], int left, int right)
{
    if (left < right){
        int pos = partition(array, left, right);

        quickSort(array, left, pos-1);
        quickSort(array, right, right);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {23,3,17,2,11,29,13,5,19,7};

    for (int i=0; i<10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, 9);

    for (int i=0; i<10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
