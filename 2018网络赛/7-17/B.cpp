#include<bits/stdc++.h>
using namespace std;
typedef long double db;
const int MAXN=55;
const db PI=acos(-1.0);    //acos反函数   
struct Point
{
    db x,y;
    Point(){}
    Point(db _x,db _y):x(_x),y(_y){}
    Point operator - (const Point &t)const  //求a，b向量 注意是后面的点-前面的点 
    {
        return Point(x-t.x,y-t.y);
    }
    db operator ^ (const Point &t)const     //定义向量相乘 
    {
        return x*t.x+y*t.y;
    }
    db len()const          //求模 
    {
        return sqrt(x*x+y*y);
    }
}p[MAXN];

db ang(Point a,Point b,Point c)    
{
    db t=((b-a)^(c-a))/(b-a).len()/(c-a).len();  //求角b余弦  
    return acos(max(-1.0L,min(1.0L,t)));		//然后根据反函数 
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<=n;i++)
        {
            double x,y;
            scanf("%lf%lf",&x,&y);
            p[i]=Point(x,y);
        }
        db res=0;
        for(int i=0;i<n;i++)
            res+=(p[n]-p[i]).len()*(PI-ang(p[i],p[(i-1+n)%n],p[(i+1)%n]));
        printf("Case #%d: %.3f\n",ca,(double)res);
    }
    return 0;
}
