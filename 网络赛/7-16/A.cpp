#include <bits/stdc++.h>

using namespace std;

int a[55],b[55];

int main()
{
	string str1,str2;
	while(cin>>str1>>str2){
		int sum=0;
		for(int i = 0;i < str1.size();i++){
			a[i+1] = str1[i]-65;
			b[i+1] = str2[i]-65;
		}
		for(int i = 1;i <= str1.size();i++){
			int min_v = 100,min_p;
			for(int j = 1;j <= str1.size();j++){
				if(b[j] == -1)    //ทรฮสนý 
					continue;
				if(min_v > (b[j]+26-a[i]) % 26){   
					min_v = (b[j]+26-a[i]) % 26;
					min_p = j;
				} 
			}
			sum += min_v;
			b[min_p] = -1;
		}
		printf("%d\n",sum);
	}
	return 0;	
} 
