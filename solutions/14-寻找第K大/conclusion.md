# [寻找第K大](https://www.nowcoder.com/practice/e016ad9b7f0b45048c58a9f27ba618bf)
[题解](./main_1.cpp)

## 堆排
```cpp
int findKth(vector<int> a, int n, int k) {
	// write code here
	int res=-1;
	if(k>n) return res;
	priority_queue<int, vector<int>, greater<int>>pq;
	for(auto val : a){
		if(pq.size() < k) pq.push(val);
		else if(val >= pq.top()){
			pq.pop();
			pq.push(val);
		}
	}
	return pq.top();
}
```

## top k
参考[最小的k个数](../1-最小的k个数/conclusion.md)