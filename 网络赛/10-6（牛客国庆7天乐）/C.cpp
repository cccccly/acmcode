#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while(~scanf("%d",&n)){
		if(n == 1){
			puts("0");
			continue;
		}
		else if(n == 2){
			puts("1");
			continue;
		}
		else {
			printf("%d\n",n);
		}
	}
	return 0;
} 
