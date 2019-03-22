#include <bits/stdc++.h>

using namespace std;

#define ll long long

const long long mod = 7;
const int maxn = 2;   //矩阵大小 

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
	ans.unit();  //单位化 
	while(k){
		if(k&1)
			ans = ans*a;
		k>>=1;
		a = a*a;
	} 
    return ans;  
}  

Matrix init(int a,int b){
	Matrix ans;
	ans.s[0][0] = a;
	ans.s[0][1] = 1;
	ans.s[1][0] = b;
	return ans;
}
int main()
{
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);
	if(n <= 2){
		puts("1");
		return 0;
	}
	Matrix A;
	A = init(a,b);
	A = pow_mod(A,n-2);
	printf("%d\n",(A.s[0][0]+A.s[1][0]+14)%7);
	return 0;
} 
