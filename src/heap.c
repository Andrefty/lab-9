#include "heap.h"
/**
 * TODO: Implementati functia de creare MinHeap avand o capacitate data
 * @param  capacitate: capacitatea heap-ului
 * @retval - heap-ul creat
 */
MinHeap *create(int capacitate)
{
	MinHeap *h = (MinHeap *)malloc(sizeof(MinHeap));
	h->size = 0;
	h->capacity = capacitate;
	h->poz = (int *)malloc(sizeof(int) * h->capacity);
	for (int i = 0; i < h->capacity; i++)
		h->poz[i] = -1;
	h->arr = (HeapNode **)calloc(h->capacity, sizeof(HeapNode *));
	// for (int i = 0; i < h->capacity; i++)
	// {
	// 	h->arr[i] = (HeapNode *)calloc(1, sizeof(HeapNode));
	// 	h->arr[i]->distanta=INT_MAX;
	// }

	return h;
}

/**
 * TODO: Implementati functia de creare HeapNode 
 * @param  v:  varful care trebuie adaugat
 * @param dist: distanta rezultata in urma implementarii algoritmului Dijkstra
 * @retval - HeapNode-ul creat
 */
HeapNode *createHeapNode(int v, int dist)
{
	HeapNode *n = (HeapNode *)calloc(1, sizeof(HeapNode)); // doar pt testat daca trebuie vectorul declarat deja maxim
	n->v = v;
	n->distanta = dist;
	return n;
}

/**
 * TODO: Implementati functia de returnare a index-ului
 * parintelui unui nod din MinHeap
 * @param  heap: MinHeap-ul
 * @param  i: index-ul copilului
 * @retval - parintele copilului i
 */

int parent(MinHeap *heap, int i)
{
	if (i > heap->size - 1 || i <= 0)
		return -1;
	return (i - 1) / 2;
}
/**
 * TODO:  Implementati functia de returnare a index-ului
 * copilului stang al unui nod
 * @param  heap: MinHeap-ul
 * @param  i: parintele i
 * @retval - copilul din stanga al parintelui i
 */

int leftChild(MinHeap *heap, int i)
{
	int poz = 2 * i + 1;
	if (poz > heap->size - 1 || i < 0)
		return -1;
	return poz;
}

/**
 * TODO:  Implementati functia de returnare a index-ului
 * copilului drept al unui nod
 * @param  heap: MinHeap-ul
 * @param  i: parintele i
 * @retval - copilul din dreapta al parintelui i
 */
int rightChild(MinHeap *heap, int i)
{
	int poz = 2 * i + 2;
	if (poz > heap->size - 1 || i < 0)
		return -1;
	return poz;
}

/**
 * TODO: Implementati functia de returnare a radacinii
 * unui heap   
 * @param  heap: MinHeap-ul
 * @retval - HeapNode-ul in care este stocata radacina
 */
HeapNode *returnRoot(MinHeap *heap)
{
	if (heap->size)
		return heap->arr[0];
}

/**
 * TODO: Implementati functia heapify
 * @param  heap: MinHeap-ul
 * @param  i: pozitia de pe care se doreste
 * @retval None
 */
void heapify(MinHeap *heap, int i)
{
	int l, r, min;
	HeapNode *aux;
	while (1)
	{
		min = i;
		l = leftChild(heap, i);
		r = rightChild(heap, i);
		if (l != -1 && heap->arr[l]->distanta < heap->arr[min]->distanta)
			min = l;
		if (r != -1 && heap->arr[r]->distanta < heap->arr[min]->distanta)
			min = r;
		if (min != i)
		{
			aux = heap->arr[i];
			heap->arr[i] = heap->arr[min];
			heap->arr[min] = aux;
			i = min;
		}
		else
			break;
	}
}
/**
 * TODO: Implementati functia de redimensionare a MinHeap-ului  
 * @param  heap: MinHeap-ul
 * @retval None
 */
void resize(MinHeap *heap)
{
	HeapNode **v = (HeapNode **)realloc(heap->arr, heap->capacity = heap->capacity * 2);
	int *g = (int *)realloc(heap->poz, heap->capacity = heap->capacity * 2);
	if (v == NULL)
		return;
	if (heap->arr != NULL)
		free(heap->arr);
	heap->arr = v;
	if (g == NULL)
		return;
	if (heap->poz != NULL)
		free(heap->poz);
	heap->poz = g;
}
/**
 * TODO: Implementati functia de inserare a unui nod in heap
 * @param  heap: MinHeap-ul
 * @param  x: HeapNode-ul care urmeaza a fi inserat
 * @retval None
 */

void insert(MinHeap *heap, HeapNode *x)
{

	int i;
	if (heap->size == heap->capacity)
		resize(heap);
	i = heap->size;
	if (heap->poz[x->v] != -1)
	{
		heap->arr[heap->poz[x->v]]->distanta = x->distanta;
		i = heap->poz[x->v];
	}
	else
	{
		// heap->poz[x->v]=heap->size;
		heap->size++;
	}
	for (int z = 0; z < heap->capacity; z++)
		heap->poz[z] = -1;
	while (i > 0 && x->distanta < heap->arr[(i - 1) / 2]->distanta)
	{
		heap->arr[i] = heap->arr[(i - 1) / 2];
		// int tmp=heap->poz[heap->arr[i]->v];
		// heap->poz[heap->arr[i]->v]=heap->poz[heap->arr[(i - 1) / 2]->v];
		// heap->poz[heap->arr[(i - 1) / 2]->v]=tmp;
		i = (i - 1) / 2;
	}
	heap->arr[i] = x;
	for (int j = 0; j < heap->size; j++)
	{
		heap->poz[heap->arr[j]->v] = j;
	}
}

/**
 * TODO: Implementati functia stergere a unui heap
 * @param  h: MinHeap-ul
 * @retval None
 */
void deleteMinHeap(MinHeap **heap)
{
	free((*heap)->poz);
	(*heap)->poz = NULL;
	for (int i = 0; i < (*heap)->capacity; i++)
	{
		free((*heap)->arr[i]);
		(*heap)->arr[i]=NULL;
	}
	free((*heap)->arr);
	(*heap)->arr=NULL;
}
/**
 * TODO: Implementati functia de afisare a unui heap
 * @param  heap: MinHeap-ul
 * @note : se va afisa si pozitia HeapNode-urilor, pe langa componentele HeapNode-ului
 * @retval None
 */
void printHeap(MinHeap *heap)
{
	for (int i = 0; i < heap->capacity; i++)
	{
		printf("%d ", heap->poz[i]);
	}
	printf("\n");
}
/**
 * TODO: Implementati functia de stergere a radacinii
 * @param  heap: MinHeap-ul
 * @retval HeapNode-ul care s-a sters, fosta radacina
 */
HeapNode *deleteNode(MinHeap *heap)
{
	HeapNode *cop = returnRoot(heap);
	heap->poz[heap->arr[0]->v] = -1;
	heap->arr[0] = heap->arr[(heap->size) - 1];
	(heap->size)--;
	heapify(heap, 0);
	for (int z = 0; z < heap->capacity; z++)
		heap->poz[z] = -1;
	for (int j = 0; j < heap->size; j++)
	{
		heap->poz[heap->arr[j]->v] = j;
	}
	return cop;
}
