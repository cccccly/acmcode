#include <bits/stdc++.h>

using namespace std;
const double pi = 3.1415926;


int main(){
	long long r;
	while(~scanf("%lld",&r)){
		double a = pi*1.0*r*r;
		printf("%.6lf\n",a);
		a = 2*r*r;
		printf("%.6lf\n",a);
	}	
	return 0;
} 
