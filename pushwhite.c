#include<stdio.h>
#include<stdlib.h>

int main(){
	int n, sum = 0;
	scanf("%d", &n);
	int* array= (int*)malloc(sizeof(int)*n);
	int* ans= (int*)malloc(sizeof(int)*n);
	int* num= (int*)malloc(sizeof(int)*n);
	int i = 0;
	int start = 0;
	while(scanf("%d", &num[i]) != EOF){
		for(int j =0;j<num[i];j++){
			array[start] = 1;
			ans[start] = 1;
			start++;
		}
		sum += num[i];
		ans[start] =0;
		array[start] =0;
		start++;
		i++;
	}
	int t = n - sum - (i-1);
	while(t--){
		int head = n-1;
		int number = i - 1;
		while(head>=0){
			if(array[head] == 1){
				array[head + 1] = 1;
				array[head + 1 - num[number]] = 0;
				head = head + 1 - num[number];
				number--;
			}
			head--;
		}
		for(int k =0;k<n;k++){
			if(array[k] ==0){
				ans[k] = 0;
				//printf("%d ", k);
			}
		}		
		//printf("\n");
	}
	printf("%d", ans[0]);
	for(int k = 1;k<n;k++)
		printf(" %d", ans[k]);
	printf("\n");
	return 0;
}