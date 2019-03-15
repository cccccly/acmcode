#include <stdio.h>

using namespace std;
int M,N;
int maze[20][20];
int opt[20][20]; //保存最优解
int flip[20][20]; //保存中间结果 

int 


int main(){
	while(~scanf("%d %d",&M,&N)){
		for(int i = 0;i < M;i++){
			for(int j = 0;j < N;j++)
				scanf("%d",maze[i][j]);
		}
		
		for(int i = 0;i < 1<<N;i++){  //考虑第一行有2^N情况 
			for(int j = 0;j < N;j++){
			 	flip[0][j] = i>>j&1;    //倒序放置 
			 	cacl(); 
			}
		}
	}
	
	return 0;
}
