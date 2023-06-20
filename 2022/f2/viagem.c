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

int** achar_rotas_pela_origem_exceto(int** rotas, int rotassz, int* excp, int excpsz, int orig, int* count) {
    int** possiveisrotas = (int**)malloc(sizeof(int));
    
    for(int i = 0; i < rotassz; i++) {
        if(rotas[i][0] != orig) continue;

        if(excp != NULL) {
            int skip = 0;

            for(int j = 0; j < excpsz; j++) {
                if(excp[j] == rotas[i][1]) {
                    skip = 1;
                    break;
                }
            }

            if(skip) return NULL;
        }
        
        (*count)++;
        possiveisrotas = realloc(possiveisrotas, *count);
        possiveisrotas[*count - 2] = rotas[i];    
    }

    *(count)--;
    return possiveisrotas;
}

int achar_melhor_rota(int** rotas, int rotassz, int* excp, int excpsz, int* tempos, int tempossz, int dest, int* valor, int valordisp) {
    if(tempos == NULL)
        tempos = (int*)malloc(sizeof(int));

    for(int i = 0; i < rotassz; i++) {
        (*valor) += rotas[i][3];
        if(*valor > valordisp) break;

        tempossz++;
        tempos = realloc(tempos, tempossz * sizeof(int));
        tempos[tempossz - 1] = rotas[i][2];

        if(rotas[i][1] != dest) {
            if(excp == NULL)
                excp = (int*)malloc(sizeof(int));

            excpsz++;
            excp = realloc(excp, excpsz * sizeof(int));
            excp[excpsz - 1] = rotas[i][0];

            int possiveisrotassz = 0;
            int** possiveisrotas = achar_rotas_pela_origem_exceto(rotas, rotassz, excp, excpsz, rotas[i][0], &possiveisrotassz);
        
            for(int j = 0; j < possiveisrotassz; j++) {
                return achar_melhor_rota(possiveisrotas, possiveisrotassz, excp, excpsz, tempos, tempossz, dest, valor, valordisp);
            }
        } else if(tempossz > 0) {
            selectionSort(tempos, tempossz);
            return tempos[0];
        }
    }

    return -1;
}

int main() {
    int valordisp, numilhas, numrotas, orig, dest;
    scanf("%d %d %d", &valordisp, &numilhas, &numrotas);

    int** rotas = (int**)malloc(numrotas * sizeof(int*));

    for(int i = 0; i < numrotas; i++) {
        rotas[i] = realloc(rotas[i], 4 * sizeof(int));
        scanf("%d %d %d %d", &rotas[i][0], &rotas[i][1], &rotas[i][2], &rotas[i][3]);
    }

    scanf("%d %d", &orig, &dest);

    int possiveisorigenssz = 1;
    int** possiveisorigens = achar_rotas_pela_origem_exceto(rotas, numrotas, NULL, 0, orig, &possiveisorigenssz);
    int valoracc = 0;
    
    int menor_tempo = achar_melhor_rota(possiveisorigens, possiveisorigenssz, NULL, 0, NULL, 0, dest, &valoracc, valordisp);
    printf("%d\n", menor_tempo);
}