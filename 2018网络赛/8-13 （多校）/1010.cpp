#include <bits/stdc++.h>

using namespace std;

#define ll long long

const long long mod = 1e9+7;
const int maxn = 3;   //矩阵大小 

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

Matrix init(ll C,ll D,ll x){
	Matrix ans;
	ans.s[0][0] = D;ans.s[0][1] = 1;
	ans.s[1][0] = C;
	ans.s[2][0] = x;ans.s[2][2] = 1;
	return ans;
}

//打印矩阵
void output(Matrix a){
    for(int i=0;i<maxn;++i){
        for(int j=0;j<maxn;++j){
           printf("%lld ",a.s[i][j]);
        }
        puts("");
    }
} 
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
			Matrix ans;
			ans.s[0][0] = B;ans.s[0][1] = A;ans.s[0][2] = 1;
			for(ll i = 3;i <= n;i++){
				Matrix a;
				ll temp;
				if(P/i > 0)
					temp = P/(P/i);
				else temp = n;
				temp = min(temp,n); 
				a = init(C,D,P/i);
				a = pow_mod(a,temp-i+1);
				ans = ans*a;
				i = temp;
//				output(ans);
			}
			printf("%lld\n",ans.s[0][0]);
		}		
	}
	return 0;
} 
