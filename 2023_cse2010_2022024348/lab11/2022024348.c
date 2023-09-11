#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *fin;
FILE *fout;

typedef int ElementType;
typedef ElementType List;
typedef struct HashTbl* HashTable;

typedef struct HashTbl{
	int TableSize;
	List *TheLists;
}HashTbl;

HashTable createTable(int TableSize);
void Insert(HashTable H, ElementType Key, int solution);
void Delete(HashTable H, ElementType Key, int solution);
int Find(HashTable H, ElementType Key, int solution);
void printTable(HashTable H);
void deleteTable(HashTable H);

int main(int argc, char *argv[]){
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");


	char solution_str[20];
	int solution, TableSize;

	fscanf(fin, "%s", solution_str);
	if(!strcmp(solution_str, "linear"))
		solution = 1;
	else if(!strcmp(solution_str, "quadratic"))
		solution = 2;
	else{
		fprintf(fout, "Error: Invalid hashing solution!");
		return 0;
	}
	
	fscanf(fin, "%d", &TableSize);

	HashTable H = createTable(TableSize);

	char cv;
	int key;
	while(!feof(fin)){
		fscanf(fin, "%c", &cv);
		switch(cv){
			case 'i':
				fscanf(fin, "%d", &key);
				Insert(H, key, solution);
				break;

			case 'f':
				fscanf(fin, "%d", &key);
				int result = Find(H, key, solution);
				if(result)
					fprintf(fout, "%d is in the table\n", key);
				else
					fprintf(fout, "%d is not in the table\n", key);
				break;

			case 'd':
				fscanf(fin, "%d", &key);
				Delete(H, key, solution);
				break;

			case 'p':
				printTable(H);
				break;
		}
	}

	deleteTable(H);

	return 0;
}

/*
Create new Hash Table with given TableSize
reture:
	the pointer of new hash table
*/
HashTable createTable(int TableSize){
	HashTable hash = (HashTable)malloc(sizeof(HashTbl));
	hash->TableSize = TableSize;
	hash->TheLists = (List*)malloc(sizeof(ElementType) * TableSize);
	return hash;
}

/*
Insert the key in hash table with given solution (linear or quadratic).
print out : 
	Successful insertion : "insert %d into address %d\n"
	When inserting duplicate key value : "insertion error : %d already exists at address %d\n"
	When HashTable is full : "insertion error : table is full\n"
*/
void Insert(HashTable H, ElementType Key, int solution){
	if(solution == 1){//Linear solution
		int i;
		for(i = 0;i < H->TableSize;++i){
			int idx = Key % H->TableSize + i;
			//Successful insertion
			if(H->TheLists[idx] == 0){
				H->TheLists[idx] = Key;
				fprintf(fout, "insert %d into address %d\n", Key, idx);
				break;
			}
			//When inserting duplicate key value
			if(H->TheLists[idx] == Key){
				fprintf(fout, "insertion error : %d already exists at address %d\n", Key, idx);
				break;
			}
		}
		//When HashTable is full
		if(i == H->TableSize){
			fprintf(fout, "insertion error : table is full\n");
		}
	}else if(solution == 2){//Quadratic solution
		int i;
		for(i = 0;i < H->TableSize;++i){
			int idx = Key % H->TableSize + i * i;
			//Successful insertion
			if(H->TheLists[idx] == 0){
				H->TheLists[idx] = Key;
				fprintf(fout, "insert %d into address %d\n", Key, idx);
				break;
			}
			//When inserting duplicate key value
			if(H->TheLists[idx] == Key){
				fprintf(fout, "insertion error : %d already exists at address %d\n", Key, idx);
				break;
			}
		}
		//When HashTable is full
		if(i == H->TableSize){
			fprintf(fout, "insertion error : table is full\n");
		}
	}
}
/*
Delete the key in hash table with given solution (linear or quadratic).
print out : 	
	when key value is found :  "delete %d\n"
	when key value does not exist : %d is not in the table\n"
*/
void Delete(HashTable H, ElementType Key, int solution){
	if(solution == 1){//Linear solution
		int i;
		for(i = 0;i < H->TableSize;++i){
			int idx = Key % H->TableSize + i;
			if(H->TheLists[idx] == Key){
				H->TheLists[idx] = 0;
				fprintf(fout, "delete %d\n", Key);
				break;
			}
		}
		if(i == H->TableSize){
			fprintf(fout, "deletion error: %d is not in the table\n", Key);
		}
	}else if(solution == 2){//Quadratic solution
		int i;
		for(i = 0;i < H->TableSize;++i){
			int idx = Key % H->TableSize + i * i;
			if(H->TheLists[idx] == Key){
				H->TheLists[idx] = 0;
				fprintf(fout, "delete %d\n", Key);
				break;
			}
		}
		if(i == H->TableSize){
			fprintf(fout, "deletion error: %d is not in the table\n", Key);
		}
	}
}

/*
Find the Key from hash table with given solution (linear or quadratic).
return:
	0 : when the key is not found
	1 : when the key is found
*/
int Find(HashTable H, ElementType Key, int solution){
	if(solution == 1){//Linear solution
		for(int i = 0;i < H->TableSize;++i){
			int idx = Key % H->TableSize + i;
			if(H->TheLists[idx] == Key){
				return 1;
			}
		}
		return 0;
	}else if(solution == 2){//Quadratic solution
		for(int i = 0;i < H->TableSize;++i){
			int idx = Key % H->TableSize + i * i;
			if(H->TheLists[idx] == Key){
				return 1;
			}
		}
		return 0;
	}
}
/*
Print all values of Hash Table
print out the key values ​​in the Hash Table in the order of index in the Hash Table.
	empty Hash Table print : "0 "
	Non empty Hash Table print : "%d "
*/
void printTable(HashTable H){
	for(int i = 0;i < H->TableSize;++i){
		fprintf(fout, "%d ", H->TheLists[i]);
	}
}
/*
delete Table 
*/
void deleteTable(HashTable H){
	free(H->TheLists);
	free(H);
}
