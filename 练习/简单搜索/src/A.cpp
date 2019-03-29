#include <stdio.h>
#include <string.h>
using namespace std;
#define maxn 10
int maze[maxn][maxn];//��¼���� 
int vis[maxn];//��i���Ƿ����������? 
int count,tot;//��ǰ���õ������� �������� 
int n,k;  //���̴�С ������ 
void dfs(int cur){
	if(count == k){ //�ﵽ���� 
		tot++;
		return; 
	}
	if(cur > n) //�ѳ������� 
		return;
	for(int i = 1;i <= n;i++){
		if(!vis[i] && maze[cur][i]){ //��ǰ��û������ �ҵ�ǰ�����? 
			vis[i] = 1;
			count++;
			dfs(cur+1);
			vis[i] = 0;  //���� 
			count--;
		}
	}
	dfs(cur+1); //���ܷŲ������� 
}

int main(){
	
	while(~scanf("%d%d",&n,&k)){
		if(n == -1 && k == -1)
			break;
		getchar();
		char c;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				c = getchar();
				if(c == '.')
					maze[i][j] = 0;
				else
					maze[i][j] = 1;
			}
			getchar();
		}
		count = 0,tot = 0;
		memset(vis,0,sizeof(vis));
		dfs(1);
		printf("%d\n",tot);	
	}
	return 0;
} 
