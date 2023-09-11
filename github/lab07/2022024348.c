#include<stdio.h>
#include<stdlib.h>
#include<time.h>

FILE *fin;
FILE *fout;

typedef struct _DisjointSet {
	int size_maze;
	int *ptr_arr;
}DisjointSets;

void init(DisjointSets *sets, DisjointSets *maze_print, int num);
void Union(DisjointSets *sets, int i, int j);
int find(DisjointSets *sets, int i);
void createMaze(DisjointSets *sets, DisjointSets *maze_print, int num);
void printMaze(DisjointSets *sets, int num);
void freeMaze(DisjointSets *sets, DisjointSets *maze_print);


int main(int argc, char* agrv[]) {
	srand((unsigned int)time(NULL));

	int num, i;
	fin = fopen(agrv[1], "r");
	fout = fopen(agrv[2], "w");

	DisjointSets *sets, *maze_print;
	fscanf(fin, "%d", &num);

	sets = (DisjointSets*)malloc(sizeof(DisjointSets));
	maze_print = (DisjointSets*)malloc(sizeof(DisjointSets));

	init(sets, maze_print, num);
	createMaze(sets, maze_print, num);
	printMaze(maze_print, num);

	freeMaze(sets, maze_print);

	fclose(fin);
	fclose(fout);

	return 0;
}
/*
Allocate and Initialize Disjoint sets
    "sets": have num*num disjoint sets
    "maze_print": have num*num*2 values (two directions: right, down)   
        the values are either 0(no wall) or 1 (wall)
*/
void init(DisjointSets *sets, DisjointSets *maze_print, int num) {
	sets->size_maze = num * num + 1;
	sets->ptr_arr = (int*)malloc(sizeof(int) * sets->size_maze);
	//Initialize sets
	for(int i = 0;i < sets->size_maze;++i){
		sets->ptr_arr[i] = 0;
	}
	maze_print->size_maze = num * num * 2 + 1;
	maze_print->ptr_arr = (int*)malloc(sizeof(int) * maze_print->size_maze);
	//Set the maze that everything has a wall
	for(int i = 0;i < maze_print->size_maze;++i){
		maze_print->ptr_arr[i] = 1;
	}
}

/*
Merge two disjoint sets including i and j respectively
*/
void Union(DisjointSets *sets, int i, int j) {
	if(sets->ptr_arr[i] < sets->ptr_arr[j]){
		sets->ptr_arr[j] = i;
	}else if(sets->ptr_arr[i] > sets->ptr_arr[j]){
		sets->ptr_arr[i] = j;
	}else{
		--sets->ptr_arr[i];
		sets->ptr_arr[j] = i;
	}
}
/*
Find the set including given element "i" and return the representative element  
*/
int find(DisjointSets *sets, int i) {
	while(sets->ptr_arr[i] > 0){
		i = sets->ptr_arr[i];
	}
	return i;
}
/*
Create Maze without cycle
You should generate the maze by randomly choosing cell and direction 
*/
void createMaze(DisjointSets *sets, DisjointSets *maze_print, int num) {
	//Set the number of disconnecting elements
	int sets_num = num * num;
	while(sets_num > 0){
		int direction = rand() % 2;//Right, bottom
		int rnd = rand() % (num * num);//Number of element
		if(maze_print->ptr_arr[2 * rnd - direction]){
			if(direction){
				if(rnd % num != 0){
					int u = find(sets, rnd);
					int v = find(sets, rnd + 1);
					//For creating the maze without cycle
					if(u != v){
						Union(sets, u, v);
						maze_print->ptr_arr[2 * rnd - direction] = 0;
						--sets_num;
					}
				}
			}else{
				if(rnd <= num * (num - 1)){
					int u = find(sets, rnd);
					int v = find(sets, rnd + 1);
					if(u != v){
						Union(sets, u, v);
						maze_print->ptr_arr[2 * rnd - direction] = 0;
						--sets_num;
					}
				}
			}
		}
	}
	maze_print->ptr_arr[2 * num * num - 1] = 0;
}

/*
Print Maze
Example> 
+---+---+---+---+---+
            |       |
+   +   +---+   +---+
|   |       |       |
+---+   +---+   +   +
|               |   |
+   +---+   +   +---+
|   |       |       |
+   +   +---+---+---+
|   |                
+---+---+---+---+---+
*/
void printMaze(DisjointSets *sets, int num) {
	for(int i = 1;i <= num;++i){
		fprintf(fout, "+---");
	}
	fprintf(fout, "+\n ");
	for(int i = 0;i < num - 1;++i){
		for(int j = 1;j <= num;++j){
			if(sets->ptr_arr[2 * (i * num + j) - 1]){
				fprintf(fout, "   |");
			}else{
				fprintf(fout, "    ");
			}
		}
		fprintf(fout, "\n+");
		for(int j = 1;j <= num;++j){
			if(sets->ptr_arr[2 * (i * num + j)]){
				fprintf(fout, "---+");
			}else{
				fprintf(fout, "   +");
			}
		}
		fprintf(fout, "\n|");
	}
	for(int i = 1;i <= num;++i){
		if(sets->ptr_arr[2 * ((num - 1) * num + i) - 1]){
			fprintf(fout, "   |");
		}else{
			fprintf(fout, "    ");
		}
	}
	fprintf(fout, "\n+");
	for(int i = 1;i <= num;++i){
		if(sets->ptr_arr[2 * ((num - 1) * num + i)]){
			fprintf(fout, "---+");
		}else{
			fprintf(fout, "   +");
		}
	}
}
/*
Deallocate sets
*/
void freeMaze(DisjointSets *sets, DisjointSets * maze_print) {
	free(sets->ptr_arr);
	free(sets);
	free(maze_print->ptr_arr);
	free(maze_print);
}
