#include <iostream>
#include<stdio.h>

using namespace std;
#define MAXN 600003
long long mod[MAXN];

int main(){
	int n;
	while(~scanf("%d",&n)&&n){
		int i;
		for(i = 1; ;i++){
			mod[i] = mod[i/2]*10+i%2;
			if(mod[i]%n == 0)
				break;
		}
		printf("%lld\n",mod[i]);
	}
	return 0;
} 
