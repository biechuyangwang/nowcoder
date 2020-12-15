# [大数加法](https://www.nowcoder.com/practice/11ae12e8c6fe48f883cad618c2e81475)
[题解](./main_1.cpp)

## 大数加法
处理方法类似于归并


```cpp
string solve(string s, string t) {
	// write code here
	string res;
	int size_max = max(s.size(),t.size());
	int size_min = min(s.size(),t.size());
	int flag = 0;  //保存进位 
	int tmp = 0;  // 保存当前位的和 
	int i=s.size()-1,j=t.size()-1;
	while(i>=0 && j>=0){
		tmp = s[i--]-'0' + t[j--]-'0' + flag;
		flag = tmp/10;
		tmp = tmp%10;
		res.push_back(tmp+'0');
	}
	while(i>=0){
		tmp = s[i--]-'0' + flag;
		flag = tmp/10;
		tmp = tmp%10;
		res.push_back(tmp+'0');
	}
	while(j>=0){
		tmp = t[j--]-'0' + flag;
		flag = tmp/10;
		tmp = tmp%10;
		res.push_back(tmp+'0');
	}
	if(flag) res.push_back('1');
	reverse(res.begin(),res.end());
	return res;
}
```