# [划分链表](https://www.nowcoder.com/practice/1dc1036be38f45f19000e48abe00b12f)
[题解](./main_1.cpp)

## 划分链表
```cpp
ListNode* partition(ListNode* head, int x) {
	// write code here
	ListNode *list1=new ListNode(0);
	ListNode *list2=new ListNode(0);
	ListNode *p=list1,*q = list2;
	while(head){
		if(head->val<x){
			p->next = head;
			head = head->next;
			p = p->next;
		}else{
			q->next = head;
			head = head->next;
			q = q->next;
		}
	}
	p->next = list2->next;
	q->next = nullptr;
	return list1->next;
}
```