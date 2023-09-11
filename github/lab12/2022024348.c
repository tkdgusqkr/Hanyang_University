#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INF 1e9

FILE *fin;
FILE *fout;

typedef struct Node {
	int vertex;
	int dist;	//distance
	int prev;
}Node;

typedef struct Graph {
	int size;
	int** vertices;
	Node* nodes;
}Graph;

typedef struct Heap {
	int Capacity;
	int Size;
	Node* Element;
}Heap;

Graph* createGraph(int size);
void deleteGraph(Graph* g);
void dijkstra(Graph* g);
int* shortestPath(Graph* g, int dest);
Heap* createMinHeap(int heapSize);
void deleteMinHeap(Heap* minHeap);
void insertToMinHeap(Heap* minHeap, int vertex, int distance);
Node* deleteMin(Heap* minHeap);

void swap(Node* node1, Node* node2) {
	Node temp = *node1;
	*node1 = *node2;
	*node2 = temp;
}

void main(int argc, char *argv[]) {
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");

	Graph* g;
	int size;
	fscanf(fin, "%d\n", &size);
	g = createGraph(size + 1);

	char tmp = 0;
	while (tmp != '\n' && tmp != EOF) {
		int node1, node2, weight;
		fscanf(fin, "%d-%d-%d", &node1, &node2, &weight);
		g->vertices[node1][node2] = weight;
		tmp = fgetc(fin);
	}

	dijkstra(g);

	int j;
	for(int i = 2; i < g->size; i++){
		int* path = shortestPath(g, i);
		if(path == NULL){
			fprintf(fout, "can not reach to node %d\n", i);
			continue;
		}
		for (j = g->size - 1; j > 0; j--){
			if(path[j] == 0) continue;
			fprintf(fout, "%d->", path[j]);
		} 
		fprintf(fout, "%d (cost : %d)\n", i, g->nodes[i].dist);
		free(path);
	}
	deleteGraph(g);
}
/*
Allocate Graph Matrix

Initial distance: INF except 1st node (source)
Initial prev: -1
*/
Graph* createGraph(int size) {
	Graph* g = (Graph*)malloc(sizeof(Graph));
	g->size = size;
	g->vertices = (int**)malloc(sizeof(int*) * size);
	for(int i = 0;i < size;++i){
		g->vertices[i] = (int*)malloc(sizeof(int) * size);
	}
	g->nodes = (Node*)malloc(sizeof(Node) * size);
	for(int i = 0;i < size;++i){
		g->nodes[i].vertex = i;
		g->nodes[i].dist = INF;
		g->nodes[i].prev = -1;
	}
	return g;
}
// deallocate graph
void deleteGraph(Graph* g){
	free(g->nodes);
	for(int i = 0;i < g->size;++i){
		free(g->vertices[i]);
	}
	free(g->vertices);
	free(g);
}
/*
Allocate min heap
*/ 
Heap* createMinHeap(int heapSize) {
	Heap* H = (Heap*)malloc(sizeof(Heap));
	H->Capacity = heapSize;
	H->Size = 0;
	H->Element = (Node*)malloc(sizeof(Node) * heapSize);
	H->Element[0].vertex = 0;
	H->Element[0].dist = -1;
	H->Element[0].prev = -1;
	return H;
}
/*
Deallocate min heap
*/
void deleteMinHeap(Heap* minHeap){
	free(minHeap->Element);
	free(minHeap);
}
/*
Dijkstra Algorithm
*/
void dijkstra(Graph* g){
	g->nodes[1].dist = 0;
	for(int i = 1;i < g->size;++i){
		if(g->vertices[1][i]){
			g->nodes[i].dist = g->vertices[1][i];
			g->nodes[i].prev = 1;
		}
	}
	Heap* H = createMinHeap(g->size);
	for(int i = 1;i < g->size;++i){
		insertToMinHeap(H, i, g->nodes[i].dist);
	}
	while(H->Size > 0){
		Node* node = deleteMin(H);
		for(int i = 1;i < g->size;++i){
			if(g->vertices[node->vertex][i]){
				if(g->nodes[node->vertex].dist + g->vertices[node->vertex][i] < g->nodes[i].dist){
					g->nodes[i].dist = g->nodes[node->vertex].dist + g->vertices[node->vertex][i];
					g->nodes[i].prev = node->vertex;
				}
			}
		}
		free(node);
	}
}
/*
Return shortest path from source(1) to dest(i)
Return type is array and the size is the number of node.
You should save the path reversely. 
For example, If shortest path is 1->2->3 
and the number of node(g->size) is 5,
you must return [3, 2, 1 , 0, 0]
If there is no path, return NULL 
*/
int* shortestPath(Graph* g, int dest){
	if(g->nodes[dest].prev == -1 && dest != 1){//Except 1
		return NULL;
	}
	int* path = (int*)malloc(sizeof(int) * g->size);
	for(int i = 0;i < g->size;++i){
		path[i] = g->nodes[dest].vertex;
		dest = g->nodes[dest].prev;
	}
	return path;
}
/*
Insert Node with vertex and distance into minHeap
*/
void insertToMinHeap(Heap* minHeap, int vertex, int distance) {
	if(minHeap->Size >= minHeap->Capacity){
		return;
	}
	int i;
	for(i = ++minHeap->Size;minHeap->Element[i / 2].dist > distance;i /= 2){
		minHeap->Element[i].vertex = minHeap->Element[i / 2].vertex;
		minHeap->Element[i].dist = minHeap->Element[i / 2].dist;
		minHeap->Element[i].prev = minHeap->Element[i / 2].prev;
	}
	minHeap->Element[i].vertex = vertex;
	minHeap->Element[i].dist = distance;
}
/*
pop the Node with minimum distance from minHeap
return:
	Node with minimum distance
*/
Node* deleteMin(Heap *minHeap) {
	//Delete and modificate.
	Node* min = (Node*)malloc(sizeof(Node));
       	min->vertex = minHeap->Element[1].vertex;
       	min->dist = minHeap->Element[1].dist;
       	min->prev = minHeap->Element[1].prev;
	int lastIndex = minHeap->Size--;
	int i, next;
	for(i = 1;i * 2 <= minHeap->Size;i = next){
		next = i * 2;
		if(next < minHeap->Size && minHeap->Element[next + 1].dist < minHeap->Element[next].dist){
			next += 1;
		}
		if(minHeap->Element[lastIndex].dist > minHeap->Element[next].dist){
			minHeap->Element[i].vertex = minHeap->Element[next].vertex;
			minHeap->Element[i].dist = minHeap->Element[next].dist;
			minHeap->Element[i].prev = minHeap->Element[next].prev;
		}else{
			break;
		}
	}
	minHeap->Element[i].vertex = minHeap->Element[lastIndex].vertex;
	minHeap->Element[i].dist = minHeap->Element[lastIndex].dist;
	minHeap->Element[i].prev = minHeap->Element[lastIndex].prev;
	return min;
}

