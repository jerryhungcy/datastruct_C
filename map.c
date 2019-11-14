#include<stdio.h>
#include<stdlib.h>

char map[10][10];
int s1 = 8, s2 = 8;
int e1 = 1, e2 = 1;
struct position{
	int x;
	int y;
	int d;
};

struct position p[100];

int step=0;
int walk(int px, int py, int derction){
	
	map[px][py] = 'G';
	//printf("%d %d %c\n", px, py , map[px][py]);
	if(px == e1 && py == e2){
		return 1;
	}else
	switch(derction){
		case 0:
			if(map[px][py+1] == '0'){
				p[step].x = px;
				p[step].y = py;
				p[step].d = 1;
				step++;
				return walk(px, py+1, 0);
				break;
			}
		case 1:
			if(map[px-1][py] == '0'){
				p[step].x = px;
				p[step].y = py;
				p[step].d = 2;
				step++;
				return walk(px-1, py, 0);
				break;
			}
		case 2:
			if(map[px][py-1] == '0'){
				
				p[step].x = px;
				p[step].y = py;
				p[step].d = 3;
				step++;
				return walk(px, py-1, 0);
				break;
			}
		case 3:
			if(map[px+1][py] == '0'){
				
				p[step].x = px;
				p[step].y = py;
				p[step].d = 4;
				step++;
				return walk(px+1, py, 0);
				break;
			}
		default:
			if(px == s1 && py == s2){
				return 0;
			}else{
				map[px][py] = 'D';
				//printf("%d %d %c\n", px, py , map[px][py]);
				step--;
				return walk(p[step].x, p[step].y, p[step].d);
			}
			break;
	}
	return 0;
}


int main(){
	for(int i =0;i<10;i++){
		for(int j =0;j<10;j++){
			scanf(" %c", &map[i][j]);
		}
	}
	if(walk(s1, s2, 0)){
		printf("YES\n");
	}else printf("NO\n");
	map[s1][s2] = 'S';
	map[e1][e2] = 'X';
	for(int i =0;i<10;i++){
		printf("%c", map[i][0]);
		for(int j =1;j<10;j++){
			printf(" %c", map[i][j]);
		}
		printf("\n");
	}
}