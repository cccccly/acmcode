#include <bits/stdc++.h>
#define maxn 100007
using namespace std;
struct Node{
	int pos;
	int num;
	bool operator < (Node const& _A)const{
		if(num < _A.num)  return true;
	}
};
priority_queue <Node> pq;
int ans[maxn][2];
int main(){
	int n;
	while(~scanf("%d",&n)){
		Node temp;
		for(int i = 1;i <= n;i++){
			scanf("%d",&temp.num);
			temp.pos = i;
			ans[i][0] = 1;
			ans[i][1] = temp.num;
			pq.push(temp);
		}
		while(!pq.empty()){
			temp = pq.top();
			pq.pop();
			int i = temp.pos;
			if(ans[i][1] < ans[i-1][1]){
				ans[i-1][0] = ans[i][0] + 1;
			}
			if(ans[i][1] < ans[i+1][1]){
				ans[i+1][0] = ans[i][0] + 1;
			}
		}
		int sum = 0;
		for(int i = 1;i <= n;i++)
			sum += ans[i][0];
		printf("%d\n",sum);
	}
	return 0;
} 
