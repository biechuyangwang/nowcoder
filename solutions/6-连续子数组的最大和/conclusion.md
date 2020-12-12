# [连续子数组的最大和](https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484)
[题解](./main_1.cpp)

扩展：
[动态规划问题]()

## 1 动态方程式

```formula
f(x) = max{a(x),f(x-1)+a(x)}
其中f(x)表示以a(x)结尾的字数组的最大和。
本题的子数组是最少含有一个元素的数组，子数组不能为空。
```

## 2 递归方法

```cpp
int FindGreatestSumOfSubArray_1(vector<int> array) {
    int res = array[0];
    int len = array.size();
    vector<int>dp(len);
    dp[0] = array[0];
    for(int i=0;i<len;++i){
        dp[i] = max(array[i], dp[i-1]+array[i]);
        res = res < dp[i] ? dp[i] : res;
    }
    return res;
}
```

## 3 优化降维(去除重复计算)

```cpp
int FindGreatestSumOfSubArray(vector<int> array) {
    int res = array[0];
    int x,x_1=array[0];
    for(int i=1;i<array.size();++i){
        x = max(array[i], x_1+array[i]);
        res = max(res, x);
        x_1 = x;
    }
    return res;
}
```