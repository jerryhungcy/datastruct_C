#include<stdio.h>
#include<stdlib.h>

typedef struct node treenode;

struct node{
	treenode* leftChild;
	treenode* rightChild;
	int value;	
};

void Preorder(treenode* t){
	printf("%d ", t->value);
	if(t->leftChild){
		Preorder(t->leftChild);
	}//else printf("left NULL\n");
	if(t->rightChild){
		Preorder(t->rightChild);
	}//else printf("right NULL\n");
}

int main(){
	int temp, same;
	treenode *root, *tempP, *newP;
	scanf("%d", &temp);
	root = (treenode*)malloc(sizeof(treenode));
	root->value = temp;
	root->leftChild = NULL;
	root->rightChild = NULL;
	Preorder(root);
	printf("\n");
	while(scanf("%d", &temp) != EOF){
		tempP = root;
		same = 0;
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
					break;
				}
			}else{
				break;
			}
		}
		Preorder(root);
		printf("\n");	
	}
}