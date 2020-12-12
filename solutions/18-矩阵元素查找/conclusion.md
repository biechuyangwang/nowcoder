# [矩阵元素查找](https://www.nowcoder.com/practice/3afe6fabdb2c46ed98f06cfd9a20f2ce)
[题解](./main_1.cpp)

## 有序二维数组查找
```
从左下或者右上开始遍历
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