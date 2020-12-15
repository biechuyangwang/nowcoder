# [反转链表](https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca)
[题解](./main_1.cpp)

## 反转链表  
```cpp
ListNode* ReverseList(ListNode* pHead) {
	ListNode* pre = nullptr;
	auto cur = pHead, post = pHead;
	while(cur){
		post = cur->next;
		cur->next = pre;
		pre = cur;
		cur = post;
	}
	return pre;
}
```