#include<stdio.h>
#include<stdlib.h>

int n;

int checkIndex(int i){
	if(i>=n){
		return i - n;
	}else if(i<0){
		return i+ n;
	}else return i;
}

int main(){
	scanf("%d", &n);
	int array[n][n];
	for(int i = 0;i<n;i++){
		for(int j=0 ;j<n;j++){
			array[i][j] = 0;
		}
	}
	int number , row, col;
	number = 1;
	row = 0, col = n/2;
	array[row][col] = number;
	number++;
	while(number <= n*n){
		if(array[checkIndex(row-1)][checkIndex(col+1)] > 0){
			row = checkIndex(row + 1);
			array[row][col] = number;

		}else {
			row = checkIndex(row-1);
			col = checkIndex(col + 1);
			array[row][col] = number;
		}
		number++;
	}
	for(int i =0 ;i<n;i++){
		printf("%d", array[i][0]);
		for(int j =1 ;j<n;j++){
			printf(" %d", array[i][j]);
		}
		printf("\n");
	}
	return 0;
}