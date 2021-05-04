#include "graph.h"
#include "heap.h"
/**
 * TODO:   Implementati algoritmul Floyd-Warshall pentru un graf cu matricea de adiacenta data
 * @param  g: graful dat
 * @retval - Matricea costurilor pentru toate nodurile
 */
int **Floyd_Warshall(Graph *g)
{
    int **c = (int **)calloc(g->V, sizeof(int *));
    int i, j, z;
    for (i = 0; i < g->V; i++)
    {
        c[i] = (int *)calloc(g->V, sizeof(int));
        for (j = 0; j < g->V; j++)
            if (g->mat[i][j] != 0)
                c[i][j] = g->mat[i][j];
            else
                c[i][j] = 99999;
    }
    for (z = 0; z < g->V; z++)
        for (i = 0; i < g->V; i++)
            for (j = 0; j < g->V; j++)
                if (c[i][j] > c[i][z] + c[z][j])
                    c[i][j] = c[i][z] + c[z][j];
    return c;
}