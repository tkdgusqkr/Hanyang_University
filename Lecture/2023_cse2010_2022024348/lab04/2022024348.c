
#include<stdio.h>
#include<stdlib.h>

FILE *fin;
FILE *fout;

#define FROMPARENT 0
#define FROMTHREAD 1

typedef struct ThreadedTree* ThreadedPtr;
typedef int ElementType;

struct ThreadedTree {
	int left_thread; // flag if ptr is thread, 1, if it is a thread or 0, if it points to a child node
	ThreadedPtr left_child;
	ElementType data;
	ThreadedPtr right_child;
	int right_thread; // flag if ptr is thread, 1, if it is a thread or 0, if it points to a child node
}ThreadedTree;

/*
Create a root of new Threaded Tree
Root data should be -1
return:
	the pointer of new Threaded Tree
*/
ThreadedPtr CreateTree(){
	ThreadedPtr node = (ThreadedPtr)malloc(sizeof(ThreadedTree));
	node->left_thread = 1;
	node->left_child = node;
	node->data = -1; // Because it is root node.
	node->right_child = node;
	node->right_thread = 1;
	return node;
}


/*
Insert the key value "data" in Threaded Tree
root : Pointer to the root node of Threaded Tree
root_idx : Index of the root node of Threaded Tree, means the first node to find the insertion position
data : data key value of the node to be newly inserted,
idx : The index of the node to be newly inserted, 0 means root index
return :
	1, the insertion succeeds
	0, the insertion fails.
*/
int Insert(ThreadedPtr root, int root_idx, ElementType data, int idx){
	if(idx > 100 || idx < 0)
		return 0;
	if(data > 10000 || data < 0)
		return 0;
	if(idx == 1){
		ThreadedPtr node = (ThreadedPtr)malloc(sizeof(ThreadedTree));
		node->left_thread = 1;
		node->left_child = root;
		node->data = data;
		node->right_child = root;
		node->right_thread = 1;
		// Create new node.
		root->left_thread = 0;
		root->right_child = node;
		root->right_thread = 0;
		// Update root node.
		return 1;
	}else if(idx > 1){
		int i, j;
		int right[7] = {0,};
		for(i = 0;idx / 2;++i){
			right[i] = idx % 2;
			idx /= 2;
		}
		// The process of finding the trace path of node received.
		// Check whether the position of the path is even or odd.
		ThreadedPtr tmp = root->right_child;
		for(j = i - 1;j > 0;--j){
			if(right[j])
				tmp = tmp->right_child;
			else
				tmp = tmp->left_child;
		}
		ThreadedPtr node = (ThreadedPtr)malloc(sizeof(ThreadedTree));
		node->left_thread = 1;
		node->data = data;
		node->right_thread = 1;
		if(right[j]){
			node->left_child = tmp;
			node->right_child = tmp->right_child;
			tmp->right_thread = 0;
			tmp->right_child = node;
		}else{
			node->left_child = tmp->left_child;
			node->right_child = tmp;
			tmp->left_thread = 0;
			tmp->left_child = node;
		}
		// Assign that node to the appropriate lacation.
		return 1;
	}
}

/*
In Order Traversal
Implementing in a recursive form is prohibited.
When printing out, the interval between each key is one space
print out:
	"inorder traversal : data1 data2 data3" (When there are 3 data, except root node)

*/
void printInorder(ThreadedPtr root){
	fprintf(fout, "inorder traversal :");
	ThreadedPtr tmp = root;
	ThreadedPtr temp = root;
	while(1){
		ThreadedPtr ptr;
		ptr = tmp->right_child;
		if(!tmp->right_thread && temp != ptr){ // Delete in-place iteration by checking if the next node is equal to the previoua node.
			while(!ptr->left_thread){
				temp = ptr;
				ptr = ptr->left_child;
			}
		}
		tmp = ptr;
		// Find the in-order successor.
		if(tmp == root)
			break;
		fprintf(fout, " %d", tmp->data);
	}
	fprintf(fout, "\n");
}

/*
Delete the Tree
*/
void DeleteTree(ThreadedPtr root){
	ThreadedPtr tmp1, tmp2; // Set to pre-save information to be deleted when dynamic allocation is released.
	if(!root->left_thread && root != root->left_child)
		tmp1 = root->left_child;
	else
		tmp1 = NULL;
	if(!root->right_thread)
		tmp2 = root->right_child;
	else
		tmp2 = NULL;
	free(root);
	if(tmp1 != NULL)
		DeleteTree(tmp1);
	if(tmp2 != NULL)
		DeleteTree(tmp2);
	
}

int main(int argc, char *argv[]){
	fin=fopen(argv[1], "r");
	fout=fopen(argv[2], "w");

	ThreadedPtr root = CreateTree();

	int NUM_NODES;
	fscanf(fin, "%d", &NUM_NODES);

	int root_idx=0, idx=0;

	while(++idx <= NUM_NODES){
		ElementType data;
		fscanf(fin, "%d", &data);
		
		if(Insert(root, root_idx, data, idx) == 0){
			fprintf(fout, "Insertion failed!\n");
			return 0;
		}
	}	

	printInorder(root);
	DeleteTree(root);
	
	
	fclose(fin);
	fclose(fout);

	return 0;
}
