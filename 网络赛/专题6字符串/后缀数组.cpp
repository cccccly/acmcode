//倍增算法求后缀数组 
//SA[i]存放排名第i大的后缀首字符下标
//rank[i]存放各个后缀的优先级
int sa[MAXN],Rank[MAXN],height[MAXN];
int wa[MAXN],wb[MAXN],wv[MAXN],Ws[MAXN];
int cmp(int *r,int a,int b,int l){
      return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(const char r[],int sa[],int n,int m){//string, sa, 字符串长度+1, 字母表大小+1
      int i,j,p,*x=wa,*y=wb,*t; 
      for(i=0; i<m; i++) Ws[i]=0;
      for(i=0; i<n; i++) Ws[x[i]=r[i]]++;//以字符在字母表中顺序为下标 
      for(i=1; i<m; i++) Ws[i]+=Ws[i-1];
      for(i=n-1; i>=0; i--) sa[--Ws[x[i]]]=i;
      /*cout<<"SA"<<endl;;
      for(int i=0;i<n+1;i++)cout<<sa[i]<<' ';*/
      for(j=1,p=1; p<n; j*=2,m=p)
      {
            for(p=0,i=n-j; i<n; i++) y[p++]=i; 
            for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
            for(i=0; i<n; i++) wv[i]=x[y[i]];
            for(i=0; i<m; i++) Ws[i]=0;
            for(i=0; i<n; i++) Ws[wv[i]]++;
            for(i=1; i<m; i++) Ws[i]+=Ws[i-1];
            for(i=n-1; i>=0; i--) sa[--Ws[wv[i]]]=y[i];
            for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
                  x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
      }
      return;
}