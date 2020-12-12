# [最长回文子串](https://www.nowcoder.com/practice/b4525d1d84934cf280439aeecc36f4af)
[题解](./main_1.cpp)

## 动归方程
```
/*
* 动归方程
* i<=j
* 
* dp[i,i] = 1
* if dp[i+1,j-1]=-1
*   dp[i][j] = -1 
* else 
*   if a[i] = a[j]
*       dp[i,j] = dp[i+1,j-1]+1
*   else 
*       dp[i,j] = -1
* 由于dp[i,j]依赖于下左，所以循环要右上(外层向右，也就是j，内层i)
*/
```

```cpp
    int getLongestPalindrome(string A, int n) {
    	int res=0;
    	if(n==0) return res;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;++i) dp[i][i]=1;
        for(int j=1;j<n;++j){
        	for(int i=j-1;i>=0;--i){
				if(dp[i+1][j-1]==-1) dp[i][j]=-1;  // 用-1来表示不是回文串，0用来表示空串
				else{
					if(A[i]==A[j]) dp[i][j] = dp[i+1][j-1] + 2;
					else dp[i][j]=-1;
					res = max(res,dp[i][j]);
				}
			}
		}
		// for(auto x : dp){
		// 	for(auto val : x)
		// 		cout << val << " ";
		// 	cout << endl;
		// }
		return res; 
    }
```