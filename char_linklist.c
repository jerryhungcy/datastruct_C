#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct ptrnode* link;
struct ptrnode {
	int len;
	char* token;
	
	link nextlink;
	int counter;
};

void print(link l){
	for(int i = 0;i<l->len;i++){
		printf("%c", l->token[i]);
	}
	printf(", %d\n", l->counter);
}

int comp(link l, char* t, int len){  //0 wrong 1 pass
	/*printf("cmp ");
	print(l);
	printf(" ");
	for(int i = 0;i<len;i++){
		printf("%c", t[i]);
	}
	printf("\n");
	*/
	if(l->len == len){
		for(int i = 0;i<len;i++){
			if(l->token[i] != t[i] && abs(l->token[i] - t[i] ) != 'a'- 'A'){
				return 0;
			}
		}
		return 1;
	}else return 0;
}

int main(){
	char temp[100];
	link tempP;
	link head = NULL;
	while(scanf("%s", temp) !=EOF){
		 
		int length = strlen(temp);
		int n, s;
		
		if(temp[0] == '#'){
			switch(temp[1]){
				case 'F':
					break;
				case 'E':
					return 0;
					break;
				case 'A':
					scanf("%s", temp);
					length = strlen(temp);
					tempP = head;
					while(!comp(tempP, temp, length)){
						if(tempP->nextlink){
							tempP = tempP->nextlink;
						}else {
							link newP = (link)malloc(sizeof(newP));
							newP->len = length;
							newP->token = (char*)malloc(sizeof(char)* (newP->len)+1);
							strcpy(newP-> token , temp);
							tempP->nextlink = newP;
							newP->counter = 1;
							newP->nextlink =NULL;
							break;
						}
					}
					if(comp(tempP, temp, length)){
						tempP->counter++;
					}
					break;
				case'I':
					s=0;
					scanf("%d", &n);
					scanf(" %s", temp);
					length = strlen(temp);
					tempP = head;
					while(!comp(tempP, temp, length)){
						if(tempP->nextlink){
							tempP = tempP->nextlink;
							s++;
						}else break;
					}
					if(comp(tempP, temp, length)){
						tempP->counter++;
						break;
					}else if(s>=n){
						tempP = head;
						for(int i = 0;i<n-1;tempP = tempP->nextlink, i++);
						link newP = (link)malloc(sizeof(newP));
						newP->len = length;
						newP->token = (char*)malloc(sizeof(char)* (newP->len)+1);
						strcpy(newP-> token , temp);
						newP->nextlink = tempP->nextlink;
						tempP->nextlink = newP;
						newP->counter = 1;
					}
					break;
				case 'P':
					tempP = head;
					while(tempP){
						print(tempP);
						tempP = tempP->nextlink;
					}
					break;
				default:
					printf("something got wrong\n");
					break;
			}
		}else {
			//printf("read %s\n", temp);
			if(head == NULL){
				link newP = (link)malloc(sizeof(newP));
				newP->len = length;
				newP->token = (char*)malloc(sizeof(char)* (newP->len)+1);
				newP->nextlink = NULL;
				strcpy(newP-> token , temp);
				newP->counter = 1;
				head = newP;
				//printf("head %d %d\n", head->counter, newP->counter);
			}else {
				tempP = head;
				while(!comp(tempP, temp, length)){
					if(tempP->nextlink){
						tempP = tempP->nextlink;
					}else {
						link newP = (link)malloc(sizeof(newP));
						newP->len = length;
						newP->token = (char*)malloc(sizeof(char)* (newP->len)+1);
						strcpy(newP-> token , temp);
						tempP->nextlink = newP;
						newP->nextlink =NULL;
						newP->counter = 1;
						break;
					}
				}
				if(comp(tempP, temp, length)){
					tempP->counter++;
				}
			}
		}
	}
	return 0;
}