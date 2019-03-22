#include <bits/stdc++.h> 

#define mod 1000000007 
using namespace std; 
char a[10000005]; 
long long quickmod(long long  a, long long  b){     
	long long ans=1;    
	while(b)     
	{         
		if(b&1)       
	    {             
			ans=(ans*a)%mod;         
		}     
	    b=b/2;         
		a=(a*a)%mod;     
	}   
	return ans; 
} 
int main() 
{     
	long long sum,len;
	int t;
	scanf("%d",&t);
	while(t--){
		getchar();
		while(gets(a))     
		{
			len=strlen(a);       
		    sum=0;         
		    for(int i=0;i<len;i++)      
			{
			    sum=(sum*10+a[i]-'0')%(mod-1);        
			}      
		    if(sum==0)
				cout<<quickmod(2,mod-2)<<endl;    
			else
			{	
				sum--;
				cout<<quickmod(2,sum)<<endl;
			}     
		}
	}
         
	return 0; 
}
