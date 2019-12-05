#include<stdio.h>
#include<stdlib.h>
 
int main(){
	int size = 256;
	int* array = (int*)malloc(sizeof(int)* size);
	for(int i=0;i<size ;i++){
		array[i] = 0;
	}
	array[1] = -1;
	int temp;
	int max_index;
	while(scanf("%d", &temp) != EOF){
		if(array[1] == -1){
			array[1] = temp;
		}else {
			int i = 1;
			while(array[i]){
				if(array[i] > temp){
					i = i*2+1;
				}else if(array[i] < temp){
					i = i*2;
				}else {
					break;
				}
			}
			array[i] = temp;
			if(i>max_index){
				max_index = i;
			}
		}
	}
	int count = 0;
	while(max_index){
		max_index /=2;
		count++;
	}
	printf("%d\n", count);
}