# [矩阵的最小路径和](https://www.nowcoder.com/practice/7d21b6be4c6b429bb92d219341c4f8bb)
[题解](./main_1.cpp)

## 动归方程
```cpp
/*
* // 初始化
* m = a.size()
* n = a[0].size()
* 
* for i <- 1:m
* dp[i][0] += dp[i-1][0]
* for j <- 1:n
* dp[0][j] += dp[0][j-1]
* 
* // 动归
* for i <- 1:m
* 	for j <- 1:n
*		dp[i][j] = max(dp[i-1][j],dp[i][j-1])+a[i][j]
*
* return dp[m][n]
*
* // 其实初始化和运算可以放在一起进行
*/
```

## 最小路径和
```cpp
int minPathSum(vector<vector<int> >& matrix) {
	// write code here
	for(int i=1;i<matrix.size();++i){
		matrix[i][0] += matrix[i-1][0];
		for(int j=1;j<matrix[0].size();++j){
			matrix[0][j] += matrix[0][j-1];
			matrix[i][j] = min(matrix[i-1][j],matrix[i][j-1]) + matrix[i][j];
		}
	}
	return matrix[matrix.size()-1][matrix[0].size()-1];
}
```