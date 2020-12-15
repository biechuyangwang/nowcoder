# [判断一个链表是否为回文结构](https://www.nowcoder.com/practice/3fed228444e740c8be66232ce8b87c2f)
[题解](./main_1.cpp)

## 判断链表是否是回文结构
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