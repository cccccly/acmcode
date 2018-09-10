#include <bits/stdc++.h>

using namespace std;
#define MAXN 1000010
int a[MAXN];
int main()

{
	int T;
	scanf("%d",&T);
	for(int j = 1;j <= T;j++){
		int  n,v;
		scanf("%d%d",&n,&v);
		for(int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		int p1=1,p2=n;
		int sum=0,res=-1;
		while(sum < v&&p1 <= p2){
			sum += a[p1];
			res = a[p1];
			p1++;
			if(sum >= v||p1 > p2)
				break;
			sum += a[p2];
			p2--;
		}
		if(sum < v){
			printf("Case #%d: -1\n",j);
		}
		else{
			printf("Case #%d: %d\n",j,res);
		}
	}
	return 0;
 } 
