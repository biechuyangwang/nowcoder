# [最大正方形](https://www.nowcoder.com/practice/0058c4092cec44c2975e38223f10470e)
[题解](./main_1.cpp)

## 思路
```cpp
/*
* 1 1
* 1 1
*
* 1 1 1
* 1 1 1
* 1 1 1
* 
* 1 1 2
* 1 2 2
* 1 2 3
*
* 该位置为右下角坐标的边长
*/
```

## 题解
```cpp
int solve(vector<vector<char> >& matrix) {
    // write code here
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int> >dp(m, vector<int>(n,0));
    int maxn=0;
    for(int i=0;i<m;++i) dp[i][0]=matrix[i][0]-'0';
    for(int i=0;i<n;++i) dp[0][i]=matrix[0][i]-'0';
    for(int i=1;i<m;++i){
        for(int j=1;j<n;++j){
            if(matrix[i][j]=='1'){
                dp[i][j]=min(dp[i-1][j-1], dp[i-1][j]);
                dp[i][j]=min(dp[i][j],dp[i][j-1])+1;
                maxn = max(maxn, dp[i][j]);
            }
        }
    }
    return maxn*maxn;
}
```
