# [把数字翻译成字符串](https://www.nowcoder.com/practice/046a55e6cd274cffb88fc32dba695668)
[题解](./main_1.cpp)

## 动归方程
```cpp
/*
* 
* dp[i] = 0                 if a[i]='0' and a[i-1]='0'
* dp[i] = dp[i-1]+dp[i-2]   if a[i-1]='1' or (a[i-1]='2' and a[i]<='6')
* 因为涉及到i-2的值，所以需要处理i<2的情况，可以单独处理
* dp[i] = dp[i-1]           other
*/
```

## 题解
```cpp
int solve(string nums) {
    // write code here
    if(nums.size()==0) return 0;
    if(nums[0]=='0') return 0;
    vector<int>dp(nums.size()+1);
    dp[0] = 1;
    for(int i=1;i<nums.size();++i){
        dp[i] = dp[i-1];
        if(nums[i]=='0'){
            if(nums[i-1]=='0') return 0;
        }else{
            if((nums[i-1]=='1')||(nums[i-1]=='2'&&nums[i]<='6')){
                dp[i] += i > 1?dp[i-2] :1;  // 区别前两位
            }
        }
    }
    return dp[nums.size()-1];
}
```
