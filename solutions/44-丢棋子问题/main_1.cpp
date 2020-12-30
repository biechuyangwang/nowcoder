/*
* author： 李俊
* time：2020/12/18
*
* 丢棋子
*/

/*
* 注意事项
*/

/*
* dp[i][j]表示i个棋子扔j次，可以判断的楼层。
* dp[1][j] = j
* dp[i][1] = 1
* dp[i][j] = dp[i][j-1] + dp[i-1][j-1] + 1
* 如果第一次扔碎了，那么还有i-1个棋子可以扔j-1次；
* 如果第一次没碎，还有i个棋子可以扔j-1次；
* 所以能确定的层数是两者的和加上当前层。
* 优化：
* 根据动归方程，可以发现，当前状态只与两个状态有关，可以降低维度解决空间。
* 
* 如果内外遍历都一样，选择小的作为内层。
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回最差情况下扔棋子的最小次数
     * @param n int整型 楼层数
     * @param k int整型 棋子数
     * @return int整型
     */
	int solve(int n, int k) {
	    // write code here
	    int maxn=0, times=1;
	    vector<int>pre(k+1);
	    vector<int>cur(k+1);
	    while(maxn<n){
	        for(int i=1;i<=k;++i){
	            if(times==1) cur[i]=1;  // 扔1次，无论如何只能确定1层 
	            else if(i==1) cur[i]=times;  // 1个棋子，扔i次能确定i层
	            else cur[i]=pre[i-1]+pre[i]+1; 
	        }
	        maxn = cur.back();
	        pre = cur;
	        times++;
	    }
	    return times-1;
	}
};

int main(){
	int input = 105;
	int val=2;
	Solution ss;
    auto res = ss.solve(input,val);
    cout << res;
	return 0;
}

/*
* output 1:
* 14
*/