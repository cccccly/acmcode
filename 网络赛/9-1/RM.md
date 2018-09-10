# 2018年9月1日 
> ## <a href="https://nanti.jisuanke.com/?page=1&sort=id&kw=%E5%8D%97%E4%BA%AC&tags=">ACM-ICPC 2018 南京赛区网络预赛</a>

　
> ## Problem A - An Olympian Math Problem

> ### 题意：S=1×1!+2×2!+⋯+(n-1)×(n−1)! 给定n，求S%n。       

> ### 思路：
- 1+S(n)=1+1×1!+2×2!+⋯+(n−1)×(n−1)!
- =2×1!+2×2!+⋯+(n−1)×(n−1)!
- =2!+2×2!+⋯+(n−1)×(n−1)!
- =3×2!+⋯+(n−1)×(n−1)!
- =3!+3×3!+⋯+(n−1)×(n−1)!
- =4×3!+⋯+(n−1)×(n−1)!
- =⋯=(n−1)!+(n−1)×(n−1)!=n×(n−1)!=n!
- 即最后输出n-1 注意数据范围要开ll。

　
> ## Problem L - Magical Girl Haze
> ### 题意：N个城市，M条路（有向图）,问最多可以让K条路免费（权值为0），求1号城市-N号城市的最短路径
> ### 思路：dji 将dist[i]转化成dp[i][j]，多一维J表示当前用了几次免费的路。
 
　
> ## Problem J - Sum
> ### 题意：f（n）表示将n转化为没有平方因子a，b，且n=a*b，问有多少种分法，且6=1*6=6*1算两种 4=2*2算一种。最后输出前缀和。
> ### 思路：线性筛，首先每个素数的ans=2，筛i*prime[j]显然分三种情况。1：i%prime[j]!=0,说明ans[i*prime[j]] = ans[i]*prime[j],显然成立。2：i%prime[j]==0但是i中只含有prime[j]De 