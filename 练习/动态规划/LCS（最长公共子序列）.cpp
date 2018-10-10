
#include <stdio.h>

#include <string.h>
#include <stdlib.h>
int LCSLength(char* str1, char* str2, int **b)
{
	int i,j,length1,length2,len;
	length1 = strlen(str1);
	length2 = strlen(str2);


	//双指针的方法申请动态二维数组
	int **c = new int*[length1+1]; //共有length1+1行
	for(i = 0; i < length1+1; i++)
		c[i] = new int[length2+1];//共有length2+1列

	for(i = 0; i < length1+1; i++)
		c[i][0]=0;        //第0列都初始化为0
	for(j = 0; j < length2+1; j++)
		c[0][j]=0;        //第0行都初始化为0

	for(i = 1; i < length1+1; i++)
	{
		for(j = 1; j < length2+1; j++)
		{
			if(str1[i-1]==str2[j-1])//由于c[][]的0行0列没有使用，c[][]的第i行元素对应str1的第i-1个元素
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=0;          //输出公共子串时的搜索方向
			}
			else if(c[i-1][j]>c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]=1;
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]=-1;
			}
		}
	}
	len=c[length1][length2];
	for(i = 0; i < length1+1; i++)    //释放动态申请的二维数组
		delete[] c[i];
	delete[] c;
	return len;
}
void PrintLCS(int **b, char *str1, int i, int j)
{
	if(i==0 || j==0)
		return ;
	if(b[i][j]==0)
	{
		PrintLCS(b, str1, i-1, j-1);//从后面开始递归，所以要先递归到子串的前面，然后从前往后开始输出子串
		printf("%c",str1[i-1]);//c[][]的第i行元素对应str1的第i-1个元素
	}
	else if(b[i][j]==1)

		PrintLCS(b, str1, i-1, j);
	else
		PrintLCS(b, str1, i, j-1);
}
int main(void)
{
	char str1[100],str2[100];
	int i,length1,length2,len;
	printf("请输入第一个字符串：");
	gets(str1);
	printf("请输入第二个字符串：");
	gets(str2);
	length1 = strlen(str1);
	length2 = strlen(str2);
	//双指针的方法申请动态二维数组
	int **b = new int*[length1+1];
	for(i= 0; i < length1+1; i++)
		b[i] = new int[length2+1];
	len=LCSLength(str1,str2,b);
	printf("最长公共子序列的长度为：%d\n",len);
	printf("最长公共子序列为：");
	PrintLCS(b,str1,length1,length2);
	printf("\n");
	for(i = 0; i < length1+1; i++)//释放动态申请的二维数组
		delete[] b[i];
	delete[] b;
	system("pause");
	return 0;
}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int max1(int m,int n)
{
	if(m>n)
		return m;
	else
		return n;
}
int max2(int x,int y,int z,int k,int m,int n)
{
	int max=-1;
	if(x>max)
		max=x;
	if(y>max)
		max=y;
	if(z>max)
		max=z;
	if(k>max)
		max=k;
	if(m>max)
		max=m;
	if(n>max)
		max=n;
	return max;
}
int LCSLength(char* str1, char* str2, char* str3) //求得三个字符串的最大公共子序列长度并输出公共子序列
{
	int i,j,k,length1,length2,length3,len;
	length1 = strlen(str1);
	length2 = strlen(str2);
	length3 = strlen(str3);
	//申请动态三维数组
	int ***c = new int**[length1+1];      //共有length1+1行
	for(i = 0; i < length1+1; i++)
	{
		c[i] = new int*[length2+1];      //共有length2+1列
		for(j = 0; j<length2+1; j++)
			c[i][j] = new int[length3+1];
	}
	for(i = 0; i < length1+1; i++)
	{
		for(j = 0; j < length2+1; j++)
			c[i][j][0]=0;
	}
	for(i = 0; i < length2+1; i++)
	{
		for(j = 0; j < length3+1; j++)
			c[0][i][j]=0;
	}
	for(i = 0; i < length1+1; i++)
	{
		for(j = 0; j < length3+1; j++)
			c[i][0][j]=0;
	}
	for(i = 1; i < length1+1; i++)
	{
		for(j = 1; j < length2+1; j++)
		{
			for(k = 1; k < length3+1; k++)
			{
				if(str1[i-1]==str2[j-1] && str2[j-1]==str3[k-1])
					c[i][j][k]=c[i-1][j-1][k-1]+1;
				else if(str1[i-1]==str2[j-1] && str1[i-1]!=str3[k-1])
					c[i][j][k]=max1(c[i][j][k-1],c[i-1][j-1][k]);
				else if(str1[i-1]==str3[k-1] && str1[i-1]!=str2[j-1])
					c[i][j][k]=max1(c[i][j-1][k],c[i-1][j][k-1]);
				else if(str2[j-1]==str3[k-1] && str1[i-1]!=str2[j-1])
					c[i][j][k]=max1(c[i-1][j][k],c[i][j-1][k-1]);
				else
				{
					c[i][j][k]=max2(c[i-1][j][k],c[i][j-1][k],c[i][j][k-1],c[i-1][j-1][k],c[i-1][j][k-1],c[i][j-1][k-1]);
				}
			}
		}
	}
	len=c[length1][length2][length3];
	for(i = 1; i < length1+1; i++) //释放动态申请的三维数组
	{
		for(j = 1; j < length2+1; j++)
			delete[] c[i][j];
		delete[] c[i];
	}
	delete[] c;
	return len;
}
int main(void)
{
	char str1[100],str2[100],str3[100];
	int len;
	printf("请输入第一个字符串：");
	gets(str1);
	printf("请输入第二个字符串：");
	gets(str2);
	printf("请输入第三个字符串：");
	gets(str3);
	len=LCSLength(str1,str2,str3);
	printf("最长公共子序列的长度为：%d\n",len);
	system("pause");
	return 0;
}

