# [最少货币数](https://www.nowcoder.com/practice/3911a20b3f8743058214ceaa099eeb45)
[题解](./main_1.cpp)

## 动归方程
```cpp
/*
* for i->target:
*   for j->a.size()-1:
*       if i>=a[j]:
*           dp[i] = min(dp[i],dp[i-a[j]]+1)
*/
```

## 题解
```cpp
int minMoney(vector<int>& arr, int aim) {
    // write code here
    vector<int>dp(aim+1,aim+1);
    dp[0]=0;
    for(int i=1;i<=aim;++i){
        for(int j=0;j<arr.size();++j){
            if(arr[j]<=i)
            dp[i] = min(dp[i],dp[i-arr[j]]+1);
        }
    }
    return dp[aim]==aim+1?-1:dp[aim];
}
```
