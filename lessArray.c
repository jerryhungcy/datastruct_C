#include<stdio.h>

int main(){
	int row, col;
	scanf("%d%d", &row, &col);
	int size = row * col /3, temp, index =0;
	int r[size], c[size], value[size];
	for(int i =0;i<row;i++){
		for(int j =0;j<col ;j++){
			scanf("%d", &temp );
			if(temp != 0){
				r[index] = i;
				c[index] = j;
				value[index] = temp;
				index++;
			}
		}
	}
	printf("%d %d %d\n", row, col, index);
	for(int i =0;i<index ;i++){
		printf("%d %d %d\n", r[i], c[i], value[i]);
	}
	return 0;
}