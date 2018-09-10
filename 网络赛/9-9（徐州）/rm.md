#[ACM-ICPC 2018 徐州赛区网络预赛](https://nanti.jisuanke.com/?page=1&sort=id&kw=%E5%BE%90%E5%B7%9E&tags=) 9月9日

> ## F Features Track
> ## 题意：在计算机视觉中，对于一个物体来说，如果它的特征在不同帧处在同一个位置（坐标相同），就能说是“特征移动”。要找出最长的“特征移动”。
> ## 思路：简单的map应用，边读入数据边处理，因为特征都是用<x,y>表示，所以用一个node存<x,y>，再定义这个node的小于号以便于map插入。
> ## tip 
> - 同一帧输入的时候可能有多个相同点
> - 如果最长长度为1也就是不连续，要输出0

　
> ## H Ryuji doesn't want to study
> ## 题意：求区间合，但是根据一个公式区间[l,r]的区间和为，a[l]*L+a[l+1]*(L-1)+...+a[r] (L = r-l+1) 
> ## 思路：用树状数组维护两个区间和，a[i]和a[i]*(n-i+1)这样答案就是 `sum(bit2,r)-sum(bit2,l-1)-(n-r)*(sum(bit1,r)-sum(bit1,l-1))`
> ## tip 

> - 后补的题，当时卡了3个多小时