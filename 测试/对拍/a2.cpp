#include<bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
const int MAXN = 1010;
 
int n,m;
char G[MAXN][MAXN];
int fire[MAXN][MAXN];  //火烧到（i，j）的最小时间 
int Time[MAXN][MAXN];  //人到达（i，j）的最小时间 
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
 
void bfsFire(){   //求火烧到（i，j）的最小时间 
	memset(fire,-1,sizeof(fire));
	queue< pair<int,int> > q;
	for(int i = 0 ; i<n ; i++){
		for(int j = 0 ; j<m ; j++){
			if(G[i][j] == 'F'){
				fire[i][j] = 0;                //F为火的初始位置，时间为0 
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
			
			if(nxtx<0 || nxtx>=n || nxty<0 || nxty>=m) //地图之外 
				continue;
			if(fire[nxtx][nxty]!=-1)                   //火之前已经烧到 
				continue; 
			if(G[nxtx][nxty] == '#')                   //是墙 
				continue;
			
			fire[nxtx][nxty] = fire[x][y] + 1;
			q.push(make_pair(nxtx,nxty));
		}
	}
} 
 
int bfs(){   //求人跑出迷宫的最小时间 
	queue< pair<int,int> > q;
	memset(Time,-1,sizeof(Time));
	
	for(int i = 0 ; i<n ; i++){
		for(int j = 0 ; j<m ; j++){
			if(G[i][j] == 'J'){
				q.push(make_pair(i,j));
				Time[i][j] = 0;              //J为JOE逃跑的起始位置，时间为0 
			}
		}
	}
	
	while (!q.empty()){
		pair<int,int> temp = q.front();
		q.pop();
		
		int x = temp.first;
		int y = temp.second;
		
		if(x==0 || y==0 || x==n-1 || y==m-1)   //能顺利到达边界即为逃出边界。逃出去的时间要+1，即从边界跑出去 
			return Time[x][y]+1;
			
		for(int i = 0 ; i<4 ; i++){
			int nxtx = x+dir[i][0];
			int nxty = y+dir[i][1];
			
			if(Time[nxtx][nxty] != -1)      //之前已经搜索过 
				continue;
			if(nxtx<0 || nxtx>=n || nxty<0 || nxty>=m)   //下一步在规定范围之外 
				continue;
			if(G[nxtx][nxty] == '#')                //下一步是墙 
				continue;
			if(fire[nxtx][nxty]!=-1 && Time[x][y]+1>=fire[nxtx][nxty])  //人最小到达的时间比火烧到的时间大 
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
