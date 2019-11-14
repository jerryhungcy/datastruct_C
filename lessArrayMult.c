#include<stdio.h>
#include<stdlib.h>

struct lessM{
	int row;
	int col;
	int value;
};
typedef struct lessM lm;

int cmp(const void *a, const void *b){
	lm* c = (lm*)a;
	lm* d = (lm*)b;
	if(c->row > d->row)return 1;
	else if(c->row < d->row)return -1;
	else if(c->col > d->col) return 1;
	else return -1;
}


int main(){
	int n;
	char a;
	int size = 0; 
	scanf("%d", &n);
	lm array[n];
	for(int i=0;i<n;i++){
		scanf(" %c%d%c%d%c%c%d", &a, &array[i].row, &a, &array[i].col, &a, &a, &array[i].value);
		if(size < array[i].row) size = array[i].row;
		if(size < array[i].col) size = array[i].col;
	}
	qsort(&array[0], n, sizeof(lm), cmp);
	int** ans = (int**)malloc(sizeof(int)*size*size);
	for(int i=0;i<size;i++){
		ans[i] = (int*)malloc(sizeof(int)*size);
	}
	for(int i=0;i<n;i++){
		for(int j = 0;j<n;j++){
			ans[i][j]=0;
		}
	}
	for(int i=0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(array[i].col == array[j].col){
				ans[array[i].row-1][array[j].row-1] +=array[i].value * array[j].value;
			}
		}
	}
	for(int i=0;i<size;i++){
		for(int j = 0;j<size;j++){
			if(j!=0){
				printf(" ");
			}
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}


