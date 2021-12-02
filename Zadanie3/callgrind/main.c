#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void print_array(int* arr, int SIZE)
{
    printf("[");

    for(int i = 0; i < SIZE; ++i)
    {
        printf("%d, ", arr[i]);
    }

    printf("]\n");
}

void bubble_sort(int* arr, int SIZE)
{
    for(int i = 0; i < SIZE - 1; ++i)
    {
        for(int j = 0; j < SIZE - i - 1; ++j)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        // print_array(arr, SIZE);
    }
}


// Implementacja merge_sortu z: https://www.geeksforgeeks.org/c-program-for-merge-sort/
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
  
    /* create temp arrays */
    int L[n1], R[n2];
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
  
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
  
        merge(arr, l, m, r);
    }
}

int compare(const void* first, const void* second)
{
    return *((const int*)first) > *((const int*)second);
}

int main(void)
{
    srand(time(NULL));

    int arr[100];    
    const int SIZE = sizeof(arr) / sizeof(int);

    for(int i = 0; i < SIZE; ++i)
    {
        arr[i] = rand() % 100 + 1;       
    }

    bubble_sort(arr, SIZE);
    print_array(arr, SIZE);

    qsort(arr, SIZE, sizeof(int), compare);
    print_array(arr, SIZE);

    mergeSort(arr, 0, SIZE - 1);
    print_array(arr, SIZE);
}