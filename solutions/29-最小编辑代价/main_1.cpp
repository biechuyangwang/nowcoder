/*
* author： 李俊
* time：2020/12/13
*
* 最小编辑代价
*/

/*
* 注意事项
*/

/*
* dp[i][j]表述str1的前i个字符转化成str2的前j个字符需要的最小代价。
* 
* // 初始化
* m = str1.size()
* n = str2.size()
* 
* for i <- 1:m
* dp[i][0] = i*dc
* for j <- 1:n
* dp[0][j] = j*ic
* 
* // 动归
* for i <- 1:m
* 	for j <- 1:n
*		dp[i][j] = min(dp[i][j-1]+ic, dp[i-1][j]+dc, dp[i-1][j-1]+rc)
*
* return dp[m][n]
*
* // 其实初始化和运算可以放在一起进行
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * min edit cost
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @param ic int整型 insert cost
     * @param dc int整型 delete cost
     * @param rc int整型 replace cost
     * @return int整型
     */
    int minEditCost(string str1, string str2, int ic, int dc, int rc) {
        // write code here
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;++i){
        	dp[i][0] = i*dc;
        	for(int j=1;j<=n;++j){
        		dp[0][j] = j*ic;
        		if(str1[i-1]==str2[j-1])
        			dp[i][j] = dp[i-1][j-1];
        		else{
        			dp[i][j] = min(min(dp[i][j-1]+ic,dp[i-1][j]+dc),dp[i-1][j-1]+rc);
				}
			}
		}
		return dp[m][n];
    }
};

int main(){
	string str1 = "abc";
	string str2 = "adc";
	vector<int>input = {5,3,100};



	Solution ss;
    auto res = ss.minEditCost(str1,str2,input[0],input[1],input[2]);    
    cout << res;
	cout << endl;
	return 0;
}

/*
* output 1:
* 8
*/