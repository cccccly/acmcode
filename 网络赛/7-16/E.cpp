#include <bits/stdc++.h>

using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 1000010

int a[MAXN];    //ai 表示删除i数后会减少的好数数量 

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n,temp;
		int min1=MAXN,min2=MAXN; //最小和次小
		memset(a , 0 ,sizeof(a)); 
		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
			scanf("%d",&temp);
			if(temp < min1){    //不好的数
				min2 = min1;
				min1 = temp;
				a[temp] = 0;  
			}
			else if(temp < min2){  //好数但是可能会变成不好的数 
				min2 = temp;
				a[temp] = 1;      //首先删除自己让总数-- 
				a[min1]++;        
			}
			else a[temp] = 1;     //好数不影响后面的数  只是让good总数-- 
		}
		int ans = 0;
//		for(int i = 1;i <= n;i++){
//			printf("%d ",a[i]);
//		}
	/*显然优先选删除不好的数且影响为0的 如果没有 那么就找一个最小的影响为1个数*/
		for(int i = 1;i <= n;i++){
			if(a[i] == 0){
				ans = i;
				break;
			}
		}
		if(!ans){
			for(int i = 1;i <= n;i++){
				if(a[i] == 1){
					ans = i;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;	
} 
