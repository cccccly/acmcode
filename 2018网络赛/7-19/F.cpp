#include <bits/stdc++.h>

using namespace std;
#define MAXN 100003 
int fib[50];
map <int,int> mp;

int main()
{
	int count = 0;
	fib[1] = 1;
	fib[2] = 1;
	int p = 3;
	while(fib[p-1] <= 1000000){
		fib[p] = fib[p-1] + fib[p-2];
		p++;
	} 
	p--;
	int n;
	while(cin>>n){
		mp.clear();
		int temp;
		bool flag = false;
		for(int i = 1;i <= n;i++){
			scanf("%d",&temp);
			if(mp.count(temp)){
				if(temp == 1 && flag == false){
					mp[0] = i;
					flag = true;
				}
			}
			else mp[temp] = i;
		}
		if(flag){
			printf("%d %d\n",mp[1],mp[0]);
			continue;
		}
		else{
			for(int i = 3;i <= 30;i++){
				if(mp.count(fib[i])){
					if(mp.count(fib[i+1])){
						flag = true;
						printf("%d %d\n",mp[fib[i]],mp[fib[i+1]]);
						break;
					}	
				}
			}
		}
		if(!flag)
			puts("impossible");
	}
} 
