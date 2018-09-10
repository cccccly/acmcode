#include<bits/stdc++.h>

using namespace std;
int a[105];
bool vis[105];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int temp = a[1];
	int cnt = 1;
	vis[1] = 1;
	for(int i = 2;i <= n;i++){
		if(temp == a[i])
			vis[i] = 0;
		else{
			vis[i] = 1;
			cnt++;
		}
		temp = a[i];
	}
	printf("%d\n",cnt);
	for(int i = 1;i <= n;i++){
		if(vis[i])
			printf("%d ",a[i]);
	}
	return 0;
} 
