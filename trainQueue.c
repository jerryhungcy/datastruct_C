#include<stdio.h>
#include<stdlib.h>

int main(){
	int n, end;
	scanf("%d", &n);
	int* array = (int*)malloc(sizeof(int)*n);
	int* have = (int*)malloc(sizeof(int) * n+1);
	while(1){
		end = 0;
		scanf("%d", &array[0]);
		if(array[0] == -1){
			break;
		}
		have[array[0]] = 1;
		for(int i= 1;i<n;i++){
			scanf("%d", &array[i]);
			if(end == 1){
				continue;
			}
			if(array[i-1] > array[i]){
				for(int j =1;j< array[i-1] - array[i];j++ ){
					if(have[array[i]+j] == 0){
						end =1;
						break;
					}
				}
			}
			have[array[i]] = 1;
		}
		if(end == 0){
			printf("YES\n");
		}else printf("NO\n");
		for(int i= 1;i<n+1;i++){
			have[i] =0;
		}	
	}
}