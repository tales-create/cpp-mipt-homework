#include <stdio.h>

void reverse(int array[], int size)
{
    for (int i = 0; i < size / 2; ++i)
    {
        int temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
}

void print_array(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int arr1[] = {10, 20, 30, 40, 50};
    reverse(arr1, 5);
    print_array(arr1, 5);

    int arr2[] = {60, 20, 80, 10};
    reverse(arr2, 4);
    print_array(arr2, 4);

    return 0;
}