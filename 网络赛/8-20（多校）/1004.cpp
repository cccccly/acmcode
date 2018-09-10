#include <bits/stdc++.h>
#define inf 0x3f3f3f
#define ll long long
using namespace std;

const ll mod = 998244353;

ll gcd(ll a,ll b)
{
    return b>0?gcd(b,a%b):a;
}


int main()
{
	int t;
	ll a,b,c,a1,b1,c1;
	ll res,sign,temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&a1,&b1,&c1);
		res = a1*(c-b)+b1*(a-c)+c1*(b-a);
		if(res < 0)
		{
			sign = -1;
			res *= sign;
		}
		else if(res > 0)
		{
			sign = 1;
		}
		else 
		{
			puts("0");
			continue;
		}
		temp = gcd(res,a+b+c);
		ll fm = a+b+c;
		res /= temp,fm /= temp;
		if(fm == 1){
			printf("%lld\n",res*sign);
		}
		else{
			printf("%lld/%lld\n",res*sign,fm);
		}
	}
	return 0;
} 
