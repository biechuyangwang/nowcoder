# [最长公共子序列](https://www.nowcoder.com/practice/6d29638c85bb4ffd80c020fe244baf11)
[题解](./main_1.cpp)

## 动归方程
```cpp
/*
* dp[i][j] = dp[i-1][j-1]+1 if s[i]=s[j]
* dp[i][j] = max(dp[i-1][j], dp[i][j-1]) others
*/
```

## 题解
```cpp
string LCS(string s1, string s2) {
    // write code here
    int m = s1.size();
    int n = s2.size();
    if(m==0 || n==0) return "-1";
    string res;
    vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
    for(int i=1;i<=m;++i){
        for(int j=1;j<=m;++j){
            if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    while(m!=0 && n!=0){
        if(s1[m-1]==s2[n-1]){
            res.push_back(s1[m-1]);
            m--;
            n--;
        }else if(dp[m-1][n] > dp[m][n-1]){
            m--;
        }else n--;
    }
    if(res.size()==0) return "-1";
    reverse(res.begin(), res.end());
    return res;
}
```