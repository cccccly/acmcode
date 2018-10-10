#include<bits/stdc++.h>

using namespace std;
#define maxn 1010
int a[maxn][maxn];
int main(){
	int n;
	while(~scanf("%d",&n)){
		int x,y;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j] == -1)
					x = i,y = j;
			}
		}
		int x1,y1,mn = 10001;
		if(x == 1){
			x1 = 2;
		}
		else x1 = 1;
		if(y == 1){
			y1 = 2;
		}
		else y1 = 1;
		int xcnt,ycnt;
		for(int i = 1;i <= n;i++){
			mn = min(mn,a[x1][i]);
		}
		ycnt = a[x1][y] - mn;
		xcnt = a[x1][y1] - mn;
		xcnt = a[x][y1] - xcnt;
		printf("%d\n",xcnt+ycnt);
	}
	return 0;
}
