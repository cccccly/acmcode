#include <bits/stdc++.h>

using namespace std;
//��float ����ԭʼ��  ����ȡ 

stack <double> fst;
stack <char> op1;
queue <double> fq;
queue <char> op2;
int main()
{
	string s;
	while(getline(cin,s)){
		if(s.size() == 1&&s[0] == '0')
			break;
		for(int i = s.size()-1;i >= 0;i--){   //����fst,op1�ֱ�洢���ֺͲ����� 
			if(s[i] <= '9'&&s[i] >= '0'){
				double cnt = 1,num=0;
				while(s[i] >= '0' && s[i] <= '9' &&i>=0){
					num += (s[i]-'0')*cnt;
					cnt*=10,i--;
				}
				fst.push(num);i++;
			}
			else if(s[i] != ' ')
				op1.push(s[i]);
		}
		
//		while(!op1.empty()){
//			printf("%c ",op1.top());
//			op1.pop();
//		}
		
		while(!op1.empty()){
			char c = op1.top();op1.pop();
			double a = fst.top();fst.pop();
			if(c == '+' || c == '-'){
				op2.push(c);
				fq.push(a);
			}
			else if(c == '*'){
				double b = fst.top();
				fst.pop();
				fst.push(a*b);
			}
			else if(c == '/'){
				double b = fst.top();
				fst.pop();
				fst.push(a/b);
			}
		} 
		if(!fst.empty()){
			fq.push(fst.top());
			fst.pop();
		}
			
		double sum = fq.front();
		fq.pop();
		while(!op2.empty()){
			char c = op2.front();
			op2.pop();
			double a = fq.front();
			fq.pop();
			if(c == '+'){
				sum += a;
			}
			else{
				sum -= a;
			}
		}
		printf("%.2llf\n",sum);
	} 
	return 0;
}


