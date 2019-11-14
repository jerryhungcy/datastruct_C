#include<stdio.h>
#include<stdlib.h>

int first =1;

void check(int i){
	if(i< 10){
		printf("%d ", i);
	}else if(i<100){
		if(i/10 == i%10){
			printf("%d ", i);
		}
	}else if(i < 1000){
		if(i/100 == i%10){
			printf("%d ", i);
		} 
	}
}


int main(){
	int head, tail;
	scanf("%d%d", &head, &tail);
	for(int i = head ;i<= tail;i++){
		check(i);
	}
	printf("\n");
	return 0;
}
