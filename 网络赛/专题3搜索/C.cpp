#include <bits/stdc++.h>

using namespace std;
#define MAXN 100003
#define ll long long
ll res[10003];

int cheak(ll x){
	int sum = 0;
	while(x){
		sum += x%10;
		x /= 10;
	}	
	return sum==10; 
} 

void init(){
	int i = 1;
	for(ll num = 19;i <= 10000;num+=9){
		if(cheak(num)){
			res[i++] = num;
		} 
	}
}
int main(){
	init();
//	for(int i = 1;i <= 10000;i++)
//		printf("%d\n",res[i]);
	int k;
	while(~scanf("%d",&k)){
		printf("%d\n",res[k]);
	}
	return 0;
}
