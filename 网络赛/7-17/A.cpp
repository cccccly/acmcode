#include <bits/stdc++.h>
 
using namespace std;
#define LL long long 
int n, p, q, m;
unsigned int SA, SB, SC;
stack <int> st;
stack <int> mx;
unsigned int rng61(){
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}
LL gen(){
	LL res = 0;
	while(!st.empty()){
		st.pop();
	}
	while(!mx.empty()){
		mx.pop();
	}
    scanf("%d%d%d%d%u%u%u", &n, &p, &q, &m, &SA, &SB, &SC);
    for(int i = 1; i <= n; i++){
        if(rng61() % (p + q) < p){
        	int temp = rng61() % m + 1;
        	if(st.empty()){
        		st.push(temp);
        		mx.push(temp);
			}
			else{
				st.push(temp);
				if(mx.top() >= temp){
					mx.push(mx.top());
				}
				else{
					mx.push(temp);
				}
			}
			res ^= 1LL*mx.top()*i;
		}
        else{
        	if(st.empty()){
        		res ^= 0;
			}
			else{
				st.pop();
        		mx.pop();
        		if(st.empty()){
        			res ^= 0;
				}
				else{
					res ^= 1LL*mx.top()*i;
				}
			}
		}
	}
	return res;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int j = 1;j <= T;j++){
		LL res = gen();
		printf("Case #%d: %lld\n",j,res);
	}
	return 0;
}
