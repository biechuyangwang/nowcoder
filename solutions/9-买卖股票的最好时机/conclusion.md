# [买卖股票的最好时机](https://www.nowcoder.com/practice/64b4262d4e6d4f6181cd45446a5821ec)
[题解](./main_1.cpp)

扩展：
参考[连续子数组最大和](../6-连续子数组的最大和/conclusion.md)

## 1 动归方程
```
f(x) = max{a(x)-a(x-1),f(x-1)+a(x)-a(x-1)}
f(x)指第x天买股票最大收益。股票最少持有一天。当利润小于0会取0。
```

## 2 优化去重版
```cpp
int maxProfit(vector<int>& prices) {
    // write code here
    int x_1 = 0;
    int x = 0;
    int res = 0;
    for(int i=1;i<prices.size();++i){
        x = max(prices[i]-prices[i-1],x_1+prices[i]-prices[i-1]);
        res = max(res, x);
        x_1 = x;
    }
    return res;
}
```