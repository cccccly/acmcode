#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	int a,n;
	while(T--){
		scanf("%d%d",&n,&a);
		if(n == 1){
			printf("1 %d\n",a+1);
		}
		else if(n == 2){
			int temp = a/2;
			if(a%2){
				
				printf("%d %d\n",2*temp*temp+2*temp,2*temp*temp+2*temp+1);
			}
			else {
				printf("%d %d\n",temp*temp-1,temp*temp+1);
			}
		}
		else
			printf("-1 -1\n");
	}
	return 0;
} 
