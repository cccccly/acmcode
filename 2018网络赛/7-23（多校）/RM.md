# 2018年7月23日 
> ## <a href="http://acm.hdu.edu.cn/contests/contest_show.php?cid=802"> 2018 Multi-University Training Contest 1</a>

　
题目在6298-6308
账号 team0725
密码 424690
> ## Problem 1004 — Distinct Values

> ### 题意：求n个整数的一个序列。给了m个条件，每个条件的格式为两个整数l，r表示在下标l到r中所有元素不相等，最后满足m个条件后还需要这个序列和最小。       

> ### 思路：首先预处理，有些小区间被全部包含那么是没有意义的，去重。根据样例发现最小能放的数是1,思路为使用pq，先将1-n压入pq中，不断使用当前能用的最小值，同时前面可用的值又加入队列中。

　
