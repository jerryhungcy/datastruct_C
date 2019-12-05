#include<stdio.h>
#include<stdlib.h>

typedef struct nodelink* nodePointer;

struct nodelink{
	int data;
	nodePointer link = NULL;
};

int main(){
	int n, first =0;
	scanf("%d", &n);
	while(n--){
		if(first){
			printf("\n");
		}
		first=1;
		nodePointer head, tail, newP, tempPointer;
		nodePointer array = (nodePointer)malloc(sizeof(array));
		array->link = NULL;
		head = NULL;
		tail = NULL;
		char c;
		int temp;
		while(1){

			scanf(" %c", &c);
			if(c == 'a'){
				scanf("%d", &temp);
				newP = (nodePointer)malloc(sizeof(newP));
				newP->link = NULL;
				if(tail != NULL){
					tail->link  = newP;
					tail = newP;
					
					newP->data = temp;
				}else{
					tail = newP;
					head = newP;
					newP->link = NULL;
					newP->data = temp;
				}
				
			}else if(c == 'f'){
				scanf("%d", &temp);
				newP = (nodePointer)malloc(sizeof(newP));
				if(head != NULL){
					newP -> link = head;
					head = newP;
					newP->data = temp;
				}else{
					head = newP;
					tail = newP;
					newP->link = NULL;
					newP->data = temp;
				}
				
			}else if(c == 'i'){
				int j, i =0;
				scanf("%d%d", &temp, &j);
				if(j!=0){
					j-=1;
					tempPointer = head;
					while(i != j){
						if(tempPointer!=NULL) {
							tempPointer = tempPointer->link;
							i++;
						}else break;
					}
					newP = (nodePointer)malloc(sizeof(newP));
					newP->link = tempPointer->link;
					tempPointer->link = newP;
					newP->data = temp;
				}

			}else break;
			tempPointer=head;
			printf("Created Linked list is: ");
			while(tempPointer!=NULL){
				printf(" %d ", tempPointer->data);
				tempPointer = tempPointer->link;
			}
			printf("\n");
		}
	}
	
	
}