#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *fin;
FILE *fout;

typedef struct _Queue {
	int* key;
	int first, rear, qsize, max_queue_size;
}Queue;

typedef struct _Graph {
	int size;
	int* node;
	int** matrix;
}Graph;

Graph* CreateGraph(int* nodes, int n);
void InsertEdge(Graph* G, int a, int b);
void DeleteGraph(Graph* G);
int* Topsort(Graph* G);
Queue* MakeNewQueue(int X);
int IsEmpty(Queue* Q);
int Dequeue(Queue* Q);
void Enqueue(Queue* Q, int X);
void DeleteQueue(Queue* Q);
int InDegree(Graph* G, int num);
int Location(Graph* G, int num);
void countInput(int* n, char* str) {
	int len = strlen(str), i;
	for (i = 0; i < len; i++)
		if (0 <= str[i] - '0' && str[i] - '0' < 10) (*n)++;
}

void parseInput(int* arr, char* str, int n) {
	int len = strlen(str), i;
	int cnt = 0;
	for (i = 0; i < len; i++)
	if (0 <= str[i] - '0' && str[i] - '0' < 10) arr[cnt++] = str[i] - '0';
}

int main(int argc, char* agrv[]) {
	fin = fopen(agrv[1], "r");
	fout = fopen(agrv[2], "w");

	char numbers[100], inputs[150];
	fgets(numbers, 100, fin);
	int n = 0;
	countInput(&n, numbers);
	int* nodes = (int*)malloc(sizeof(int)*n);
	int* sorted_arr = NULL;
	parseInput(nodes, numbers, n);

	Graph* G = CreateGraph(nodes, n);

	fgets(inputs, 100, fin);
	int len = strlen(inputs), i, j;
	for (i = 0; i < len; i += 4) {
		int a = inputs[i] - '0', b = inputs[i + 2] - '0';
		InsertEdge(G, a, b);
	}

	// PrintGraph(G);
	fprintf(fout, "%-3s", " ");
	for (i = 0; i < G->size; i++) fprintf(fout, "%-3d", G->node[i]);
	fprintf(fout, "\n");
	for (i = 0; i < G->size; i++) {
		fprintf(fout, "%-3d", G->node[i]);
		for (j = 0; j < G->size; j++) fprintf(fout, "%-3d", G->matrix[i][j]);
		fprintf(fout, "\n");
	}
	fprintf(fout, "\n");

	sorted_arr = Topsort(G);
	if(sorted_arr == NULL){
		fprintf(fout, "sorting error : cycle!");
	}else{
		for(i = 0; i < G->size; i ++)
			fprintf(fout, "%d ", sorted_arr[i]);
		fprintf(fout, "\n");
	}
	free(sorted_arr);
	DeleteGraph(G);

	fclose(fin);
	fclose(fout);

	return 0;
}

/*
Create new graph with given nodes and the count of nodes.
saved nodes should be sorted.
return: 
        the pointer of new graph
 */
Graph* CreateGraph(int* nodes, int n) {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->size = n;
	for(int i = 1;i < n;++i){
		for(int j = 0;j < n - i;++j){
			if(nodes[j] > nodes[j + 1]){
				int tmp = nodes[j];
				nodes[j] = nodes[j + 1];
				nodes[j + 1] = tmp;
			}
		}
	}
	graph->node = nodes;
	graph->matrix = (int**)malloc(sizeof(int*) * n);
	for(int i = 0;i < n;++i){
		graph->matrix[i] = (int*)malloc(sizeof(int) * n);
	}
	return graph;
}
/*
Insert edge from a to b in the graph.
*/
void InsertEdge(Graph* G, int a, int b) {
	int start, end;
	for(int i = 0;i < G->size;++i){
		if(G->node[i] == a){
			start = i;
		}
		if(G->node[i] == b){
			end = i;
		}
	}
	G->matrix[start][end] = 1;
}
/*
Deallocate the memory of the graph G.
*/
void DeleteGraph(Graph* G){
	free(G->node);
	for(int i = 0;i < G->size;++i){
		free(G->matrix[i]);
	}
	free(G->matrix);
	free(G);
}

/*
Topological sort
If two or more nodes have same priority,
    the node with the smaller number takes precedence.
return:
    the array of sorted
    NULL if the graph has a cycle
*/
int* Topsort(Graph* G){
	int* sorted_arr = (int*)malloc(sizeof(int) * G->size);
	Queue* queue = MakeNewQueue(G->size);
	int chk = 0;
	//Check 0 indegree
	for(int i = 0;i < G->size;++i){
		if(InDegree(G, i) == G->size){
			Enqueue(queue, G->node[i]);
			chk += 1;
		}
	}
	//It means cycle that does not have 0 indegree key
	if(!chk){
		return NULL;
	}
	for(int j = 0;j < G->size;++j){
		sorted_arr[j] = Dequeue(queue);
		int num = -1;
		for(int h = 0;h < G->size;++h){
			if(G->matrix[Location(G, sorted_arr[j])][h]){
				if(num == -1){
					num = h;
				}else{
					if(InDegree(G, num) < InDegree(G, h)){
						num = h;
					}
				}
			}
		}
		if(num != -1){
			Enqueue(queue, G->node[num]);
			for(int m = 0;m < G->size;++m){
				G->matrix[Location(G, sorted_arr[j])][m] = 0;
			}
		}
	}
	return sorted_arr;	
}

/*
Create new Queue with maximum size X
return:
        the pointer of new queue
*/
Queue* MakeNewQueue(int X){
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->key = (int*)malloc(sizeof(int) * X);
	queue->first = 0;
	queue->rear = -1;
	queue->qsize = 0;
	queue->max_queue_size = X;
	return queue;
}
/*
Check the queue either is empty or not.
return:
        1, empty
        0, non-empty
*/
int IsEmpty(Queue* Q){
	if(!Q->qsize){
		return 1;
	}
	return 0;
}
/*
pop the front key in queue
return:
        the front key in queue
*/
int Dequeue(Queue* Q){
	if(!IsEmpty(Q)){
		Q->qsize -= 1;
		return Q->key[Q->first++];
	}
}
/*
push the key in queue
*/
void Enqueue(Queue* Q, int X){
	if(Q->qsize < Q->max_queue_size){
		if(!IsEmpty(Q)){
			for(int i = Q->first;i <= Q->rear;++i){
				if(Q->key[i] == X){
					return;
				}
			}
		}
		Q->qsize++;
		Q->key[++Q->rear] = X;
	}
}

/*
Deallocate the memory of the queue
*/
void DeleteQueue(Queue* Q){
	free(Q->key);
	free(Q);
}

/*
Count number ofIndegree
*/
int InDegree(Graph* G, int num){
	int chk = 0;
	for(int i = 0 ;i < G->size;++i){
		if(!G->matrix[i][num]){
			chk += 1;
		}
	}
	return chk;
}

/*
Check the location of key
*/
int Location(Graph* G, int num){
	for(int i = 0;i < G->size;++i){
		if(num == G->node[i]){
			return i;
		}
	}
}
