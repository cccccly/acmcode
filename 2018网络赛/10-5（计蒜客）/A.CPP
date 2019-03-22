#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while(~scanf("%d",&n)){
		int a,b;
		for(int i = 1;i <= n;i++){
			scanf("%d %d",&a,&b);
			if(a > b)
				printf("%d\n",a*2+b);
			else
				printf("%d\n",b*2+a);
		}
	}
	return 0;
} 
