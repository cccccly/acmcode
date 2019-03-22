#include<bits/stdc++.h>
using namespace std;
typedef __int64 LL;

multiset<int> sk;
map <int ,int> mp;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
    	sk.clear();
    	mp.clear();
    	int n;
    	LL ans = 0;
    	int cnt = 0;
    	scanf("%d",&n);
    	for(int i=0; i<n; i++)
	    {
	        int x;
	        scanf("%d",&x);
	        if(!sk.empty()&&*sk.begin()<x)
	        {
	            ans+=x-*sk.begin();
	            if(mp.count(x)){
	        		if(mp[x] >= 0)
	        			cnt++;
	        		else cnt--;
	        		mp[x]++;
				}
				else {
					mp[x] = 1;
					cnt++;
				}
				if(mp.count(*sk.begin())){
	        		if(mp[*sk.begin()] <= 0)
	        			cnt++;
	        		else cnt--;
	        		mp[*sk.begin()]--;
				}
				else {
					mp[*sk.begin()] = -1;
					cnt++;
				}
	            sk.erase(sk.begin());
	            sk.insert(x);
	            sk.insert(x);
	        }
	        else{
	        	sk.insert(x);
	        	
			}
	            
	    }
	    printf("%d %d\n",ans,cnt);
	}
    
    return 0;
}

