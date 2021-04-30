#include "graph.h"
#include "heap.h"
/**
 * TODO:   Implementati o functie care citeste dintr-un fisier de intrare
 * nr-ul de varfuri, muchii, iar pe urmatoarele linii
 * nod u, nod v si distanta[u][v], pentru a putea reprezenta ulterior matricea de adiacenta
 * @param  input: fisierul de intrare
 * @note   -Atentie! Nu redeschideti fisierul de intrare
 * @retval - Graful in reprezentarea matrice de adiacenta
 */
Graph *createGraph(FILE *input)
{
    int u = 0, v = 0;
    Graph *g = (Graph *)malloc(sizeof(Graph));
    fscanf(input, "%d%d", &(g->V), &(g->E));
    g->mat = (int **)calloc(g->V, sizeof(int *));
    for (int i = 0; i < g->V; i++)
        g->mat[i] = (int *)calloc(g->V, sizeof(int));
    for (int i = 0; i < g->E; i++)
    {
        fscanf(input, "%d%d", &(u), &(v));
        fscanf(input,"%d",&g->mat[u][v]);
        g->mat[v][u]=g->mat[u][v];
    }
    return g;
}
/**
 * TODO: Implementati functia de afisare a matricei de adiacenta
 * @param  g: graful creat anterior
 * @note : Nice to have
 * @retval - None
 */
void printMat(Graph *g)
{
    for (int i = 0; i < g->V; i++)
    {
        for (int j = 0; j < g->V; j++)
            printf("%d ", g->mat[i][j]);
        printf("\n");
    }
}