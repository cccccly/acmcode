#include <bits/stdc++.h>

using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 1000010

int a[MAXN];    //ai ��ʾɾ��i�������ٵĺ������� 

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n,temp;
		int min1=MAXN,min2=MAXN; //��С�ʹ�С
		memset(a , 0 ,sizeof(a)); 
		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
			scanf("%d",&temp);
			if(temp < min1){    //���õ���
				min2 = min1;
				min1 = temp;
				a[temp] = 0;  
			}
			else if(temp < min2){  //�������ǿ��ܻ��ɲ��õ��� 
				min2 = temp;
				a[temp] = 1;      //����ɾ���Լ�������-- 
				a[min1]++;        
			}
			else a[temp] = 1;     //������Ӱ��������  ֻ����good����-- 
		}
		int ans = 0;
//		for(int i = 1;i <= n;i++){
//			printf("%d ",a[i]);
//		}
	/*��Ȼ����ѡɾ�����õ�����Ӱ��Ϊ0�� ���û�� ��ô����һ����С��Ӱ��Ϊ1����*/
		for(int i = 1;i <= n;i++){
			if(a[i] == 0){
				ans = i;
				break;
			}
		}
		if(!ans){
			for(int i = 1;i <= n;i++){
				if(a[i] == 1){
					ans = i;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;	
} 
