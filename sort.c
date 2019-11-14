#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
	int* c = (int*)a;
	int* d = (int*)b;
	if(*c > *d)return 1;
	else if(*c<*d)return -1;
	else return 0;
}


int main(){
	int n;
	scanf("%d", &n);
	int* array = (int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d", &array[i]);
	}
	qsort(&array[0], n, sizeof(int), cmp);
	printf("%d", array[0]);
	for(int i=1;i<n;i++){
		printf(" %d", array[i]);
	}
	printf("\n");
	return 0;
}