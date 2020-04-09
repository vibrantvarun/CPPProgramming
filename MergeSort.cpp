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

void merge(int a[], int low, int mid, int high)
{

    int i, j, k;

    int s = mid - low + 1;
    int t = high - mid;

    int arr1[s], arr2[t];

    for (i = 0; i < s; i++)
    {
        arr1[i] = a[low + i];
    }

    for (j = 0; j < t; j++)
    {
        arr2[j] = a[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = low;

    while (i < s && j < t)
    {

        if (arr1[i] <= arr2[j])
        {
            a[k] = arr1[i];
            i++;
        }
        else
        {
            a[k] = arr2[j];
            j++;
        }

        k++;
    }

    while (i < s)
    {
        a[k] = arr1[i];
        i++;
        k++;
    }

    while (j < t)
    {
        a[k] = arr2[j];
        j++;
        k++;
    }
}

void sort(int a[], int low, int high)
{
    if (low < high)
    {

        int m = low + (high - low) / 2;

        sort(a, low, m);
        sort(a, m + 1, high);

        merge(a, low, m, high);
    }
}

int main()
{
    int arr[] = {2, 5, 3, 6, 1, 9, 4, 6, 82};

    printArray(arr, sizeof(arr) / sizeof(int));

    sort(arr, 0, (sizeof(arr) / sizeof(int)) - 1);

    printArray(arr, sizeof(arr) / sizeof(int));

    return 0;
}