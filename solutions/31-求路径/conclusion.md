# [求路径](https://www.nowcoder.com/practice/166eaff8439d4cd898e3ba933fbc6358)
[题解](./main_1.cpp)

求方案数

## 动归方程
```cpp
/*
* 其实是求方案数
* dp[i][0] = 1
* dp[0][j] = 1
* dp[i][j] = dp[i-1][j] + dp[i][j-1]
* 注：初始化和动归状态转移分离，可以避免一些逻辑问题
*/
```

## 路径
```cpp
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
```