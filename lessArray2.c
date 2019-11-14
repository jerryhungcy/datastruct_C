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
	if(c->col > d->col)return 1;
	else if(c->col < d->col)return -1;
	else if(c->row > d->row) return 1;
	else return -1;
}

int main(){
	int n, r, c;
	scanf("%d%d%d", &r, &c, &n);
	lm rowfirst[n];
	for(int i=0;i<n;i++){
		scanf("%d%d%d", &rowfirst[i].row, &rowfirst[i].col, &rowfirst[i].value);
	}
	qsort(&rowfirst[0], n, sizeof(lm), cmp);
	printf("%d %d %d\n", r, c, n);
	for(int i =0;i<n;i++){
		printf("%d %d %d\n", rowfirst[i].col, rowfirst[i].row, rowfirst[i].value);
	}

	return 0;
}