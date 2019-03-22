#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,cnt = 1;
	while(cin>>t){
		queue <int> q[1003];  //记录队列内出现的次序 
		queue <int> Q;        //记录每个队列中出现的次序 
		map <int ,int> mp;    //建立映射，每个元素属于第几个team queue
		if(t == 0)
			break;
		printf("Scenario #%d\n",cnt++);
		for(int i = 1;i <= t;i++){
			int num,temp;
			scanf("%d",&num);
			while(num--){
				scanf("%d",&temp);
				mp[temp] = i; 
			}
		}
		string op;
		
		while(cin>>op){
			int opNum;
			if(op[0] == 'E'){
				scanf("%d",&opNum);
				int num = mp[opNum];  //拿到opNum对应的原始队列标号 
				if(q[num].empty())    //对应的标号为空  则说明第一次出现这个标号序列 加入Q 
					Q.push(num);
				q[num].push(opNum);  
			}else if(op[0] == 'D'){
				int num = Q.front();
				printf("%d\n",q[num].front());
				q[num].pop();
				if(q[num].empty())
					Q.pop();
			}else {
				break;
			}
		}
		puts("");    //有毒。。。没读题 
	}
	return 0; 
} 
