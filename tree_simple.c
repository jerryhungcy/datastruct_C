#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n;
	scanf("%d", &n);
	int size = 100;
	int* tree = (int*)malloc(sizeof(int)*size);
	for(int i = 0;i<size;i++){
		tree[i] = 0;
	}
	int root, left, right;
	scanf("%d%d%d", &root, &left, &right);
	tree[1] = root;
	tree[2] = left;
	tree[3] = right; 
	int last = 0;
	while(1){
		
		scanf("%d", &root);
		if(root == -1){
			break;
		}
		scanf("%d%d", &left, &right);
		for(int i =0;i<size;i++){
			if(tree[i] == root){
				tree[i*2]= left;
				tree[i*2+1] = right;
				if(i*2+1 > last) {
					last = i*2+1;
				}
				break;
			}
		}
	}
	printf("%d", tree[1]);
	for(int i=2;i<last+1;i++){
		printf(" %d", tree[i]);
	}
	printf("\n");
	return 0;
}