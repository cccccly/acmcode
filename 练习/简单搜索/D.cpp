#include <stdio.h>
#include <string.h>
using namespace std;
int M,N,ans,temp;
int maze[20][20];
int opt[20][20]; //�������Ž�
int flip[20][20]; //�����м���
int dx[4] = {0,-1,0,0};
int dy[4] = {0,0,-1,1}; 

int judge(int x,int y){  //check (x,y)��û����һ��Ӱ���״���µ���ɫ
	int x2,y2,res = maze[x][y]; 
	for(int i = 0;i < 4;i++){
		x2 = x + dx[i];
		y2 = y + dy[i];
		if(x2 >= 0 && x2 < M && y2 >= 0 && y2 < N)
			res += flip[x2][y2];
	}
	return res % 2;
}

int calc(){
	for(int i = 1;i < M;i++){   //ȷ��1 ~ M�е�flip 
		for(int j = 0;j < N;j++){
			if(judge(i-1,j) == 1){ //��һ��ש�Ǻڵ� ֻ�����ש����ת�� 
				flip[i][j] = 1;
				temp++;
			}
		}
	}
	for(int i = 0;i < N;i++){   //check���һ���Ƿ�ȫ�� 
		if(judge(M-1,i) == 1)
			return 0;
	}
	return 1;
}


int main(){
	while(~scanf("%d %d",&M,&N)){
		for(int i = 0;i < M;i++){
			for(int j = 0;j < N;j++)
				scanf("%d",&maze[i][j]);
		}
		ans = 0x7fffffff;
		for(int i = 0;i < 1<<N;i++){  //���ǵ�һ����2^N��� 
			memset(flip,0,sizeof(flip));
			temp = 0;
			for(int j = 0;j < N;j++){
				if(i>>j&1){
					flip[0][j] = 1;
					temp++;    //��ת 
				}	
			}
		 	if(calc() && temp < ans){//�����ַ����Ŀ��������� 	
				ans = temp;
				memcpy(opt,flip,sizeof(flip));	  //����һ�����Ž� 
			}
			
//			for(int i = 0 ;i < M;i++){
//				for(int j = 0;j < N;j++){
//					printf("%d ",flip[i][j]);
//				}
//				puts("");
//			}
//			puts("");
		}
		if(ans == 0x7fffffff)
			puts("IMPOSSIBLE");
		else
			for(int i = 0 ;i < M;i++){
				for(int j = 0;j < N;j++){
					if(j == N-1)
						printf("%d",opt[i][j]);
					else
						printf("%d ",opt[i][j]);
				}
				puts("");
			}
	}
	return 0;
}
