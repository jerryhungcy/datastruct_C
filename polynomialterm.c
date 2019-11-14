#include<stdio.h>
#include<stdlib.h>

struct polynomial{

    float coef; //係數

    unsigned int expon; //次數

};

typedef struct polynomial poly;
struct polystring
{
	int size;
	poly* member;
};

typedef struct polystring ps;
void printPoly(ps polys){
	for(int i=0;i<polys.size;i++){
		if(polys.member[i].coef != 0){
			if(i>0 && polys.member[i].coef>0) printf("+");
			printf("%.2f", polys.member[i].coef);
			if(polys.member[i].expon>1){
				printf("x^%d", polys.member[i].expon);
			}else if(polys.member[i].expon == 1){
				printf("x");
			}
		}
	}
	printf("\n");
}
int cmp(const void *a, const void *b){
	poly* c = (poly*)a;
	poly* d = (poly*)b;
	if(c->expon > d->expon)return -1;
	else if(c->expon < d->expon)return 1;
	else return 0;
}

int main(){
	int len1, len2;
	scanf("%d", &len1);
	ps first;
	first.size = len1;
	first.member = (poly*)malloc(sizeof(poly) * len1);
	for(int i=0;i<first.size;i++){
		scanf("%f%d", &first.member[i].coef, &first.member[i].expon);
	}
	
	scanf("%d", &len2);
	ps sec;
	sec.size = len2;
	sec.member = (poly*)malloc(sizeof(poly) * len2);
	for(int i=0;i<len2;i++){
		scanf("%f%d", &sec.member[i].coef, &sec.member[i].expon);
	}
	
	ps ans;
	ans.size = len1*len2;
	ans.member = (poly*)malloc(sizeof(poly) *len1* len2);
	int t=0;
	for(int i= 0;i<len1;i++){
		for(int j = 0;j<len2;j++){
			ans.member[t].coef = first.member[i].coef * sec.member[j].coef;
			ans.member[t].expon = first.member[i].expon + sec.member[j].expon;
			t++;
		}
	}
	qsort(&ans.member[0], t, sizeof(poly), cmp);
	float sum = ans.member[0].coef;
	int size_of_ans = 0;
	int ex = ans.member[0].expon;
	for(int i =1;i<ans.size;i++){
		if(ans.member[i].expon == ex){
			sum += ans.member[i].coef;
		}else {
			ans.member[size_of_ans].coef = sum;
			ans.member[size_of_ans].expon = ex;
			sum = ans.member[i].coef;
			ex = ans.member[i].expon;
			size_of_ans++;
		}

	}
	ans.member[size_of_ans].coef = sum;
	ans.member[size_of_ans].expon = ex;
	size_of_ans++;
	ans.size = size_of_ans;
	printPoly(first);
	printPoly(sec);
	printPoly(ans);

	return 0;
}