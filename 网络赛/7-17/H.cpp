#include <bits/stdc++.h>

using namespace std;
#define MAXN 100000+3
#define ll long long
struct mon{
	int hp;
	int atk;
};
map <float , mon> mp;

int main(){
	int T;
	scanf("%d",&T);
	for(int j = 1;j <= T;j++){
		int n,hp,atk;
		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
			scanf("%d%d",&hp,&atk);
			hp = ceil(sqrt(2*hp+0.25)-0.5);   //�������Ҫ��Ĵ���
			mon m;
			m.atk = atk;
			m.hp = hp;
			float temp;
			temp = hp*1.0/atk;
			   //�����ȼ����˵������ĸ��������ںϳ�һ���� 
			while(mp.count(temp)){
				temp +=0.00001;
			}
			mp[temp].hp = hp;
			mp[temp].atk = atk;
		}
		map<float , mon>::iterator iter; 
		ll sum=0,i=0;
		for(iter = mp.begin();iter != mp.end();iter++){
			i += iter->second.hp;
			sum += (ll)i*iter->second.atk;
		} 	
		mp.clear();
		printf("Case #%d: %lld\n",j,sum);	
	}
	return 0;
} 
