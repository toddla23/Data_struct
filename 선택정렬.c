#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 15

void swap(int A[], int i, int min)
{
    int temp = A[min];
    A[min] = A[i];
    A[i] = temp;

}

void swap1(int A[], int j)
{
    int temp = A[j-1];
    A[j-1] = A[j];
    A[j] = temp;

}

void bubbleSort(int A[])
{
    printf("Before Sort: ");
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");

    printf("\n <<<<<<<<<< Bubble Sorting... >>>>>>>>>\n");

    for(int i = 1; i < N; i++)
    {
        for(int j = 1; j <= N-i; j++)
        {
            if(A[j-1] > A[j])
                swap1(A, j);
        }
        printf(" %d Pass >> ", i);
        for(int i = 0; i < N; i++)
            printf("%d ", A[i]);
        printf("\n");
    }
    
}

void insertionSort(int A[])
{
    printf("Before Sort: ");
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");

    printf("\n <<<<<<<<<< Insertion Sorting... >>>>>>>>>\n");

    for(int i = 1; i <= N-1; i++)
    {
        int key = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > key)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;

        
        for(int i = 0; i < N; i++)
            printf("%d ", A[i]);
        printf("\n");


    }


}

void selectionSort(int A[])
{
    printf("Before Sort: ");
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");

    printf("\n <<<<<<<<<< Selection Sorting... >>>>>>>>>\n");

    for(int i = 0; i <= N-2; i++)
    {
        int min = i;
        for(int j = i+1; j <= N-1; j++)
            if(A[j] < A[min])
                min = j;

        swap(A, i, min);

        printf(" %d Pass >> ", i+1);
        for(int i = 0; i < N; i++)
            printf("%d ", A[i]);
        printf("\n");

    }

    printf("After Sort: ");
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");

}

int main(void)
{
    int A[N];

    srand(time(NULL));
    for(int i = 0; i < N; i++)
        A[i] = rand()%100;

    bubbleSort(A);
    
}