#include <bits/stdc++.h>
using namespace std;

void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void partition(int arr[], int low, int high, int &i, int &j)
{

    if (high - low <= 1)
    {

        if (arr[high] < arr[low])
        {
            swap(&arr[high], &arr[low]);
        }
        i = low;
        j = high;
        return;
    }

    int mid = low;
    int pivot = arr[high];

    while (mid <= high)
    {

        if (arr[mid] > pivot)
        {
            swap(&arr[mid], &arr[high--]);
        }
        else if (arr[mid] == pivot)
        {
            mid++;
        }
        else if (arr[mid] < pivot)
        {
            swap(&arr[low++],&arr[mid++]);
        }
    }
    i = low - 1;
    j = mid;
}

void sort(int a[], int low, int high)
{

    if (high <= low)
    {
        return;
    }

    int i, j;
    partition(a, low, high, i, j);

    sort(a, low, i);
    sort(a, j, high);
}

int main()
{
    int arr[] = {4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4};
    int size = sizeof(arr) / sizeof(int);
    printArray(arr, size);

    sort(arr, 0, size - 1);

    printArray(arr, size);
    return 0;
}
