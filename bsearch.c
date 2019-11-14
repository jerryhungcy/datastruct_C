 #include<stdio.h>
 #include<stdlib.h>

 int bsearch(int* a, int n, int head, int tail){
 	if(a[head] == n){
 		return head;
 	}else if(a[tail] == n){
 		return tail;
 	}
 	int mid = (head + tail)/2;
 	if(a[mid]> n){
 		return bsearch(a, n, head, mid);
 	}else if(a[mid] < n){
 		return bsearch(a, n, mid, tail);
 	}else if(a[mid] == n) return mid;
 	return 0;
 }

 int main(){
 	int n, t;
 	scanf("%d%d", &t, &n);
 	int array[n];
 	for(int i=0;i<n;i++){
 		scanf("%d", &array[i]);
 	}
 	printf("%d\n", bsearch(array, t, 0, n-1));
 }