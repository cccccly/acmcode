const int MAXM=50005;　　　　　　　　　　//定义 MAXM为线段最大长度

int a[MAXM],st[MAXM<<2];　　　　// a 数组为 main 函数中读入的内容，st 数组为需要查询的数的信息（如和、最值等），树的空间大小为线段最大长度的四倍

void build(int o,int l,int r){　　　　//传入的参数为 o:当前需要建立的结点；l：当前需要建立的左端点；r：当前需要建立的右端点
    if(l==r)st[o]=a[l];　　　　　　//当左端点等于右端点即建立叶子结点时，直接给数组信息赋值
    else{
        int m=l+((r-l)>>1);　　　　　　// m 为中间点，左儿子结点为 [l,m] ，右儿子结点为 [m+1,r]；
        build(o<<1,l,m);　　　　　　　　//构建左儿子结点
        build((o<<1)|1,m+1,r);　　　　　//构建右儿子结点
        st[o]=st[o<<1]+st[(o<<1)|1];　　//递归返回时用儿子结点更新父节点，此处可进行更新最大值、最小值、区间和等操作
    }
}
// build(1,1,n);

void update(int o,int l,int r,int ind,int ans){　　//o、l、r为当前更新到的结点、左右端点，ind为需要修改的叶子结点左端点，ans为需要修改成的值；
    if(l==r){　　　　　　　　　　　//若当前更新点的左右端点相等即到叶子结点时，直接更新信息并返回
        st[o]=ans;
        return;
    }
    int m=l+((r-l)>>1);
    if(ind<=m){　　　//若需要更新的叶子结点在当前结点的左儿子结点的范围内，则递归更新左儿子结点，否则更新右儿子结点
        update(o<<1,l,m,ind,ans);
    }
    else{
        update((o<<1)|1,m+1,r,ind,ans);
    }
    st[o]=max(st[o<<1],st[(o<<1)|1]);//递归回之后用儿子结点更新父节点（此处是区间最大值）
}
//update(1,1,n,ind,ans);　 //在main函数中的语句    

