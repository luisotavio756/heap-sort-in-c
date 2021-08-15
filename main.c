#include <stdio.h>
#include <stdlib.h>

void criarHeap(int * vet, int ini, int fim) {
    int aux = vet[ini];
    int j = ini * 2 + 1;

    while(j <= fim) {
        if(j < fim) {
            if(vet[j] < vet[j + 1]) {
                j = j + 1;
            }
        }

        if(aux < vet[j]) {
            vet[ini] = vet[j];
            ini = j;
            j = 2 * ini + 1;
        }else {
            j = fim + 1;
        }
    }

    vet[ini] = aux;
}

void heapSort(int * vet, int n) {
    int i, aux;

    for(i = (n-1)/2; i >= 0; i--) {
        criarHeap(vet, i, n-1);
    }

    for(i = n - 1; i >= 1; i--) {
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        criarHeap(vet, 0, i-1);
    }
}

void imprimirVetor(int * vet, int tam) {
    printf("\n%d\n", tam);

    int i;
    for(i = 0; i < tam; i++) {
        printf("%d\n", vet[i]);
    }
}


int main(int argc, char *argv[]) {
    FILE *file;
    int * v;
    int numero;
    int cont = 0;
    int tam;

    file = fopen(argv[1], "r");

    if (file != NULL) {
        while (fscanf(file, "%d", &numero) != EOF) {
            if (cont == 0) {
                tam = numero;
                v = (int*)malloc(numero * sizeof(int));
            } else {
                v[cont-1] = numero;
            }

            cont++;
        }

        fclose(file);

        heapSort(v, tam);
        imprimirVetor(v, tam);
    } else {
        fclose(file);

        puts("Invalid file!");
    }

    return 0;
}
