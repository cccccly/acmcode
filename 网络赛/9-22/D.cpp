#include <bits/stdc++.h>

using namespace std;
#define maxn 1000005
int ab[maxn];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,c,temp;
		scanf("%d %d",&n,&c);
		for(int i = 1;i <= n;i++){
			scanf("%d",&ab[i]);
		}
		for(int i = 1;i <= n;i++){
			scanf("%d",&temp);
			ab[i] -= temp;
		}
		int f1 = 1,f2 = 1,h = c,flag = 0;
		while(f1<=n){
			while(h >= 0){
				if(f1 == f2){
					flag = 1;
					break;
				}
				h += ab[f2];
				f2 = f2 % n + 1;	
			}
			if(flag)
				break;
			else{
				while(h < 0 && f1 <= n){
					h -= ab[f1++];
					if(f2 < f1)
						f2 = f1;
				}
			}
		}
		if(flag == 0)
			puts("-1");
		else{
			printf("%d\n",f1);
		}
	}
	return 0;
} 
