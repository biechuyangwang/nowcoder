# [最小编辑代价](https://www.nowcoder.com/practice/05fed41805ae4394ab6607d0d745c8e4)
[题解](./main_1.cpp)

## 动归方程
```cpp
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
```

## 最小编辑代价
```cpp
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
```