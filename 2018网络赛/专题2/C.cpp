#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,cnt = 1;
	while(cin>>t){
		queue <int> q[1003];  //��¼�����ڳ��ֵĴ��� 
		queue <int> Q;        //��¼ÿ�������г��ֵĴ��� 
		map <int ,int> mp;    //����ӳ�䣬ÿ��Ԫ�����ڵڼ���team queue
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
				int num = mp[opNum];  //�õ�opNum��Ӧ��ԭʼ���б�� 
				if(q[num].empty())    //��Ӧ�ı��Ϊ��  ��˵����һ�γ������������� ����Q 
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
		puts("");    //�ж�������û���� 
	}
	return 0; 
} 
