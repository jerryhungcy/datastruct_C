#include<stdio.h>
#include<stdlib.h>

typedef struct nodeLink* nodePointer;
struct nodeLink{
	int data;
	nodePointer link;
};

int main(){
	int temp;
	nodePointer head = NULL, tempP, newP;
	while(scanf("%d", &temp) != EOF){
		newP = (nodePointer)malloc(sizeof(newP));
		if(head == NULL){
			head = newP;
			newP->data = temp;
			newP->link = NULL;
			tempP = newP;
			continue;
		}
		newP->data = temp;
		newP->link = NULL;
		tempP->link = newP;
		tempP = newP;
	}
	nodePointer last, mid;
	mid = NULL;
	while(head != NULL){
		last = mid;
		mid = head;
		head = head->link;
		mid->link = last;
	}
	int first = 0;
	while(mid != NULL){
		if(first){
			printf(" %d", mid->data);
		}else printf("%d", mid->data);
		first = 1;
		mid = mid->link;
	}
	printf("\n");
	return 0;
}