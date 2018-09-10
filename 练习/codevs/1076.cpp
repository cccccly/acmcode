#include <bits/stdc++.h>

using namespace std;

int a[100000+5];
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}	
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
