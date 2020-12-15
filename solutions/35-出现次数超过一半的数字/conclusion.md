# [出现数字超过一半的数字](https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163)
[题解](./main_1.cpp)

## 超过一半的数字
```cpp
int MoreThanHalfNum_Solution(vector<int> numbers){
	int pre;
	if(numbers.size()==0) return 0;
	int cnt=0;
	for(auto val : numbers){
		if(cnt==0) pre = val;  // 抵消后，需要更新pre
		if(pre==val) cnt++;
		else cnt--;
	}
	cnt=0;
	for(auto val : numbers){
		if(pre==val) cnt++;
	}
	if(cnt >numbers.size()/2) return pre;
	else return 0;
}
```

## 其他方法
hash_map统计，然后判断最大的是否满足要求。  
排序，判断中间的数是否满足要求。  