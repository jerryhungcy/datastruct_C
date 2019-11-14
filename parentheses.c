#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int len;
	char s[100];
	
	while(1){
		scanf("%s", s);
		len = strlen(s);
		printf("%d\n", len);
		if(s[0] == 'e') break;
		int q =0;
		for(int i=0;i<len;i++){
			if(s[i] == '('){
				q++;
			}else if(s[i] == ')'){
				if(q){
					q--;
				}else{
					q = -1;
					break;
				} 
			}
		}
		if(q ==0){
			printf("1\n");
		}else printf("-1\n");
	}
	return 0;
}