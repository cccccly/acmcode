#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define ll long long

int main(){
	int T;
	scanf("%d",&T);
	ll A,B,C,D,P,n;
	while(T--){
		scanf("%lld%lld%lld%lld%lld%lld",&A,&B,&C,&D,&P,&n);
		if(n == 1){
			printf("%lld\n",A);
		}
		else if(n == 2){
			printf("%lld\n",B);
		}
		else{
			ll temp;
				ll i = 3;
				temp = (A%mod);
				printf ("%lld\n",temp);
				temp = (C%mod);
				printf ("%lld\n",temp);
				temp = (A%mod)*(C%mod)%mod;
				printf ("%lld\n",temp);
				temp = (B%mod);
				printf ("%lld\n",temp);
				temp = (D%mod);
				printf ("%lld\n",temp);
				temp = (B%mod)*(D%mod)%mod;
				printf ("%lld\n",temp);
				temp = P/i;
				printf ("%lld\n",temp);
//				temp = (A%mod)*(C%mod)%mod + (B%mod)*(D%mod)%mod + P/i;
//				A = B;
//				B = temp;
			
			
		}
				
	}
	return 0;
} 
