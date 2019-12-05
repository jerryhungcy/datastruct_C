#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int last;
void getlast(int t){
	if(t> last){
		last = t;
	}
}


int main(){
	char treeC[1000];
	int treeI[1000];
	int q =0, p=0, i=1;
	for(int j = 0;j<1000;j++){
		treeC[j] = '?';
		treeI[j] = -1; 
	}
	char temp;
	scanf("%c", &temp);
	q++;
	last = 0;
	while(q!=p){
		scanf(" %c", &temp);
		//printf("%c ", temp);
		if(temp == '('){
			/*if(treeC[i*2] != ' '){
				i = i*2+1;
			}else{i = i*2;}*/
			q++;
		}else if(temp == ')'){
			p++;
		}else if(temp >='0' && temp <='9'){
			if(treeC[i*2] == '?'){
				treeC[i*2] = temp;
				treeI[i*2] = temp - '0';
				getlast( i*2);
			}else{
				treeC[i*2+1] = temp;
				treeI[i*2+1] = temp - '0';
				getlast( i*2+1);
			}
			while(treeC[i*2] != '?' && treeC[i*2+1] != '?'){ i = i/2;}
		}else if((temp >= 'a' && temp <='z') || (temp >= 'A' && temp <='Z')){
			if(treeC[i*2] == '?'){
				treeC[i*2] = temp;
				getlast( i*2);
			}else{
				treeC[i*2+1] = temp;
				getlast( i*2+1);
			}
			while(treeC[i*2] != '?' && treeC[i*2+1] != '?'){ i = i/2;}
		}else {
			if(treeC[i] == '?'){
				treeC[i] = temp;
			}else if(treeC[i*2] == '?'){
				treeC[i*2] = temp;
				i = i*2;
			}else{
				treeC[i*2+1] = temp;
				i = i*2+1;
			}
		}
	}
	treeC[0] ='?'; 
	last += 1;
	treeC[last] ='\0';
	//printf("%s", treeC);
	char c, e;
	int n;
	while(scanf(" %c %c %d", &c, &e, &n) != EOF){
		for(int j =1 ;j<last; j++){
			if(treeC[j] == c){
				treeC[j] = n + '0';
				treeI[j] = n;
				//printf("\n%c %c %d treeC %c", c, e, n, treeC[j]);
			}
		}
	}
	int h = last, count = 0;
	while(h){h/=2; count++;}
	//printf("count = %d", count);
	int start = (int)pow(2, count-1)-1;
	//printf("\nstart = %d\n", start);
	for(int j =start;j>0;j--){
		switch(treeC[j]){
			case'*':
				treeI[j] = treeI[j*2] * treeI[j*2+1];
				break;
			case'/':
				treeI[j] = treeI[j*2] / treeI[j*2+1];
				break;
			case'+':
				treeI[j] = treeI[j*2] + treeI[j*2+1];
				break;
			case'-':
				treeI[j] = treeI[j*2] - treeI[j*2+1];
				break;
			default:
				break;
		}
	}
	printf("%d\n",treeI[1]);
	return 0;
}