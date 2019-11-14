#include<stdio.h>

struct polynomial{

    float coef; //係數

    unsigned int expon; //次數

};

typedef struct polynomial poly;

int main(){
	int len1, len2;
	scanf("%d", &len1);
	poly first[len1+1];
	for(int i=0;i<len1;i++){
		scanf("%f%d", &first[i].coef, &first[i].expon);
	}
	scanf("%d", &len2);
	poly sec[len2+1];
	poly last[len1 + len2];
	int index1 = 0, index2 = 0 , indexlast = 0;
	for(int i=0;i<len2;i++){
		scanf("%f%d", &sec[i].coef, &sec[i].expon);
	}
	first[len1].expon = 0, sec[len2].expon=0;
	while(index1 < len1 || index2 < len2){
		if(sec[index2].expon > first[index1].expon){
				last[indexlast].coef = sec[index2].coef;
				last[indexlast].expon = sec[index2].expon;
				index2++;
		}else if(sec[index2].expon == first[index1].expon){
				last[indexlast].coef = sec[index2].coef + first[index1].coef;
				last[indexlast].expon = sec[index2].expon;
				index1++;
				index2++;
		}else if(sec[index2].expon < first[index1].expon){
				last[indexlast].coef = first[index1].coef;
				last[indexlast].expon = first[index1].expon;
				index1++;
		}
		indexlast++;
	}
	for(int i=0;i<len1;i++){
		if(first[i].coef != 0){
			if(i>0 && first[i].coef > 0) printf("+");
			printf("%.2f", first[i].coef);
			if(first[i].expon>1){
				printf("x^%d", first[i].expon);
			}else if(first[i].expon == 1){
				printf("x");
			}
		}
		
	}
	printf("\n");
	for(int i=0;i<len2;i++){
		if(sec[i].coef != 0){
			if(i>0 && sec[i].coef > 0) printf("+");
			printf("%.2f", sec[i].coef);
			if(sec[i].expon>1){
				printf("x^%d", sec[i].expon);
			}else if(sec[i].expon == 1){
				printf("x");
			}
		}
	}
	printf("\n");
	for(int i=0;i<indexlast;i++){
		if(last[i].coef != 0){
			if(i>0 && last[i].coef>0) printf("+");
			printf("%.2f", last[i].coef);
			if(last[i].expon>1){
				printf("x^%d", last[i].expon);
			}else if(last[i].expon == 1){
				printf("x");
			}
		}
	}
	printf("\n");
	return 0;
}