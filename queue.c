#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	scanf("%d", &n);
	int* queue = (int*)malloc(sizeof(int) * n);
	int head = 0, tail =0;
	int temp;
	while(1){
		scanf("%d", &temp);
		if(temp == -1){
			break;
		}else if(temp){
			scanf("%d", &temp);
			if(tail+1 == head || tail +1 -n == head){
				printf("FULL\n");
			}else{
				queue[tail] = temp;
				tail++;
				if(tail == n){
					tail = 0;
				}
			}
		}else{
			if(tail == head){
				printf("EMPTY\n");
			}else{
				printf("%d\n", queue[head]);
				head++;
				if(head == n) head = 0;
			}
		}
	}
	return 0;
}