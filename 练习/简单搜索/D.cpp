#include <stdio.h>

using namespace std;
int M,N;
int maze[20][20];
int opt[20][20]; //�������Ž�
int flip[20][20]; //�����м��� 

int 


int main(){
	while(~scanf("%d %d",&M,&N)){
		for(int i = 0;i < M;i++){
			for(int j = 0;j < N;j++)
				scanf("%d",maze[i][j]);
		}
		
		for(int i = 0;i < 1<<N;i++){  //���ǵ�һ����2^N��� 
			for(int j = 0;j < N;j++){
			 	flip[0][j] = i>>j&1;    //������� 
			 	cacl(); 
			}
		}
	}
	
	return 0;
}
