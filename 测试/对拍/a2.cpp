#include<bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
const int MAXN = 1010;
 
int n,m;
char G[MAXN][MAXN];
int fire[MAXN][MAXN];  //���յ���i��j������Сʱ�� 
int Time[MAXN][MAXN];  //�˵��i��j������Сʱ�� 
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
 
void bfsFire(){   //����յ���i��j������Сʱ�� 
	memset(fire,-1,sizeof(fire));
	queue< pair<int,int> > q;
	for(int i = 0 ; i<n ; i++){
		for(int j = 0 ; j<m ; j++){
			if(G[i][j] == 'F'){
				fire[i][j] = 0;                //FΪ��ĳ�ʼλ�ã�ʱ��Ϊ0 
				q.push(make_pair(i,j));
			}
		}
	} 
	while(!q.empty()){
		pair<int,int> temp = q.front();
		q.pop();
		int x = temp.first; int y = temp.second;
		
		for(int i = 0 ; i<4 ; i++){
			int nxtx = x+dir[i][0];
			int nxty = y+dir[i][1];
			
			if(nxtx<0 || nxtx>=n || nxty<0 || nxty>=m) //��ͼ֮�� 
				continue;
			if(fire[nxtx][nxty]!=-1)                   //��֮ǰ�Ѿ��յ� 
				continue; 
			if(G[nxtx][nxty] == '#')                   //��ǽ 
				continue;
			
			fire[nxtx][nxty] = fire[x][y] + 1;
			q.push(make_pair(nxtx,nxty));
		}
	}
} 
 
int bfs(){   //�����ܳ��Թ�����Сʱ�� 
	queue< pair<int,int> > q;
	memset(Time,-1,sizeof(Time));
	
	for(int i = 0 ; i<n ; i++){
		for(int j = 0 ; j<m ; j++){
			if(G[i][j] == 'J'){
				q.push(make_pair(i,j));
				Time[i][j] = 0;              //JΪJOE���ܵ���ʼλ�ã�ʱ��Ϊ0 
			}
		}
	}
	
	while (!q.empty()){
		pair<int,int> temp = q.front();
		q.pop();
		
		int x = temp.first;
		int y = temp.second;
		
		if(x==0 || y==0 || x==n-1 || y==m-1)   //��˳������߽缴Ϊ�ӳ��߽硣�ӳ�ȥ��ʱ��Ҫ+1�����ӱ߽��ܳ�ȥ 
			return Time[x][y]+1;
			
		for(int i = 0 ; i<4 ; i++){
			int nxtx = x+dir[i][0];
			int nxty = y+dir[i][1];
			
			if(Time[nxtx][nxty] != -1)      //֮ǰ�Ѿ������� 
				continue;
			if(nxtx<0 || nxtx>=n || nxty<0 || nxty>=m)   //��һ���ڹ涨��Χ֮�� 
				continue;
			if(G[nxtx][nxty] == '#')                //��һ����ǽ 
				continue;
			if(fire[nxtx][nxty]!=-1 && Time[x][y]+1>=fire[nxtx][nxty])  //����С�����ʱ��Ȼ��յ���ʱ��� 
				continue;
			
			Time[nxtx][nxty] = Time[x][y] + 1;
			q.push(make_pair(nxtx,nxty));
		} 
	} 
	return -1;
}
 
int main(){
	freopen("data//a.in","r",stdin);
	ios::sync_with_stdio(false);
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d %d",&n,&m); 
		for(int i = 0 ; i<n ; i++){
			scanf("%s",G[i]);
		}
		bfsFire();
		
		int ans = bfs();
		if(ans == -1)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n",ans);
	}
		
	return 0;
}
