/*
 * Projeto 4 - RankLab: Central de Ordenacao Inteligente
 * Algoritmos e Pensamento Computacional | Prof. Vinicius Alves
 *
 * Integrantes: 
 *
 */

#include <stdio.h>

#define N 10

void exibirCabecalho(void);
void lerPontuacoes(int v[], int n);
void copiarVetor(int origem[], int destino[], int n);
void exibirVetor(int v[], int n);
int bubbleSort(int v[], int n);
int selectionSort(int v[], int n);
int insertionSort(int v[], int n);
int vetoresIguais(int a[], int b[], int n);

int main(void)
{
    int pontuacoes[N];
    int bubble[N], selection[N], insertion[N];
    int compBubble, compSelection, compInsertion;
    int menor, maior;
    double mediana;
    int iguais;

    exibirCabecalho();
    lerPontuacoes(pontuacoes, N);

    copiarVetor(pontuacoes, bubble, N);
    copiarVetor(pontuacoes, selection, N);
    copiarVetor(pontuacoes, insertion, N);

    compBubble = bubbleSort(bubble, N);
    compSelection = selectionSort(selection, N);
    compInsertion = insertionSort(insertion, N);

    printf("\nOriginal:  ");
    exibirVetor(pontuacoes, N);
    printf("Bubble:    ");
    exibirVetor(bubble, N);
    printf("Selection: ");
    exibirVetor(selection, N);
    printf("Insertion: ");
    exibirVetor(insertion, N);

    iguais = vetoresIguais(bubble, selection, N) &&
             vetoresIguais(selection, insertion, N);
    printf("\nResultados equivalentes: %s\n", iguais ? "SIM" : "NAO");

    menor = bubble[0];
    maior = bubble[N - 1];
    mediana = (bubble[4] + bubble[5]) / 2.0;
    printf("Menor: %d | Maior: %d | Mediana: %.2f\n", menor, maior, mediana);

    printf("Comparacoes: Bubble %d | Selection %d | Insertion %d\n",
           compBubble, compSelection, compInsertion);
    printf("=============================\n");

    return 0;
}

void exibirCabecalho(void)
{
    printf("========== RANKLAB ==========\n");
}

void lerPontuacoes(int v[], int n)
{
    int i, valor, lidos, c;

    printf("Digite %d pontuacoes entre 0 e 100:\n", n);
    for (i = 0; i < n; i++) {
        lidos = scanf("%d", &valor);
        if (lidos == EOF) {
            printf("Entrada encerrada antes do esperado.\n");
            return;
        }
        if (lidos != 1) {
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            printf("Entrada invalida. Digite um numero entre 0 e 100.\n");
            i--;
        } else if (valor < 0 || valor > 100) {
            printf("Valor %d invalido. Digite um numero entre 0 e 100.\n", valor);
            i--;
        } else {
            v[i] = valor;
        }
    }
}

void copiarVetor(int origem[], int destino[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        destino[i] = origem[i];
}

void exibirVetor(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}
int bubbleSort(int v[], int n)
{
    int i, j, aux, comparacoes = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            comparacoes++;
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
    return comparacoes;
}

int selectionSort(int v[], int n)
{
    int i, j, menor, aux, comparacoes = 0;

    for (i = 0; i < n - 1; i++) {
        menor = i;
        for (j = i + 1; j < n; j++) {
            comparacoes++;
            if (v[j] < v[menor])
                menor = j;
        }
        if (menor != i) {
            aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
        }
    }
    return comparacoes;
}

int insertionSort(int v[], int n)
{
    int i, j, chave, comparacoes = 0;

    for (i = 1; i < n; i++) {
        chave = v[i];
        j = i - 1;
        while (j >= 0) {
            comparacoes++;
            if (v[j] > chave) {
                v[j + 1] = v[j];
                j--;
            } else {
                break;
            }
        }
        v[j + 1] = chave;
    }
    return comparacoes;
}
int vetoresIguais(int a[], int b[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        if (a[i] != b[i])
            return 0;
    }
    return 1;
}
