#include<stdio.h>
#include<stdlib.h>

FILE *fin;
FILE *fout;

typedef struct BST* Tree;
typedef struct BST{
	int value;
	struct BST* left;
	struct BST* right;
}BST;

Tree insertNode(Tree root, int key);
Tree deleteNode(Tree root, int key);
int findNode(Tree root, int key);
void printInorder(Tree root);
void deleteTree(Tree root);

void main(int argc, char* argv[]){
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");
	char cv;
	int key;

	Tree root = NULL;

	while(!feof(fin)){
		fscanf(fin, "%c", &cv);
		switch(cv){
			case 'i':
				fscanf(fin, "%d", &key);
				if(!findNode(root, key))
					root = insertNode(root, key);
				else
					fprintf(fout, "insertion error: %d is already in the tree\n", key);
				break;
			case 'f':
				fscanf(fin,"%d",&key);
				if(findNode(root, key))
					fprintf(fout, "%d is in the tree\n", key);
				else
					fprintf(fout, "finding error: %d is not in the tree\n", key);
				break;
			case 'd':
				fscanf(fin, "%d", &key);
				if(findNode(root, key)){
					root = deleteNode(root, key);
					fprintf(fout, "delete %d\n", key);
				}
				else{
					fprintf(fout, "deletion error: %d is not in the tree\n", key);
				}
				break;
			case 'p':
				fscanf(fin, "%c", &cv);
				if(cv == 'i'){
					if(root == NULL)
						fprintf(fout, "tree is empty");
					else
						printInorder(root);
				}
				fprintf(fout, "\n");
				break;
		}
	}
	deleteTree(root);
}
/*
Insert the value "key" in Tree "root"
Tree root : A pointer to the root node of the binary search tree.
int key : The value of the new node to insert.
return:
	pointer of root
print out:
	"insert key\n"
*/
Tree insertNode(Tree root, int key){
	Tree node = (Tree)malloc(sizeof(BST));
	node->value = key;
	node->left = NULL;
	node->right = NULL;
	Tree tmp = root;
	Tree ptr = NULL;
	while(tmp != NULL){
		if(tmp->value > key){
			ptr = tmp;
			tmp = tmp->left;
		}else{
			ptr = tmp;
			tmp = tmp->right;
		}
	}
	//Insert key by BST process.
	if(ptr == NULL){
		root = node;
	}else{
		if(ptr->value > key)
			ptr->left = node;
		else
			ptr->right = node;
	}
	fprintf(fout, "insert %d\n", key);
	return root;
	
}
/*
Delete the value key in Tree root
Tree root : A pointer to the root node of the binary search tree.
int key : The value of the new node to be deleted.
return :
	pointer of root
*/
Tree deleteNode(Tree root, int key){
	Tree tmp = root;
	Tree ptr = NULL;
	
	while(tmp != NULL && tmp->value != key){
		if(tmp->value > key){
			ptr = tmp;
			tmp = tmp->left;
		}else if(tmp->value < key){
			ptr = tmp;
			tmp = tmp->right;
		}
	}
	//Find the left, right node of the node that has the key value.
	if(tmp->left == NULL && tmp->right == NULL){
		if(ptr == NULL){
			free(tmp);
			return NULL;
		}
		if(ptr->value > key){
			ptr->left = NULL;
			free(tmp);
		}else{
			ptr->right = NULL;
			free(tmp);
		}
	}else if(tmp->left != NULL && tmp->right != NULL){
		Tree min = tmp->right;
		Tree par = tmp;
		while(min->left != NULL){
			par = min;
			min = min->left;
		}
		min->left = tmp->left;
		if(tmp->right != min){
			min->right = tmp->right;
			par->left = NULL;
		}
		if(ptr == NULL){
			free(tmp);
			return min;
		}else{
			if(ptr->value > key)
				ptr->left = min;
			else
				ptr->right = min;
		}
		free(tmp);
	}else if(tmp->left != NULL && tmp->right == NULL){
		if(ptr == NULL){
			ptr = tmp->left;
			free(tmp);
			return ptr;
		}else{
			if(ptr->value > key){
				ptr->left = tmp->left;
				free(tmp);
			}else{
				ptr->right = tmp->left;
				free(tmp);
			}
		}
	}else if(tmp->left == NULL && tmp->right != NULL){
		if(ptr == NULL){
			ptr = tmp->right;
			free(tmp);
			return ptr;
		}else{
			if(ptr->value > key){
				ptr->left = tmp->left;
				free(tmp);
			}else{
				ptr->right = tmp->left;
				free(tmp);
			}
		}
	}
	return root;
}
/*
Find the value key in Tree root
Tree root : A pointer to the root node of the binary search tree.
int key : The value of the node trying to find.
return :
	1, key is found
	0, key is not found
*/
int findNode(Tree root, int key){
	Tree tmp = root;
	while(tmp != NULL && tmp->value != key){
		if(tmp->value > key){
			tmp = tmp->left;
		}else{
			tmp = tmp->right;
		}
	}
	if(tmp != NULL){
		return 1;
	}else{
		return 0;
	}
}
/*
In Order Traversal
Tree root : A pointer to the root node of the binary search tree.
print out:
	"root->value "
*/
void printInorder(Tree root){
	//Print inorder by recursive function.
	if(root != NULL){
		printInorder(root->left);
		fprintf(fout, "%d ", root->value);
		printInorder(root->right);
	}
}
/*
Delete Tree
free allocated memory
Tree root : A pointer to the root node of the binary search tree.
*/
void deleteTree(Tree root){
	if(root != NULL){
		Tree tmp1 = root->left;
		Tree tmp2 = root->right;
		free(root);
		deleteTree(tmp1);
		deleteTree(tmp2);
	}
}
