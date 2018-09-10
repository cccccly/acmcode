#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 1e5+5;
int a[N];
ll sum[N],sum1[N];
int n,q;
void update(int b,int c){
	int temp = a[b];
	a[b] = c;
	for(int i = b;i <= n;i++){
		sum[i] =  sum[i] - temp + c;
		sum1[i] = sum1[i] - (ll)(i-b+1)*(temp - c);
	}
}


int main(){
//	freopen("Hin.txt","r",stdin); 
//	freopen("Hout.txt","w",stdout); 
	while(~scanf("%d%d",&n,&q)){
		sum[0]=0;
		sum1[0]=0;
		for(int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
		}
		sum[1] = a[1];
		for(int i = 2;i <= n;i++){
			sum[i] = sum[i-1] + a[i];
		}
		ll temp = 0;
		for(int i = n;i >= 1;i--){
			temp += sum[i];
		}
		sum1[n] = temp;
		for(int i = n-1;i >= 1;i--){
			sum1[i] = sum1[i+1]-sum[i+1];
		}
		for(int i = 1;i <= q;i++){
			int op,L,b,c;
			scanf("%d%d%d",&op,&b,&c);
			if(op == 1){
				printf("%lld\n",(ll)(sum1[c]-sum1[b-1]-(c-b+1)*sum[b-1]));
			}
			else{
				update(b,c);
			}
		}
	}
	return 0;
}
