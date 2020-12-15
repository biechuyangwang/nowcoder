# [股票最大收益2](https://www.nowcoder.com/practice/4892d3ff304a4880b7a89ba01f48daf9)
[题解](./main_1.cpp)
```
动态找到一个切割点，切割点左边最大和右边最大的收益和的最大值。
有一个技巧就是，计算右边的时候可以选择逆序
第一个vector[i]表示以i结尾，第二个vector[i]表示以i开始，这样就构成一个以i分割的样例了。
```
## 动归方程
```cpp
for i <- 1:n-1
min_value = min(min_value, a[i]);
dp1[i] = max(dp1[i-1],a[i]-min_valuie);

for i <- n-2:0
max_value = max(max_value, a[i]);
dp2[i] = max(dp2[i+1],max_valuie-a[i]);

for i <- 0:n
res = max(res,dp1[i]+dp2[i]);
```

# 解法
```cpp
int maxProfit(vector<int>& prices) {
	// write code here
	int res=0;
	int n = prices.size();
	int min_money = prices[0];
	vector<int>ins(n,0);
	for(int i=1;i<n;++i){
		min_money = min(min_money, prices[i]);
		ins[i] = max(ins[i-1],prices[i]-min_money);
	}
	int max_money = prices[n-1];
	vector<int>des(n,0);
	for(int i=n-2;i>=0;--i){
		max_money = max(max_money, prices[i]);
		des[i] = max(des[i+1],max_money-prices[i]);
	}
	for(int i=0;i<n;++i) res = max(res,ins[i]+des[i]);
	return res;
}
```