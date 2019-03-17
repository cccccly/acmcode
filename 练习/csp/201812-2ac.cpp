#include<iostream>
typedef long long ll;  //用long long,用int会爆掉内存
using namespace std;
int main()
{
		freopen("2.in","r",stdin);
  ll r,y,g;
	cin>>r>>y>>g;
	ll n;
	cin>>n;
    ll sum=0;
	ll cur;//代表走到路口时的时间
	while(n--)
	{
		int k,t;
		cin>>k>>t;
		if(k==0)
		{
			sum+=t;
		continue;
		}
	    if(k==1)
		{
		cur=(r-t)+sum;	
		cur%=(r+g+y);
		}
	     if(k==2)
		{
		cur=(r+g+y-t)+sum;
		cur%=(r+g+y);
		}
		 if(k==3)
		{
		cur=(r+g-t)+sum;
		cur%=(r+g+y);
		}
		if(cur>0&&cur<r)
		{
			k=1;
			t=r-cur;
		}
		 if(cur>=r&&cur<r+g)
		{
			k=3;
			t=r+g-cur;
		}
	    if(cur>=r+g&&cur<r+g+y)
		{
			k=2;
			t=r+g+y-cur;
		}
	      if(k==1)
		{
		  sum+=t;
		 
		}
		 if(k==2)
		{
	     sum+=(r+t);
		}
		 if(k==3)
		{
	      sum+=0;
		}
	}
	cout<<sum<<endl;
}
