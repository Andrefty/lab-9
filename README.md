<h1 align="center">
    lab-09: Grafuri - Drumuri de cost minim
  </h1>

## Cerinte:
1. Implementati o functie care creeaza si populeaza cu date un graf pe baza unei matrice de adiacenta.
2. Implementati algoritmul Dijkstra folosindu-va de minHeap si de structura DijkstraPath (pentru instantierea & popularea vectorului de distante/predecesori).
3. Implementati algoritmul Floyd-Warshall. (Complexitate O(n³))

#### Puteti afla mai multe legat de modul de lucru [aici](https://github.com/sda-ab/student-setup#indicatii-rezolvare-laborator)

## Observatii:
  - **teste:**
    - Comanda **make test** va rula toate testele.
    - Comanda **make test-cX** (unde **X** e nr. cerintei: **1, 2, 3**) va rula testele doar pentru cerinta **X**.
    - Comanda **make single-run** va rula main-ul.
    - Comanda **make test-heap** va rula testul pentru **heap.c**.
    - Testul pentru **cerinta 2** va rula automat si testul pentru **heap.c**.
    - Pentru debug pe testul de heap, exista in folderul tests fisierul "heap_debug.txt" verificarile pentru fiecare insert si delete pana la primul mismatch.
  - **implementare**
    - Vectorul poz va fi initializat cu -1 pe intreaga capacitate, iar la structura DijkstraPath , vectorul pred trebuie initializat tot cu -1.
    - La deleteNode, dupa ce se elimina radacina, trebuie actualizata pozitia din vectorul poz cu -1.
    - In header-ul "graph.h" au fost definite valorile INF_MAX si INF_MIN pe care le puteti utiliza daca aveti nevoie in implementare.
    - In printPath se va afisa drumul fara nodul sursa, dar cu destinatia inclusiv.
## Structuri folosite:
```c
//graph.h
typedef struct{
    int V;     //nr varfuri
    int E;     //nr muchii
    int **mat; //matrice de adiacenta
} Graph;

typedef struct{
    int *dist; //vectorul de distante minime fata de nodul sursa
    int *pred; //vectorul de predecesori
} DijkstraPath;

//heap.h
typedef struct{
    int v;        // nod
    int distanta; // distanta pana la nodul v de la un nod dat
} HeapNode;

typedef struct{
    int size;
    int capacity;
    int *poz;       //vectorul de pozitii ale elementelor din MinHeap
    HeapNode **arr; //vectorul cu distantele minime pana in mom respectiv
} MinHeap;
```
