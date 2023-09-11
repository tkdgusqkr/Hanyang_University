#include<stdio.h>
#include<stdlib.h>

FILE* fin;
FILE* fout;

typedef struct Array Array;

struct Array{
    int size;
    int* values;
};

Array* CreateArray(int size);
void QuickSort(Array* array, int left, int right);
int Partition(Array* array, int left, int right);
void PrintArray(Array* array, int left, int right);
void DeleteArray(Array* array);
void swap(int* a, int* b);

int main(int argc, char *argv[]){
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");

    int size, i;
    Array* array;

    fscanf(fin, "%d", &size);
    array = CreateArray(size);
    for(i = 0; i < size; i++){
        fscanf(fin, "%d", &array->values[i]);
    }

    QuickSort(array, 0, size - 1);

    fprintf(fout, "\nsorting result :\n");
    PrintArray(array, 0, size - 1);

    //DeleteArray(array);


	return 0;
}

/*
Create new array 
input : size of the number to be sorted
output : the pointer of array
*/
Array* CreateArray(int size){
	Array* arr = (Array*)malloc(sizeof(Array));
	arr->size = size;
	arr->values = (int*)malloc(sizeof(int) * size);
	return arr;
}

/*
Quick sort
*/
void QuickSort(Array* array, int left, int right){
	if(left < right){
		int p = Partition(array, left, right);
		QuickSort(array, left, p - 1);
		QuickSort(array, p + 1, right);
	}
}

/*
Divide into 2 sub-lists based on pivot.
+ Select right-most data as pivot
+ Print left, right, pivot index at first
+ Print array values for every swap -> Printing array values should be implemented in a PrintArray function
Print format : 
    1. "left : %d, right : %d, pivot : %d\n"
    2. refered on PrintArray function
return:
    pivot index
*/
int Partition(Array* array, int left, int right){
	int pivot = array->values[right];
	fprintf(fout, "left : %d, right : %d, pivot : %d\n", left, right, pivot);
	int l = left - 1;
	int r = right;
	while(1){
		PrintArray(array, left, right);
		while(array->values[--r] > pivot);
		while(array->values[++l] < pivot);
		if(l < r){
			swap(&array->values[l], &array->values[r]);
		}else{
			if(l != right){
				swap(&array->values[l], &array->values[right]);
				PrintArray(array, left, right);
			}
			return l;
		}
	}
}

/*
Print array values 
Print format :
    “%-3s” : out of bound and should be filled with "-" charater
    “%-3d” : array values to be printed
*/
void PrintArray(Array* array, int left, int right){
	for(int i = 0;i < array->size;++i){
		if(i >= left && i <= right){
        		fprintf(fout, "%-3d", array->values[i]);
		}else{
        		fprintf(fout, "%-3s", "-");
		}
	}
        fprintf(fout, "\n");
}

/*
DeleteArray
*/
void DeleteArray(Array* array){
	free(array->values);
	free(array);
}

/*
Swap values
*/
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
