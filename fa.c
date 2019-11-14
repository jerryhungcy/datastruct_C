#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	scanf("%d", &n);
	int* array = (int*)malloc(sizeof(int)* (n+1));
	array[0]= 0;
	array[1] = 1;
	for(int i = 2; i<= n;i++){
		array[i] = array[i-1] + array[i-2];
	}
	printf("%d\n", array[n]);
	return 0;
}