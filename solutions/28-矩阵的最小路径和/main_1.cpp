/*
* author： 李俊
* time：2020/12/14
*
* 矩阵的最小路径和
*/

/*
* 注意事项
*/

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

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
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
};

int main(){
	vector<vector<int>>input = {{1,3,5,9},{8,1,3,4},{5,0,6,1},{8,8,4,0}};

	Solution ss;
    auto res = ss.minPathSum(input);
    
    cout << res;
	cout << endl;
	return 0;
}

/*
* output 1:
* 12
*/