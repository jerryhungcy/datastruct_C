#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char math_stack[100];
int math_top;

void popMath(){
	if(math_stack[math_top] != '(' && math_stack[math_top] != ')')
		printf(" %c", math_stack[math_top]);
	math_top--;
}

void pushMath(char c){
	math_top++;
	math_stack[math_top] = c;
}

int getPrimary(char c){
	switch (c){
		case    '(' :   return   -1;
		case    ')' :   return   0;
		case    '+' :   return   1;
		case    '-' :   return   1;
		case    '/' :   return   2;
		case    '*' :   return   2;
		case    '%' :   return   2;
		case    '\0' :   return  -2;
		default  :   return   -2;   /* no error checking, default is operand */ 
	}
}

int main(){
	int n;
	scanf("%d", &n);
	char* string = (char*)malloc(sizeof(char) * 100); 
	fgets(&string[0], 100, stdin);
	while(n--){
		int first = 1;
		math_top = -1;
		string = (char*)malloc(sizeof(char) * 100); 
		fgets(&string[0], 100, stdin);
		//printf("%s", string);
		int len = strlen(string);
		for(int i= 0;i<len;i++){
			if(string[i] <= '9' && string[i] >= '0'){
				if(first){
					printf("%c", string[i]);
					first = 0;
				}else
					printf(" %c", string[i]);
			}else{
				int p = getPrimary(string[i]);
				//printf(" \n %c \n", string[i]);
				if(p == 0){
					while(getPrimary(math_stack[math_top]) != -1 ){
						popMath();
					}
					popMath();
				}else if(p > 0){
					while( getPrimary(math_stack[math_top]) >= p && math_top > -1){
						popMath();
					}
					pushMath(string[i]);
				}else if(p== -1){
					pushMath(string[i]);
				}
			}
		}
		while(math_top != -1){
			popMath();
		}
		printf("\n");
	}
	return 0;
}