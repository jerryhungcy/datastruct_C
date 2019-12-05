#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct product* productNode;

struct product{
	int len;
	int num_price;
	int price[50];
	char name[50];
	productNode link;
	
};

int cmp(const void* a, const void* b){
	int* x = (int*)a;
	int* y = (int*)b;
	if(*x>*y)return 1;
	else return -1;
}
int comp(productNode l, char* t, int len){  //0 wrong 1 pass
	if(l->len == len){
		for(int i = 0;i<len;i++){
			if(l->name[i] != t[i]){
				return 0;
			}
		}
		return 1;
	}else return 0;
}

void print(productNode l){
	for(int i =0;i<l->len;i++){
		printf("%c", l->name[i]);
	}
	printf(",");
	for(int i =0;i<l->num_price;i++){
		printf("%d,", l->price[i]);
	}
	printf("\n");
}

int main(){
	int n,num;
	char temp[100];
	scanf("%d", &n);
	productNode head, newP, tempP;
	head = NULL;
	for(int i = 0;i<n;i++){
		scanf("%s %d", temp, &num);
		//printf("cin %s %d\n", temp, i);
		int length = strlen(temp);
		if(head == NULL){
			head = (productNode)malloc(sizeof(product));
			head->len = strlen(temp);
			//head->price = (int*)malloc(sizeof(int)* 10);
			//head->name = (char*)malloc(sizeof(char)* head->len);
			strcpy(head->name, temp);
			head->price[0] = num;
			head->num_price =1;
			head->link = NULL; 
		}else{
			//printf("%s %d\n", temp, num);
			int same=0;
 			for(tempP = head;tempP->link;tempP= tempP->link){
 				if(comp(tempP, temp, length)){
 					tempP->price[tempP->num_price] = num;
 					//printf("pirce[%d] = %d\n", tempP->num_price, tempP->price[tempP->num_price]);
 					tempP->num_price++;
 					same = 1;
 				}
 			}
 			if(comp(tempP, temp, length)){
				tempP->price[tempP->num_price] = num;
				//printf("pirce[%d] = %d\n", tempP->num_price, tempP->price[tempP->num_price]);
				tempP->num_price++;
				same = 1;
			}
 			if(!same){
 				newP = (productNode)malloc(sizeof(product));
 				newP->len = length;
 				//newP->price = (int*)malloc(sizeof(int)*10);
 				newP->price[0]= num;
 				newP->num_price= 1;
 				//newP->name = (char*)malloc(sizeof(char) *newP->len);
 				strcpy(newP->name, temp);
 				newP->link = NULL;
 				tempP->link = newP;
 			}
		}
	}
	for(tempP = head;tempP;tempP= tempP->link){
		qsort(tempP->price, tempP->num_price, sizeof(int), cmp);
		print(tempP);
	}
	return 0;
}