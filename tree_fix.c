#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct node treeNode;

struct node{
	treeNode* father;
	treeNode* leftChild;
	treeNode* rightChild;
	char* name;	
};

treeNode* tempP;

void findNode(treeNode* t, char* s, int l){

	if(t == NULL){
		//printf("NULL pop\n");
	}else if(t->name[0] == 'r' && s[0] == 'r'){
		tempP = t;
	}else if(t->name[1] == s[1] && t->name[2] == s[2]){
		//printf("find it\n");
		tempP = t;
	}else {
		//if(t->rightChild == NULL) printf("right NULL");
		//if(t->leftChild == NULL) printf("left NULL");
		//printf("node %s\n", t->name);
		//printf("right %s\n" , t->rightChild->name);
		findNode(t->rightChild, s, l);
		//printf("left %s\n" , t->leftChild->name);
		findNode(t->leftChild, s, l);
		return;
	}
}

int h;
void hightNode(treeNode* t, int i){
	if(t->leftChild) hightNode(t->leftChild, i+1);
	if(t->rightChild) hightNode(t->rightChild, i+1);
	if(h < i){
		h = i;
	}
}

void Preorder(treeNode* t){
	printf(" %s", t->name);
	if(t->leftChild){
		Preorder(t->leftChild);
	}
	if(t->rightChild){
		Preorder(t->rightChild);
	}
}

void Inorder(treeNode* t){
	
	if(t->leftChild){
		Inorder(t->leftChild);
	}
	printf(" %s", t->name);
	if(t->rightChild){
		Inorder(t->rightChild);
	}
}

void Postorder(treeNode* t){
	
	if(t->leftChild){
		Postorder(t->leftChild);
	}
	if(t->rightChild){
		Postorder(t->rightChild);
	}
	printf(" %s", t->name);
}

int main(){
	
	char temp[100];
	int hasgot = 0;
	treeNode *root, *newleft, *newright;
	root = (treeNode*)malloc(sizeof(treeNode));
	root->name = (char*)malloc(sizeof(char) * 2);
	strcpy(root->name, "r");
	root->father = NULL;
	root->leftChild = NULL;
	root->rightChild = NULL;
	while(1){
		if(!hasgot){
			scanf(" %s", temp);
			//printf("%s\n", temp);
		}
		hasgot = 0;
		if(temp[0] == '0'){
			break;
		}
		//printf("find %s\n", temp);
		findNode(root, temp, strlen(temp));
		scanf(" %s", temp);
		//printf("%s\n", temp);
		if((temp[2] - '0' )%2 == 1){
			newleft = (treeNode*)malloc(sizeof(treeNode));
			newleft->name = (char*)malloc(sizeof(char) * (strlen(temp) +1));
			strcpy(newleft->name, temp);
			newleft->father = tempP;
			tempP->leftChild = newleft;
			newleft->leftChild = NULL;
			newleft->rightChild = NULL;
			//printf("link left %s\n", temp);
			scanf(" %s", temp);
			
			if(temp[1] == newleft->name[1] && temp[2]-1 == newleft->name[2]){
				//printf("left right %s %s\n", newleft->name, temp);
				newright = (treeNode*)malloc(sizeof(treeNode));
			 	newright->name = (char*)malloc(sizeof(char) * (strlen(temp) +1));
				strcpy(newright->name, temp);
			 	newright->father = tempP;
				tempP->rightChild = newright;
			 	newright->leftChild = NULL;
			 	newright->rightChild = NULL;
			 	//printf("link right %s\n", temp);
			 }else {
			 	hasgot = 1;
			 }
		}else if((temp[2] - '0' )%2 == 0){
		 	newright = (treeNode*)malloc(sizeof(treeNode));
		 	newright->name = (char*)malloc(sizeof(char) * (strlen(temp) +1));
			strcpy(newright->name, temp);
		 	newright->father = tempP;
			tempP->rightChild = newright;
		 	newright->leftChild = NULL;
		 	newright->rightChild = NULL;
		 	//printf("link right %s\n", temp);
		}
		//printf("hasgot = %d\n", hasgot);
	}
	printf("Preorder:");
	Preorder(root);
	printf(" \nInorder:");
	Inorder(root);
	printf(" \nPostorder:");
	Postorder(root);
	int l, r;
	h= 0;
	hightNode(root->leftChild, 0);
	l = h;
	h = 0;
	hightNode(root->rightChild, 0);
	r = h;
	printf(" \nThe balance factor is %d\n", abs(l-r));
	return 0;
}