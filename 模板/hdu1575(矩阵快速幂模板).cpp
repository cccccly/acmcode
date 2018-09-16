#include <bits/stdc++.h>  
using namespace std;  
  
  
typedef long long ll;  
const int maxn = 12; //矩阵大小 
const int mod = 9973;
//矩阵结构体定义 
struct Matrix {   
    ll s[maxn][maxn];  
    Matrix(){ memset(s,0,sizeof(s));  };  
    Matrix operator * (const Matrix& c) {  
	    Matrix ans;  
	    for (int i = 0; i < maxn; i++) //矩阵乘法  
	        for (int j = 0; j < maxn; j++)  
	            for (int k = 0; k < maxn; k++)  
	                ans.s[i][j] = (ans.s[i][j] + s[i][k] * c.s[k][j]) % mod;  
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

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		Matrix A;
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++)
				scanf("%lld",&A.s[i][j]);
		}
		A = pow_mod(A,k);
		ll ans = 0;
		for(int i = 0;i < n;i++){
			ans += A.s[i][i];
			ans %= mod;
		}
		printf("%lld\n",ans); 
	}
	return 0;
}
