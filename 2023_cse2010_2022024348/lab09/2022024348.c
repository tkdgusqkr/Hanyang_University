#include<stdio.h>
#include<stdlib.h>

FILE *fin;
FILE *fout;

typedef struct BNode* BNodePtr;

struct BNode{
    int order;
    int size;           /* number of children */
    BNodePtr *child;    /* children pointers */
    int *key;           /* keys */
    int is_leaf;
}BNode;

BNodePtr CreateTree(int order);

void Insert(BNodePtr *root, int key);

int Find(BNodePtr root, int key);

void PrintTree(BNodePtr root);

void DeleteTree(BNodePtr root);

void Split(BNodePtr root, int next);

BNodePtr mainRoot;

int main(int argc, char* argv[]){
    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");

    int order;
    fscanf(fin, "%d", &order);
    mainRoot = CreateTree(order);

    char cv;
    int key;
    while(!feof(fin)){
        fscanf(fin, "%c", &cv);
        switch(cv){
            case 'i':
                fscanf(fin, "%d", &key);
                if(Find(mainRoot, key))
		    fprintf(fout, "insert error : key %d is already in the tree!\n", key);
                else
                    Insert(&mainRoot, key);
                break;
            case 'f':
                fscanf(fin, "%d", &key);
                if(Find(mainRoot, key))
                    fprintf(fout, "key %d found\n", key);
                else
                    fprintf(fout, "finding error : key %d is not in the tree!\n", key);
                break;
            case 'p':
                if (mainRoot->key[0] == 0)
                    fprintf(fout, "print error : tree is empty!");
                else
                    PrintTree(mainRoot);
                fprintf(fout, "\n");
                break;
        }
    }
   
    DeleteTree(mainRoot);
    fclose(fin);
    fclose(fout);

    return 0;
}

/*
Create new BTree with given order
order: order of BTree (order >= 2)
return: 
        the pointer of new BTree
 */
BNodePtr CreateTree(int order){
	BNodePtr node = (BNodePtr)malloc(sizeof(BNode));
	node->order = order;
	node->size = 0;
	node->child = (BNodePtr*)malloc(sizeof(BNodePtr) * (order + 1));
	node->key = (int*)malloc(sizeof(int) * order);
	node->is_leaf = 1;
	for(int i = 0;i <= order;++i){
		node->child[i] = NULL;
		if(i != order){
			node->key[i] = 0;
		}
	}
	return node;
}

/*
Insert the key value into BTree 
key: the key value in BTree node 
*/
void Insert(BNodePtr *root, int key){
	if((*root)->is_leaf){
		int last = 0;
		while((*root)->key[last] != 0){
			last += 1;
		}
		(*root)->key[last] = key;
		//Sort
		for(int i = 0;i <= last;++i){
			for(int j = 1;j <= last - i;++j){
				if((*root)->key[j - 1] > (*root)->key[j]){
					int tmp = (*root)->key[j - 1];
					(*root)->key[j - 1] = (*root)->key[j];
					(*root)->key[j] = tmp;
				}
			}
		}
	}else{
		int next = 0;
		while((*root)->key[next] != 0){
			if((*root)->key[next] > key){
				break;
			}
			next += 1;
		}
		Insert(&((*root)->child[next]),key);
		if((*root)->child[next]->key[(*root)->order - 1] != 0){
			Split(*root, next);
		}
	}
	if(*root == mainRoot && (*root)->key[(*root)->order - 1] != 0){
		BNodePtr parentNode = CreateTree((*root)->order);
		parentNode->key[0] = (*root)->key[(*root)->order / 2];
		parentNode->is_leaf = 0;
		BNodePtr leftNode = CreateTree((*root)->order);
		for(int i = 0;i <= (*root)->order / 2;++i){
			if(i != (*root)->order / 2){
				leftNode->key[i] = (*root)->key[i];
			}
			leftNode->child[i] = (*root)->child[i];
		}
		BNodePtr rightNode = CreateTree((*root)->order);
		for(int i = 0;i <= (*root)->order - (*root)->order / 2 - 1;++i){
			if(i != (*root)->order - (*root)->order / 2 - 1){
				rightNode->key[i] = (*root)->key[i + (*root)->order / 2 + 1];
			}
			rightNode->child[i] = (*root)->child[i + (*root)->order /2 + 1];
		}
		if(!((*root)->is_leaf)){
			leftNode->is_leaf = 0;
			rightNode->is_leaf = 0;
		}
		parentNode->child[0] = leftNode;
		parentNode->child[1] = rightNode;
		BNodePtr tmp = *root;
		*root = parentNode;
		free(tmp->key);
		free(tmp->child);
		free(tmp);
	}
}	

/*
Find node that has key in BTree
key: the key value in BTree node 
*/
int Find(BNodePtr root, int key){
	BNodePtr node = root;
	while(node != NULL){
		int i;
		int check = 0;
		for(i = 0;node->key[i] != 0;++i){
			if(node->key[i] == key){
				return 1;
			}else if(node->key[i] > key){
				node = node->child[i];
				check = 1;
				break;
			}
		}		
		if(!check){
			node = node->child[i];
		}
	}
	return 0;
}

/* 
Print Tree, inorder traversal 
*/
void PrintTree(BNodePtr root){
	if(root != NULL){
		int i;
		for(i = 0;root->key[i] != 0;++i){
			if(!root->is_leaf)
				PrintTree(root->child[i]);
			fprintf(fout, "%d ", root->key[i]);
		}
		if(!root->is_leaf)
			PrintTree(root->child[i]);
	}
}

/*
Free memory, delete a BTree completely 
*/
void DeleteTree(BNodePtr root){
	if(root != NULL){
		for(int i = 0;i < root->order;++i){
			DeleteTree(root->child[i]);
		}
		free(root->key);
		free(root->child);
		free(root);
	}
}
/*
Split function
*/
void Split(BNodePtr root, int next){
	for(int i = root->order - 1;i > next;--i){
		root->key[i] = root->key[i - 1];
	}
	root->key[next] = root->child[next]->key[root->order / 2];
	BNodePtr leftNode = CreateTree(root->order);
	leftNode->child[0] = root->child[next]->child[0];
	leftNode->child[root->order / 2] = root->child[next]->child[root->order / 2];
	for(int i = 0;i < root->order / 2;++i){
		leftNode->key[i] = root->child[next]->key[i];
	}
	BNodePtr rightNode = CreateTree(root->order);
	rightNode->child[0] = root->child[next]->child[root->order / 2 + 1];
	rightNode->child[root->order - root->order / 2 - 1] = root->child[next]->child[root->order];
	for(int i = 0;i < root->order - root->order / 2 - 1;++i){
		rightNode->key[i] = root->child[next]->key[i + root->order / 2 + 1];
	}
	for(int i = root->order;i > next;--i){
		root->child[i] = root->child[i - 1];
	}
	root->child[next + 1] = rightNode;
	BNodePtr tmp = root->child[next];
	root->child[next] = leftNode;
	free(tmp->key);
	free(tmp->child);
	free(tmp);
}
