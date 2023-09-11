#include<stdio.h>
#include<stdlib.h>

FILE *fin;
FILE *fout;

typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

struct Node{
	ElementType element;
	Position next;
};

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
void Insert(ElementType X, List L, Position P);
Position FindPrevious(ElementType X, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
void DeleteList(List L);
int* GetElements(List L);
int ListSize=0;

int main(int argc, char **argv){
	fin=fopen(argv[1], "r");
	fout=fopen(argv[2], "w");
	char x;
	int* elements;

	Position header=NULL, tmp=NULL;
	header = MakeEmpty(header);
	while(fscanf(fin,"%c",&x)!=EOF){
		if(x=='i'){
			int a,b;	fscanf(fin,"%d%d",&a,&b);
			tmp = Find(a, header);
			if(tmp!=NULL){
				fprintf(fout, "insertion(%d) failed : the key already exists in the list\n", a);
				continue;
			}
			tmp = Find(b, header);
			if(tmp==NULL){
				fprintf(fout, "insertion(%d) failed : can not find the location to be inserted\n", a);
				continue;
			}
			Insert(a, header, tmp);
		}
		else if(x=='d'){
			int a;	fscanf(fin,"%d",&a);
			tmp = Find(a, header);
			if(tmp==NULL){
				fprintf(fout, "deletion(%d) failed : element %d is not in the list\n", a, a);
				continue;
			}
			Delete(a, header);
		}
		else if(x=='f'){
			int a;	fscanf(fin,"%d",&a);
			tmp = FindPrevious(a, header);
			if(IsLast(tmp, header)) fprintf(fout, "finding(%d) failed : element %d is not in the list\n",a,a);
			else{
				if(tmp->element>0) fprintf(fout, "key of the previous node of %d is %d\n", a, tmp->element);
				else fprintf(fout, "key of the previous node of %d is head\n",a);
			}
		}
		else if(x=='p') {
			if(IsEmpty(header))
				fprintf(fout, "empty list!\n");
			else
			{
				elements = GetElements(header);
				for(int i = 0; i < ListSize; i++){
						fprintf(fout, "key:%d ", elements[i]);
					}
					fprintf(fout, "\n");
				free(elements);
			}
		}
	}
	DeleteList(header);
	fclose(fin);
	fclose(fout);
	return 0;
}

List MakeEmpty(List L){
/*
Make new header
element should be -1
return:
	the pointer of new list
*/
	L = (List)malloc(sizeof(struct Node));
	L->element = -1;
	L->next = NULL;
	return L;
// After being dynamic allocation to parameter L, set element to -1 and next to NULL.
}

int IsEmpty(List L){
/*
Check if list L is empty or not
return:
	1, list is full
	0, list is not full
*/
	return (L->next == NULL);
// If L has only header, L is empty.
// Therefore, if L is empty, next of L is NULL, so check whether next of L is NULL.
}

int IsLast(Position P, List L){
/*
Check if Position P is last or not
return:
	1, list is full
	0, list is not full
*/
	return (P->next == NULL);
// If P is the last of L, next of P is NULL.
// Therefore, check whether next of P is NULL.
}

void Insert(ElementType X, List L, Position P){
/*
Insert X in position P of list L
*/
	Position tmp = (Position)malloc(sizeof(struct Node));
	tmp->element = X;
	tmp->next = P->next;
	P->next = tmp;
	++ListSize;
// After being dynamic allocation to arbitrary Position(tmp), set element to parameter X and next to P's next.
// Set next of P to arbitrary Position(tmp).
// Since size of list has increased, increase ListSize by 1.
}

int* GetElements(List L){
/*
Return an array of copied elements from the List L
The length of the returned array should be the same as the size of the ListSize
The order of the returned array should be the same as the order of L->element  
If List is empty, return NULL
***WARNING***
You must copy the elements to another allocated array
*/
	int* arr = (int*)malloc(sizeof(int) * ListSize);
	Position p = L->next;
	for(int i = 0;p != NULL;++i){
		arr[i] = p->element;
		p = p->next;
	}
	return arr;
// After being dynamic allocation to arbitrary array, elements are stored in the array until the end of L, that is, NULL.
}

Position FindPrevious(ElementType X, List L){
/*
Find the previous node of the node with the given element X in List L
return:
	the pointer of previous node of node that has element X  
*/
	Position p = L;
	while(p->next != NULL && p->next->element != X){
		p = p->next;
	}
	return p;
// After creating arbitrary Position(p), check whether element of p's next is NULL and whether element of p' next is parameter X.
}

Position Find(ElementType X, List L){
/*
Find the node with the given element X in List L
return:
	the pointer of node has element X
*/
	Position p = L;
	while(p != NULL && p->element != X){
		p = p->next;
	}
	return p;
// After creating arbitrary Position(p), check whether element of p is NULL and whether element of p is parameter X.
}

void Delete(ElementType X, List L){
/*
Delete the node that has element X in List L
*/
	Position p = FindPrevious(X, L);
	Position tmp = p->next;
	p->next = tmp->next;
	free(tmp);
	--ListSize;
// To delete Position with X, create arbitrary Position(tmp) and save Position with X.
// Change next of previous Position of Position with X to next of Position with X, and then be free previously saved Position with X.
// Since size of list has decreased, decrease ListSize by 1.
}

void DeleteList(List L){
/*
Delete the List
*/
	Position p = L;
	while(p->next != NULL){
		Position tmp = p->next;
		free(p);
		p = tmp;
	}
	p->element = -1;
	ListSize = 0;
// To delete list, create arbitrary Position(p) and save current Position.
// It repeats until next of p becomes NULL and removes p.
// If next of p is NULL, change element of p to -1.
// Since size of list becomes 0, change ListSize to 0.
}
