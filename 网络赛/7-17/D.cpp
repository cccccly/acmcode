#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	for(int j = 1;j <= T;j++){
		int n,m;
		scanf("%d%d",&n,&m);
		printf("Case #%d: ",j);
		double y,z;
		if(n == 1){
			printf("1.000000 ");
		}
		else{
			printf("0.500000 ");
		}
		if(m == 1){
			printf("1.000000\n");
		}
		else{
			z = (m+1)*1.0/2/m;
			printf("%.6f\n",z);
		}
	}
	return 0;
} 
