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
	for(int i = 0;i<l->len-1;i++){
		printf("%c", l->token[i]);
	}
	printf(",%d\n", l->counter);
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
				printf("%c not same %c\n",  l->token[i], t[i]);
				return 0;
			}

		}
		return 1;
	}else {
		printf("not same length\n");
		return 0;
	}
}

int main(){
	char temp[10] = { "happy"};
	int length = strlen(temp);
	link newP = (link)malloc(sizeof(newP));
	newP->len = length;
	newP->token = (char*)malloc(sizeof(char)* (newP->len)+1);
	strcpy(newP-> token , temp);
	newP->counter = 1;
	newP->nextlink =NULL; 
	printf("%d", comp(newP, temp, 5));
	return 0;
}