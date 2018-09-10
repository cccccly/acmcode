#include<bits/stdc++.h>

using namespace std;
struct line{
	int s;
	int f;
}l[100005];

bool cmp(const line &a,const line &b)
{
	if(a.f-a.s == b.f-b.s)
		return a.s<b.s;
	else
    	return a.f-a.s > b.f-b.s;
}
int main(){
	int s,f;
	int cnt = 0;
	while(~scanf("%d,%d",&l[cnt].s,&l[cnt].f)){
		if(l[cnt].s == 0&&l[cnt].f == 0)
			break;
		cnt++;
	}
	sort(l,l+cnt,cmp);
	bool a[30];
	memset(a,0,sizeof(a));
	for(int i = 0;i < cnt;i++){
		int flag = 1;
		for(int j = l[i].s;j <= l[i].f;j++){
			if(!a[j])
				a[j] = 1;
			else{
				flag = 0;
				for(int k = l[i].s;k < j;k++)
					a[j] = 0;
			}
		}
		if(flag){
			printf("%d,%d\n",l[i].s,l[i].f);
		}
	}
	return 0;
} 
