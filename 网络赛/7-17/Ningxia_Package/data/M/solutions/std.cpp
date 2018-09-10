#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;

const db PI=acos(-1.0);
struct Complex
{
    db x,y;
    Complex(db _x=0,db _y=0):x(_x),y(_y){}
    Complex operator + (const Complex &t)const
    {
        return Complex(x+t.x,y+t.y);
    }
    Complex operator - (const Complex &t)const
    {
        return Complex(x-t.x,y-t.y);
    }
    Complex operator * (const Complex &t)const
    {
        return Complex(x*t.x-y*t.y,x*t.y+y*t.x);
    }
    Complex operator / (const db &t)const
    {
        return Complex(x/t,y/t);
    }
    Complex conj()const
    {
        return Complex(x,-y);
    }
};

namespace FFT
{
const int MAXN=1<<18;
void change(Complex y[],int len)
{
    for(int i=1,j=len/2;i<len-1;i++)
    {
        if(i<j)swap(y[i],y[j]);
        int k=len/2;
        while(j>=k)j-=k,k/=2;
        if(j<k)j+=k;
    }
}
Complex pmr[MAXN+1];
void init()
{
    for(int i=0;i<=MAXN;i++)
        pmr[i]=Complex(cos(2*PI*i/MAXN),sin(2*PI*i/MAXN));
}
void fft(Complex a[],int len,int on)
{
    change(a,len);
    for(int h=2;h<=len;h<<=1)
        for(int j=0,s=MAXN/h;j<len;j+=h)
            for(int k=j,t=0;k<j+h/2;k++,t+=s)
            {
                Complex w=pmr[(on>0 ? t : MAXN-t)];
                Complex u=a[k],v=w*a[k+h/2];
                a[k]=u+v,a[k+h/2]=u-v;
            }
    if(on==-1)for(int i=0;i<len;i++)
        a[i]=a[i]/len;
}
Complex p[MAXN+1];
void double_fft(Complex a[],Complex b[],int len,int on)
{
    for(int i=0;i<len;i++)
        p[i]=a[i]+b[i]*Complex(0,1);
    fft(p,len,on);
    p[len]=p[0];
    if(on==1)for(int i=0;i<len;i++)
    {
        a[i]=(p[i]+p[len-i].conj())/2;
        b[i]=(p[i]-p[len-i].conj())*Complex(0,-0.5);
    }
    else for(int i=0;i<len;i++)
        a[i]=p[i].x,b[i]=p[i].y;
}
}

const int MAXN=60005;
const int MAXL=1<<18;

ll Mod,Sqt;

Complex p[3][MAXL],q[2][MAXL];
void poly_mul(ll f[],ll g[],int len)
{
    for(int i=0;i<len;i++)
    {
        p[0][i]=f[i]/Sqt,p[1][i]=f[i]%Sqt;
        q[0][i]=g[i]/Sqt,q[1][i]=g[i]%Sqt;
    }
    for(int i=0;i<2;i++)
        FFT::double_fft(p[i],q[i],len,1);
    for(int i=0;i<len;i++)
    {
        p[2][i]=p[0][i]*q[1][i]+p[1][i]*q[0][i];
        p[0][i]=p[0][i]*q[0][i],p[1][i]=p[1][i]*q[1][i];
    }
    FFT::double_fft(p[0],p[1],len,-1);
    FFT::fft(p[2],len,-1);
    for(int i=0;i<len;i++)
    {
        ll tmp[3];
        for(int j=0;j<3;j++)
            tmp[j]=(ll)(p[j][i].x+0.5)%Mod;
        f[i]=(tmp[0]*Sqt*Sqt+tmp[1]+tmp[2]*Sqt)%Mod;
    }
}

ll fast_pow(ll a,ll k)
{
    if(k<0)a=fast_pow(a,Mod-2),k=-k;
    ll res=1;
    while(k)
    {
        if(k&1)res=res*a%Mod;
        a=a*a%Mod;
        k>>=1;
    }
    return res;
}

bool np[MAXN*2];
int pri[MAXN*2];
ll pw[MAXN*2];
void sieve(int n,int p)
{
    pw[0]=0,pw[1]=1;
    for(int i=2;i<=n;i++)np[i]=0;
    int tot=0;
    for(int i=2;i<=n;i++)
    {
        if(!np[i])
        {
            pri[tot++]=i;
            pw[i]=fast_pow(i,p);
        }
        for(int j=0;j<tot;j++)
        {
            if(i*pri[j]>n)break;
            np[i*pri[j]]=1;
            pw[i*pri[j]]=pw[i]*pw[pri[j]]%Mod;
        }
    }
}

ll poly_f[MAXL],poly_g[MAXL];

ll Fac[MAXN*2],Inv[MAXN*2],Sti[MAXN];
void get_stirling(int n)
{
    int len=1;
    while(len<=2*n)len<<=1;
    sieve(n,n);
    for(int i=0;i<len;i++)
    {
        poly_f[i]=(i<=n ? (i&1 ? Mod-1 : 1)*Inv[i]%Mod : 0);
        poly_g[i]=(i<=n ? pw[i]*Inv[i]%Mod : 0);
    }
    poly_mul(poly_f,poly_g,len);
    for(int i=0;i<=n;i++)
        Sti[i]=poly_f[i];
}
ll Col[MAXN*2];
void get_coloring(int n,int m)
{
    int len=1;
    while(len<=2*n+m)len<<=1;
    sieve(n+m,m);
    for(int i=0;i<len;i++)
    {
        poly_f[i]=(i<=n ? Sti[i] : 0);
        poly_g[i]=(i<=n+m ? pw[i]*Inv[i]%Mod : 0);
    }
    poly_mul(poly_f,poly_g,len);
    for(int i=0;i<=n+m;i++)
        Col[i]=poly_f[i]*Fac[i]%Mod;
}
ll get_sample(int n)
{
    ll res=0;
    for(int i=0;i<=n;i++)
    {
        ll cof=Fac[n+1]*Inv[i+1]%Mod*Inv[n-i]%Mod;
        if(~i&1)res=(res+Col[i]*cof)%Mod;
        else res=(res-Col[i]*cof%Mod+Mod)%Mod;
    }
    return res;
}

ll solve(int n,int m)
{
    for(int i=(Fac[0]=1);i<=n+m+1;i++)
        Fac[i]=i*Fac[i-1]%Mod;
    Inv[n+m+1]=fast_pow(Fac[n+m+1],-1);
    for(int i=n+m;i>=0;i--)
        Inv[i]=(i+1)*Inv[i+1]%Mod;
    get_stirling(n);
    get_coloring(n,m);
    return get_sample(n+m)*fast_pow(Mod-1,n+m)%Mod;
}

int main()
{
    FFT::init();
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        int n,m;
        scanf("%d%d%lld",&n,&m,&Mod);
        Sqt=sqrt(Mod);
        printf("Case #%d: %lld\n",ca,solve(n,m));
    }
    return 0;
}
