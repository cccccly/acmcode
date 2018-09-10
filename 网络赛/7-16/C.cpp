#include <bits/stdc++.h>

using namespace std;


int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		if(n == 1){
			int temp;
			scanf("%d",&temp);
			printf("0\n");
		}
		else{
			long long sum = 0,min,temp;
			scanf("%lld",&min);
			sum += min;
			for(int i = 2;i <= n;i++){
				scanf("%d",&temp);
				sum += temp;
				if(temp < min)
					min = temp;
			}
			sum += (n-2)*min;
			printf("%lld\n",sum);
		}
	}
	return 0;	
} 
