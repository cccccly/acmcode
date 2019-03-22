#include <bits/stdc++.h>  
using namespace std;  

typedef long long ll;  
const int maxn = 7; //矩阵大小 
const ll mod = 2147493647;
//矩阵结构体定义 
struct Matrix {   
    ll s[maxn][maxn];  
    Matrix(){ memset(s,0,sizeof(s));  };  
    Matrix operator * (const Matrix& c) {  
	    Matrix ans;  
	    for (int i = 0; i < maxn; i++) //矩阵乘法  
	        for (int j = 0; j < maxn; j++)  
	            for (int k = 0; k < maxn; k++)  
	                ans.s[i][j] = (ans.s[i][j] + (s[i][k] * c.s[k][j]) % mod) % mod;  
    	return ans;  
    }  
    void unit(){
    	memset(s,0,sizeof(s)); 
    	for(int i = 0;i < maxn;i++)
    		s[i][i] = 1;
	}
};  
  
//矩阵快速幂 
Matrix pow_mod(Matrix a,ll k) {  
	Matrix ans;
	ans.unit();
	while(k){
		if(k&1)
			ans = ans*a;
		k>>=1;
		a = a*a;
	} 
    return ans;  
}  

const ll init[maxn][maxn] = {
	{1,1,0,0,0,0,0},
	{2,0,0,0,0,0,0},
	{1,0,1,0,0,0,0},
	{0,0,4,1,0,0,0},
	{0,0,6,3,1,0,0},
	{0,0,4,3,2,1,0},
	{0,0,1,1,1,1,1}
};

int main()
{
	int T;
	Matrix A;	
	while(~scanf("%d",&T)){
		while(T--){
			ll n,a,b;
			memcpy(A.s, init ,sizeof(init));
			scanf("%lld%lld%lld",&n,&a,&b);
			if(n == 1){
				printf("%lld\n",a);
				continue;
			}
			else if(n == 2){
				printf("%lld\n",b);
				continue;
			}
			else{
				A = pow_mod(A,n-2);
				Matrix ans;
				ll init2[maxn][maxn] = {
					{b,a,81,27,9,3,1},
					{0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0}
				};
				memcpy(ans.s, init2, sizeof(init2));
				ans = ans*A;
				printf("%lld\n",ans.s[0][0]);
			}
		}
	}
	return 0;
}
