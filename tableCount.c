#include<stdio.h>
#include<stdlib.h>

int main(){
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	int* array = (int*)malloc(sizeof(int)*n);
	for(int i =0;i<n;i++) array[i] = 1;
	int k=0;
	a-=1;
	while(k<n){
		int sum = 0, ans;
		while(1){
			sum+= array[a];
			ans = a;
			if(sum == b) break;
			a++;
			if(a==n)a=0;
		}
		array[a] = 0;
		if(k ==0){
			printf("%d", ans+1);
		}else printf(" %d", ans+1);
		k++;
	}
	printf("\n");
	return 0;
}