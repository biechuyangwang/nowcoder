# [最小覆盖子串](https://www.nowcoder.com/practice/c466d480d20c4c7c9d322d12ca7955ac)
[题解](./main_1.cpp)

```cpp
/*
* 滑动窗口
* 1 窗口扩张，包含所有字符停止
* 2 窗口收缩，如果发现不包含所有字符，则更新最小左边界和最小窗口长度
* 然后重复1 2，直到遍历结束。
*/
```

## 最小覆盖子串
```cpp
string minWindow(string S, string T) {
	// write code here
	unordered_map<char,int> mp,num;
	for(auto x : T) mp[x]++;  // 统计T中各字符的数量
	int l = 0,r = -1,cnt = 0,n = S.size(), m = T.size();
	int minL = -1, minLength = n+1;  // 边界情况
	while(r < n-1){  // 内部有++符号，所有需要控制边界
		while(r < n-1 && cnt < m){  // 未包含所有字符
			if(++num[S[++r]] <= mp[S[r]]) cnt += 1;  // 字符出现，切未满足数量要求，扩张窗口。
		}
		while(l <= r && cnt == m){  // 窗口满足要求
			if(r-l+1 < minLength){  // 更新最小窗口长度
				minL = l;
				minLength = r-l+1;
			}
			if(--num[S[l]] < mp[S[l]]) cnt--;  // 收缩时，删掉该字符就不满足数量要求的情况
			l++;  // 收缩窗口
		}
	}
	return minL == -1 ? "" : S.substr(minL,minLength);
}
```