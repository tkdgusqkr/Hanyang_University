#include<stdio.h>
#include<stdlib.h>

FILE *fin;
FILE *fout;

struct AVLNode;
typedef struct AVLNode *Position;
typedef struct AVLNode *AVLTree;
typedef int ElementType;

typedef struct AVLNode{
	ElementType element;
	AVLTree left, right;
	int height;
}AVLNode;

int Height(AVLTree T){
	//Return the height of AVLTree.
	if(T == NULL){
		return -1;
	}else{
		return T->height;
	}
}
int Max(int a, int b){
	//Return max value.
	if(a > b){
		return a;
	}else{
		return b;
	}
}
int Element(AVLTree T){
	//Return the element of AVLTree.
	if(T == NULL){
		return -1;
	}else{
		return T->element;
	}
}
/*
Rotation functions for AVLTree
*/
Position SingleRotateWithLeft(Position node){
	//The insertion into the left subtree of the left child
	Position tmp = node->left;
	node->left = tmp->right;
	tmp->right = node;
	node->height = Max(Height(node->left), Height(node->right)) + 1;
	tmp->height = Max(Height(tmp->left), Height(tmp->right)) + 1;
	return tmp;
}
Position SingleRotateWithRight(Position node){
	//The insertion into the right subtree of the right child
	Position tmp = node->right;
	node->right = tmp->left;
	tmp->left = node;
	node->height = Max(Height(node->left), Height(node->right)) + 1;
	tmp->height = Max(Height(tmp->left), Height(tmp->right)) + 1;
	return tmp;
}
Position DoubleRotateWithLeft(Position node){
	//The insertion into the left subtree of the right child.
	node->left = SingleRotateWithRight(node->left);
	return SingleRotateWithLeft(node);
}
Position DoubleRotateWithRight(Position node){
	//The insertion into the right subtree of the left child.
	node->right = SingleRotateWithLeft(node->right);
	return SingleRotateWithRight(node);
}
/*
Insert the value X in AVLTree T
return:
	pointer of root
print out:
	"insertion error : X is already in the tree!\n" , X is already in T
*/
AVLTree Insert(ElementType X, AVLTree T){
	if(T == NULL){
		//Insert the new node.
		T = (AVLTree)malloc(sizeof(AVLNode));
		T->left = NULL;
		T->right = NULL;
		T->element = X;
		T->height = 0;
	}else{
		if(T->element > X){
			T->left = Insert(X, T->left);
			if(Height(T->left) - Height(T->right) >= 2){
				if(T->left->element > X){
					T = SingleRotateWithLeft(T);
				}else{
					T = DoubleRotateWithLeft(T);
				}
			}
		}else if(T->element < X){
			T->right = Insert(X, T->right);
			if(Height(T->right) - Height(T->left) >= 2){
				if(T->right->element < X){
					T = SingleRotateWithRight(T);
				}else{
					T = DoubleRotateWithRight(T);
				}
			}
		}else{
			fprintf(fout, "insertion error : %d is already in the tree!\n", X);
		}
	}
	//Find the current height by using the height of the below floor.
	T->height = Max(Height(T->left), Height(T->right)) + 1;
	return T;
}
/*
Delete the value X in AVLTree T
return:
	pointer of root
print out:
	"deletion error : X is not in the tree!\n", X is not in T
*/
AVLTree Delete(ElementType X, AVLTree T){
	if(T == NULL){
		fprintf(fout, "deletion error : %d is not in the tree!\n", X);
	}else{
		if(T->element > X){
			T->left = Delete(X, T->left);
			if(Height(T->right) - Height(T->left) >= 2){
				if(T->right->left == NULL){
					T = SingleRotateWithRight(T);
				}else{
					T = DoubleRotateWithRight(T);
				}
			}
		}else if(T->element < X){
			T->right = Delete(X, T->right);
			if(Height(T->left) - Height(T->right) >= 2){
				if(T->left->right == NULL){
					T = SingleRotateWithLeft(T);
				}else{
					T = DoubleRotateWithLeft(T);
				}
			}
		}else{
			//Delete the node with the corresponding X by using the BST method.
			Position min = T->right;
			Position par = T;
			if(min != NULL){
				while(min->left != NULL){
					par = min;
					min = min ->left;
				}
				if(min == T->right){
					min->left = T->left;
				}else if(min->right == NULL){
					min->left = T->left;
					min->right = T->right;
				}else{
					par->left = min->right;
					min->left = T->left;
					min->right = T->right;
				}
			}else{
				if(T->right == NULL){
					if(T->height == 1){
						min = T->left;
					}
				}
			}
			free(T);
			T = min;
		}
	}
	if(T != NULL){
		T->height = Max(Height(T->left), Height(T->right)) + 1;
	}
	return T;
}
/*
Pre order Traversal
*/
void PrintPreorder(AVLTree T){
	//Print preorder by recursive function.
	if(T != NULL){
		fprintf(fout, "%d(%d) ", T->element, T->height);
		PrintPreorder(T->left);
		PrintPreorder(T->right);
	}
}
/*
Delete Tree
free allocated memory
*/
void DeleteTree(AVLTree T){
	if(T != NULL){
		AVLTree tmp1 = T->left;
		AVLTree tmp2 = T->right;
		free(T);
		DeleteTree(tmp1);
		DeleteTree(tmp2);
	}
}

int main(int argc, char *argv[]){
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");
	AVLTree Tree = NULL;
	char cv;
	int key;

	int i=0;

	while(!feof(fin)){
		printf("%d: ", ++i);
		fscanf(fin, "%c", &cv);
		switch(cv){
			case 'i':
				fscanf(fin, "%d\n", &key);
				Tree = Insert(key, Tree);
				break;
			case 'd':
				fscanf(fin, "%d\n", &key);
				Tree = Delete(key, Tree);
				break;
		}
		PrintPreorder(Tree);
		fprintf(fout, "\n");
		printf("\n");
	}

	DeleteTree(Tree);
	fclose(fin);
	fclose(fout);
	return 0;
}
