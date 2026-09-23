#include <stdio.h>

int count_even(int array[], int size)
{
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (array[i] % 2 == 0)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    printf("%i\n", count_even(arr1, 5));

    int arr2[] = {10, 20, 30, 40};
    printf("%i\n", count_even(arr2, 4));

    int arr3[] = {10, 1};
    printf("%i\n", count_even(arr3, 2));

    return 0;
}