#include <stdio.h>
#include <algorithm>
#include<cctype>

using namespace std;

#define maxn 5000005
int a[maxn],n;
inline int read()
{
    int X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}


void judge(){
	int x,y,flag;
//	for(int i = 0;i < n-2;i++){
//		for(int j = i+1;j < n-1;j++){
//			if(a[j] <= a[n-1]-a[i] || a[j] >= a[n-1] + a[i])
//				break;
//			x = a[j] - a[i] - 1;
//			y = a[i] + a[j] + 1;
//			flag = upper_bound(a+j+1,a+n,x) - a;
//			if(flag != n && a[flag] <= y){
//				puts("YES");
//				return ;
//			}
//		}
//	}
	for(int i = 0;i < n-2;i++){
		if(a[i] + a[i+1] > a[i+2]){
			puts("YES");
			return ;
		}
	}
	puts("NO");
	return ;
}

int main(){
	while(~scanf("%d",&n)){
		for(int i = 0;i < n;i++)
			scanf("%d",&a[i]);
		if(n < 3){
			puts("NO");
			continue;
		}
		//sort(a,a+n);
		judge();
	}
	return 0;
}
