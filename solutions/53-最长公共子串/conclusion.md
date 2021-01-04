# [最长公共子串](https://www.nowcoder.com/practice/b49c3dc907814e9bbfa8437c251b028e)
[题解](./main_1.cpp)

## 动归方程
```cpp
/*
* dp[i][j] = dp[i-1][j-1]+1
* dp[i][j] = 0
* 注意空串返回"-1"
* dp开辟空间(m+1,n+1)，方便处理i-1的问题
*/
```

## 题解
```cpp
string LCS(string str1, string str2) {
    // write code here
    int m = str1.size();
    int n = str2.size();
    vector<vector<int> >dp(m+1, vector<int>(n+1,0));  // 由于需要和空串比较
    int maxlen = 0, end = 0;
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=0;
            if(dp[i][j]>maxlen){
                maxlen = dp[i][j];
                end = j-1;
            }
        }
    }
    string r;
    if(maxlen==0) return "-1";
    else r = str2.substr(end-maxlen+1, maxlen);
    return r;
}
```
