#include<bits/stdc++.h>
using namespace std;

struct cmp
{
    bool operator()(pair<int,int> &a, pair<int,int> &b) const
    {
    	if(a.first!=b.first)
        	return a.first > b.first;
        else return a.second < b.second;
    }
};

priority_queue<pair<int,int>,vector<pair<int,int> >,cmp > q;
map <int ,int> mp;


int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
    	while(!q.empty())
    		q.pop();
    	mp.clear();
    	long long ans=0,cnt = 0;
    	int x;
    	int n;
    	scanf("%d",&n);
	    for (int i=0;i<n;i++)
	    {
	        scanf("%d",&x);
	        if(q.empty())
	        {
	        	pair <int ,int> x1(x,0);
	            q.push(x1);
	            continue;
	        }
	        if(x<=q.top().first){
	        	pair <int ,int> x1(x,0);
	        	q.push(x1);
			}
	        else
	        {	
	            ans+=(x-q.top().first);
	            if(q.top().second == 1)
	            	cnt-=2;
	            cnt+=2;
	            pair<int ,int>x1(x,1);
	            q.pop();
	            q.push(x1);
	            pair<int ,int>x2(x,0);
	            q.push(x2);
	        }
	    }
	    printf("%I64d %I64d\n",ans,cnt);
	}
    
    return 0;
}
