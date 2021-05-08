#include "graph.h"
#include "heap.h"

/**
 * TODO:   Implementati Algoritmul Dijkstra folosindu-va de MinHeap-ul creat in fisierul heap.c
 * @param  g: graful dat
 * @param source : varful sursa pentru care se aplica algoritmul
 * @retval None
 */

DijkstraPath *Dijkstra(Graph *g, int source)
{
    HeapNode *u, *sursa = createHeapNode(source, 0), *aux;
    DijkstraPath *n = (DijkstraPath *)calloc(1, sizeof(DijkstraPath));
    n->dist = (int *)calloc(g->V, sizeof(int));
    n->pred = (int *)calloc(g->V, sizeof(int));
    MinHeap *h = create(g->V);
    for (int i = 0; i < g->V; i++)
    {
        n->pred[i] = -1;
        n->dist[i] = 99999;
    }
    n->dist[source] = 0;
    n->pred[source] = -1;
    insert(h, sursa);
    // for (int i = 0; i < g->V; i++)
    // {
    //     for (int j = 0; j < g->V; j++)
    //     {
    //         if (g->mat[i][j] != 0)
    //             aux = createHeapNode(j, g->mat[i][j]);
    //         insert(h, aux);
    //     }
    // }

    while (h->size)
    {
        // iau varful cu distanta minima pana la sursa dintre varfurile care nu sunt in sps
        u = deleteNode(h);
        // printf("%d\n", u->v);
        //incep sa il procesez// Updatez valoarea distantei pentru fiecare varf adiacent cu u
        for (int i = 0; i < g->V; i++)
        {
            // Updatez dist[i] daca varful i nu e in sps, daca u si i adiacente si
            //daca distanta pe noua ruta e mai mica decat cea stocata anterior
            if (g->mat[u->v][i] != 0 &&
                n->dist[u->v] != 99999 && n->dist[u->v] + g->mat[u->v][i] < n->dist[i])
            {
                n->dist[i] = n->dist[u->v] + g->mat[u->v][i];
                aux = createHeapNode(i, n->dist[i]);
                insert(h, aux);
                n->pred[i] = u->v;
            }
        }
    }
    return n;
}

/**
 * TODO:   Implementati Algoritmul Dijkstra folosindu-va de MinHeap-ul creat in fisierul heap.c
 * @param vectorPath : vectorul cailor
 * @param index : [optional pentru recursivitate]
 * @param vector_precedesori : vectorul de predecesori 
 * @param destinatie : varful destinatie pentru care se cauta path-ul
 * @param output : fisierul in care se face scrierea vectorului de predecesori (path.txt)
 * @note : se poate implementa atat recursiv, cat si iterativ
 *         nu mai trebuie facute alocari pentru vectorPath, vector_predecesori
 *         fisierul de output este deschis 
 * @retval None
 */
void printPath(int *vectorPath, int index, int *vector_precedesori, int destinatie, FILE *output)
{
    // for (int i = 0; i < destinatie; i++)
    // {
        
    // }
    if(index==-1) return;
    vectorPath[index]=destinatie;
    fprintf(output,"%d ",vectorPath[index]);
    printPath(vectorPath,index-1,vector_precedesori,vector_precedesori[destinatie],output);
    
}
