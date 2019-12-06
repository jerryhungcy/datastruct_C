#include<stdio.h>
#include<stdlib.h>

typedef struct node treenode;

struct node{
	treenode* leftChild;
	treenode* rightChild;
	treenode* father;
	int value;	
};

treenode* delP;
int find;

void Preorder(treenode* t){
	printf("%d ", t->value);
	if(t->leftChild){
		Preorder(t->leftChild);
	}//else printf("left NULL\n");
	if(t->rightChild){
		Preorder(t->rightChild);
	}//else printf("right NULL\n");
}

void findnode(treenode* t, int i){
	if(t == NULL){
		return;
	}else if(t->value == i){
		delP = t;
		find = 1;
	}else {
		findnode(t->rightChild, i);
		findnode(t->leftChild, i);
	}
	return;
}

void deleteNode(){
	treenode* min = delP->leftChild;

	if(min){
		int d = min->value;
		while(min->rightChild){
			min = min->rightChild;
			d = min->value;
		}
		delP -> value = d;
		if(min->father->value < min->value){
			min->father->rightChild = min->rightChild;
			if(min->rightChild) min->rightChild->father = min->father;
		}else{
			min->father->leftChild = min->rightChild;
			if(min->rightChild) min->rightChild->father = min->father;
		}

	}else {
		if(delP->father->value < delP->value){
			if(delP->father) delP->father->rightChild = delP->rightChild;
			if(delP->rightChild) delP->rightChild->father = delP->father;
		}else{
			if(delP->father) delP->father->leftChild = delP->rightChild;
			if(delP->rightChild) delP->rightChild->father = delP->father;
		}
	}

	
}

int main(){
	int temp, end;
	char c;
	treenode *root, *tempP, *newP;
	scanf("%d", &temp);
	root = (treenode*)malloc(sizeof(treenode));
	root->value = temp;
	root->leftChild = NULL;
	root->rightChild = NULL;
	root->father = NULL;
	while(end){
		scanf("%d", &temp);
		tempP = root;
		while(1){
			if(tempP->value > temp ){
				if(tempP->leftChild){
					tempP = tempP->leftChild;
				}else {
					newP = (treenode*)malloc(sizeof(treenode));
					newP->value = temp;
					newP->leftChild = NULL;
					newP->rightChild = NULL;
					tempP->leftChild = newP;
					newP->father = tempP;
					break;
				}
				
			}else if(tempP->value < temp){
				if(tempP->rightChild){
					tempP = tempP->rightChild;
				}else {
					newP = (treenode*)malloc(sizeof(treenode));
					newP->value = temp;
					newP->leftChild = NULL;
					newP->rightChild = NULL;
					tempP->rightChild = newP;
					newP->father = tempP;
					break;
				}
			}else{
				end = 0;
				break;
			}
		}			
	}
	printf("Binary search tree (before):\n");
	Preorder(root);
	printf("\n");
	find = 0;
	findnode(root, temp);
	if(find){
		deleteNode();
	}else{
		printf("No %d\n", temp);
	}
	while(scanf("%d", &temp) !=EOF){
		find = 0;
		findnode(root, temp);
		if(find){
			deleteNode();
		}else{
			printf("No %d\n", temp);
		}
	}
	printf("Binary search tree (after):\n");
	Preorder(root);
	printf("\n");
	return 0;
}