#include <stdio.h>
#include <stdlib.h>

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
// Function to perform Selection Sort
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
  
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
  
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
  
        // Swap the found minimum element
        // with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

int ehPonta(int n, int *galho, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        if (galho[i] == n)
            return 1;
    }

    return 0;
}

int main()
{
    int N, C;
    scanf("%d %d", &N, &C);
    
    int **cadeias = (int **)malloc(C * sizeof(int));
    
    int pacientes_zero[N];
    int counter = 0;
    int hash[C];
    int szs[C];

    for (int i = 0; i < C; i++)
    {
        scanf("%d %d", &hash[i], &szs[i]);
        cadeias[i] = realloc(cadeias[i], szs[i] * sizeof(int));

        for (int j = 0; j < szs[i]; j++)
        {
            scanf("%d", &cadeias[i][j]);
        }
    }

    for (int i = 0; i < C; i++)
    {
        int jaFoiPonta = 0;

        for(int j = 0; j < C; j++) {
            if(jaFoiPonta) break;
            jaFoiPonta = ehPonta(hash[i], cadeias[j], szs[j]);
        }

        if(!jaFoiPonta) {
            pacientes_zero[counter] = hash[i];
            counter++;
        }
    }

    selectionSort(pacientes_zero, counter);

    for(int i = 0; i < counter; i++) {
        printf("%d\n", pacientes_zero[i]);
    }

    return 0;
}