#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a,b,c;
	while(~scanf("%d%d%d",&a,&b,&c)){
		if(a%2 == 0 || b%2 == 0|| c%2 == 0)
			puts("Yes");
		else puts("No");
	}
	return 0;
}
