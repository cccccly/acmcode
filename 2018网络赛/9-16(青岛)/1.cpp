#include <bits/stdc++.h>

using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d %d",&n,&m);
		if(m == 0)
			puts("0 0");
		else {
			int b = n-m;
			if(b == 0){
				printf("%d %d\n",m,m);
				continue;
			}
			else if(b >= m){
				printf("%d 1\n",m);
				continue;
			}
			int temp = m / (b+1);
			if(m %(b+1))
				temp++;
			printf("%d %d\n",m,temp);
		}
	}
	return 0;
} 
