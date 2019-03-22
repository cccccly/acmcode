#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int x1,y1,x2,y2;
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	if((abs(x2-x1) + abs(y2-y1)) % 2 == 1)
		puts("Lose");
	else puts("Win");
	return 0;
} 
