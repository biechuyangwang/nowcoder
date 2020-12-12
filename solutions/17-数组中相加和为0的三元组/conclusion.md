# [数组中相加和为0的三元组](https://www.nowcoder.com/practice/345e2ed5f81d4017bbb8cc6055b0b711)
[题解](./main_1.cpp)

## 动归方程
```
先排序，然后利用双指针的方式遍历。
```

```cpp
vector<vector<int> > threeSum(vector<int> &num) {
	vector<vector<int>>res;
	vector<int>pre;
	vector<int>cur;
	sort(num.begin(),num.end());
	for(int i=0;i<num.size();++i){
		if(i==0 || num[i]!=num[i-1]){  // 避免第一个值相同导致的重复结果
			int left = i+1,right = num.size()-1;
			while(left < right){
				if(num[i]+num[left]+num[right]==0){
					cur = {num[i], num[left], num[right]};
					if(cur != pre) res.push_back(cur);  // 避免后两个值相同导致的重复结果
					pre = cur;
					left++;
					right--;
				}else if(num[i]+num[left]+num[right]<0) left++;
				else right--;
			}
		}	
	}
	return res;
}
```