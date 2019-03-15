
#include <stdio.h>

#include <string.h>
#include <stdlib.h>
int LCSLength(char* str1, char* str2, int **b)
{
	int i,j,length1,length2,len;
	length1 = strlen(str1);
	length2 = strlen(str2);


	//˫ָ��ķ������붯̬��ά����
	int **c = new int*[length1+1]; //����length1+1��
	for(i = 0; i < length1+1; i++)
		c[i] = new int[length2+1];//����length2+1��

	for(i = 0; i < length1+1; i++)
		c[i][0]=0;        //��0�ж���ʼ��Ϊ0
	for(j = 0; j < length2+1; j++)
		c[0][j]=0;        //��0�ж���ʼ��Ϊ0

	for(i = 1; i < length1+1; i++)
	{
		for(j = 1; j < length2+1; j++)
		{
			if(str1[i-1]==str2[j-1])//����c[][]��0��0��û��ʹ�ã�c[][]�ĵ�i��Ԫ�ض�Ӧstr1�ĵ�i-1��Ԫ��
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=0;          //��������Ӵ�ʱ����������
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
	for(i = 0; i < length1+1; i++)    //�ͷŶ�̬����Ķ�ά����
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
		PrintLCS(b, str1, i-1, j-1);//�Ӻ��濪ʼ�ݹ飬����Ҫ�ȵݹ鵽�Ӵ���ǰ�棬Ȼ���ǰ����ʼ����Ӵ�
		printf("%c",str1[i-1]);//c[][]�ĵ�i��Ԫ�ض�Ӧstr1�ĵ�i-1��Ԫ��
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
	printf("�������һ���ַ�����");
	gets(str1);
	printf("������ڶ����ַ�����");
	gets(str2);
	length1 = strlen(str1);
	length2 = strlen(str2);
	//˫ָ��ķ������붯̬��ά����
	int **b = new int*[length1+1];
	for(i= 0; i < length1+1; i++)
		b[i] = new int[length2+1];
	len=LCSLength(str1,str2,b);
	printf("����������еĳ���Ϊ��%d\n",len);
	printf("�����������Ϊ��");
	PrintLCS(b,str1,length1,length2);
	printf("\n");
	for(i = 0; i < length1+1; i++)//�ͷŶ�̬����Ķ�ά����
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
int LCSLength(char* str1, char* str2, char* str3) //��������ַ�������󹫹������г��Ȳ��������������
{
	int i,j,k,length1,length2,length3,len;
	length1 = strlen(str1);
	length2 = strlen(str2);
	length3 = strlen(str3);
	//���붯̬��ά����
	int ***c = new int**[length1+1];      //����length1+1��
	for(i = 0; i < length1+1; i++)
	{
		c[i] = new int*[length2+1];      //����length2+1��
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
	for(i = 1; i < length1+1; i++) //�ͷŶ�̬�������ά����
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
	printf("�������һ���ַ�����");
	gets(str1);
	printf("������ڶ����ַ�����");
	gets(str2);
	printf("������������ַ�����");
	gets(str3);
	len=LCSLength(str1,str2,str3);
	printf("����������еĳ���Ϊ��%d\n",len);
	system("pause");
	return 0;
}

