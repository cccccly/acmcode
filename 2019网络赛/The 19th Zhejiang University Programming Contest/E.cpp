#include <stdio.h>

#define ll long long

using namespace std;
int T,n;
ll a[110],b[110];
int main(){

	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		bool flag = 1;
		for(int i = 0;i < n;i++){
			scanf("%d",&a[i]);
		}
		for(int i = 0;i < n;i++){
			scanf("%d",&b[i]);
		}
		ll left = 0;
		for(int i = n-1;i >= 0;i--){
			if(a[i] <= b[i]){
				left += b[i] - a[i];
			}
			else if(a[i] <= b[i] + left){
				left -= a[i] - b[i];
			}
			else{
				flag = 0;
				break;
			}
		}
		if(flag)
			puts("Yes");
		else puts("No");
	}
	return 0;
}
