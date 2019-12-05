#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct linklist* link;
struct linklist{
	char* a;
	int len;
	int counter;
	link next;
};

int main(){
	 int n;
	 scanf("%d", &n);
	 int* array= (int*)malloc(sizeof(int)*n);
	 for(int i=0;i<n;i++){
	 	scanf("%d", &array[i]);
	 }
	 char temp[100];
	 int t =0;
	 link head, tempP, newP;
	 for(int j =0;j<n;j++){
	 	head = NULL;
	 	for(int i = 0;i<array[j];i++){
	 		scanf("%s", temp);
	 		//printf("%s\n", temp);
	 		if(head == NULL){
	 			head = (link)malloc(sizeof(link));
	 			head->len = strlen(temp);
	 			head->a = (char*)malloc(sizeof(char)* head->len);
	 			strcpy(head->a, temp);
	 			head->counter =1;
	 			head->next = NULL;
	 		}else {
	 			int same=0;
	 			for(tempP = head;tempP->next;tempP= tempP->next){
	 				if(!strcmp(tempP->a, temp)){
	 					tempP->counter++;
	 					same = 1;
	 				}
	 			}
	 			if(!strcmp(tempP->a, temp)){
 					tempP->counter++;
 					same = 1;
 				}
	 			if(!same){
	 				newP = (link)malloc(sizeof(link));
	 				newP->len = strlen(temp);
	 				newP->a = (char*)malloc(sizeof(char)*newP->len);
	 				strcpy(newP->a, temp);
	 				newP->counter= 1;
	 				newP->next = NULL;
	 				tempP->next = newP;
	 			}

	 		}
	 	}
	 	int counter_ans =0;
	 	for(tempP = head;tempP;tempP= tempP->next){
	 		if(tempP->counter %2 != 0){
	 			//printf("wrong %s\n", tempP->a);
	 			counter_ans++;
	 		}
	 	}
	 	printf("%d\n", counter_ans);
	 }
	 return 0;
	 
}