#include <bits/stdc++.h>  
using namespace std;  
typedef long long ll;  
const int maxn = 4; //矩阵大小 
const int mod = 1e9+7;
//矩阵结构体定义 
struct Matrix {   
    ll s[maxn][maxn];  
    Matrix(){ memset(s,0,sizeof(s));  };  
    Matrix operator * (const Matrix& c) {  
	    Matrix ans;  
	    for (int i = 0; i < maxn; i++) //矩阵乘法  
	        for (int j = 0; j < maxn; j++)  
	            for (int k = 0; k < maxn; k++)  
	                ans.s[i][j] = (ans.s[i][j] + s[i][k] * c.s[k][j] % mod) % mod;  
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
		Matrix A,ans;
		ll n;
		scanf("%lld",&n);
		A.s[0][0] = 2,A.s[0][1] = 1,A.s[0][2] = 0,A.s[0][3] = 0;
		A.s[1][0] = -1,A.s[1][1] = 0,A.s[1][2] = 1,A.s[1][3] = 0;
		A.s[2][0] = 3,A.s[2][1] = 0,A.s[2][2] = 0,A.s[2][3] = 1;
		A.s[3][0] = 2,A.s[3][1] = 0,A.s[3][2] = 0,A.s[3][3] = 0;
		ans.s[0][0] = 244,ans.s[0][1] = 106,ans.s[0][2] = 46,ans.s[0][3] = 20;
		if(n == 1)
			puts("3");
		else if(n == 2)
			puts("9");
		else if(n == 3)
			puts("20");
		else if(n == 4)
			puts("46");
		else if(n == 5)
			puts("106");
		else if(n == 6)
			puts("244");
		else{
			A = pow_mod(A,n-6);
			ans = ans*A;
			printf("%lld\n",ans.s[0][0]); 
		} 
	}
	return 0;
}
