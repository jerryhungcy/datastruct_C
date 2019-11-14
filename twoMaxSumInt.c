#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int t, max=0, max2=0, maxp;
	scanf("%d", &t);
	int* number = (int*)malloc(sizeof(int)*t);
	for(int i=0;i<t;i++){
		scanf("%d", &number[i]);
		if(max< number[i]){
			max = number[i];
			maxp = i;
		}
	}
	for(int i = 0;i<t;i++){
		if(abs(maxp-i) > 1 && max2 < number[i]){
			max2 = number[i];
		}
	}
	if(maxp == 0 || maxp == t-1 || max + max2 > number[maxp-1] + number[maxp+1]){
		printf("%d\n", max + max2);
	}else printf("%d\n", number[maxp-1] + number[maxp+1]);
	return 0;
}