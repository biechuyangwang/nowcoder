# [合并k个已排序的链表](https://www.nowcoder.com/practice/65cfde9e5b9b4cf2b6bafa5f3ef33fa6)
[题解](./main_1.cpp)

参考[排序](../../ideas/排序.md)中的归并排序

## 合并k个已排序的链表
```cpp
class Solution {
public:
	ListNode *mergeList(ListNode *p1, ListNode *p2){
		if(p1==nullptr || p2==nullptr) return p1==nullptr?p2:p1;
		if(p1->val > p2->val) {
			p2->next = mergeList(p1,p2->next);
			return p2;
		}else{
			p1->next = mergeList(p1->next,p2);
			return p1;
		}
	} 
	ListNode *mergeKLists(vector<ListNode *> &lists){
		// write code here
		ListNode *res = nullptr;
		if(lists.size()==0) return res;
		for(auto list : lists) res = mergeList(res, list);
		return res;
	}
};
```