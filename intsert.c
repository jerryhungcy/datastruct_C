#include<stdio.h>
#include<stdlib.h>


int cmp(const void *a, const void *b){
	int* c = (int*)a;
	int* d = (int*)b;
	if(*c > *d)return 1;
	else if(*c<*d)return -1;
	else return 0;
}

int main(){
	int n, temp;
	scanf("%d", &n);
	int* array = (int*)malloc(sizeof(int)*n);
	scanf("%d%d", &array[0], &array[1]);
	if(array[0] > array[1]){
		temp = array[0];
		array[0] = array[1];
		array[1] = temp;
	}
	printf("%d %d\n", array[0], array[1]);
	scanf("%d", &array[2]);
	if(array[2] < array[0]){
		temp = array[0];
		array[0] = array[2];
		array[2] = array[1];
		array[1] = temp;
	}else if(array[2] < array[1]){
		temp = array[2];
		array[2] = array[1];
		array[1] = temp;
	}
	printf("%d %d %d\n", array[0], array[1], array[2]);
	for(int i=3;i<n;i++){
		scanf("%d", &array[i]);
	}
	qsort(&array[0], n, sizeof(int), cmp);

	for(int i=0;i< n;i++){
		if(i==0)printf("%d",array[i]);
		else printf(" %d", array[i]);
	}
	printf("\n");
	return 0;
}