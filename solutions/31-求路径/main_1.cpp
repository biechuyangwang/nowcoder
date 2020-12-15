/*
* author： 李俊
* time：2020/12/14
*
* 求路径
*/

/*
* 注意事项
*/

/*
* 其实是求方案数
* dp[i][0] = 1
* dp[0][j] = 1
* dp[i][j] = dp[i-1][j] + dp[i][j-1]
* 注：初始化和动归状态转移分离，可以避免一些逻辑问题
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param m int整型 
     * @param n int整型 
     * @return int整型
     */
    int uniquePaths(int m, int n) {
        // write code here
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;++i){
        	dp[i][0] = 1;
        	for(int j=0;j<n;++j){
        		dp[0][j] = 1;
			}
		}
        for(int i=1;i<=m;++i){
        	for(int j=1;j<=n;++j){
        		dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
		return dp[m-1][n-1];
    }
};

int main(){
	vector<int>input = {2,2};
	
	Solution ss;
    auto res = ss.uniquePaths(input[0],input[1]);

    cout << res;

	cout << endl;
	return 0;
}

/*
* output 1:
* 2
*/