#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 15


void shellSort(int A[])
{
    printf("Before Sort: ");
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");

    printf("\n <<<<<<<<<< shell Sorting... >>>>>>>>>\n");

    for(int gap = 5; gap >= 1; gap -=2)
    {
        for(int i = gap; i <= N-1; i++)
        {
            int key = A[i];
            int j = i;
            while(j >= gap && A[j-gap] >key)
            {
                A[j] = A[j - gap];
                j -= gap;                
            }

            A[j] = key;
        }
    }

        for(int i = 0; i < N; i++)
            printf("%d ", A[i]);
        printf("\n");

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

int main(void)
{
    int A[N];

    srand(time(NULL));
    for(int i = 0; i < N; i++)
        A[i] = rand()%100;

    shellSort(A);
    
}