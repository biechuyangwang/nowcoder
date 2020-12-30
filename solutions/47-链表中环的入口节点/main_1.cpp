/*
* author： 李俊
* time：2020/12/21
*
* 链表中环的入口节点
*/

/*
* 注意事项
*/

/*
* 快慢指针
* 环的长度为b
* fast=slow=head;
* 相遇点为t
* 一个指针放在t，一个放在起点，以相同的速度前进，经过t时间， 一定在t点相遇
* 但是在此之前一定会在环的入口先相遇，这样就找到环的入口了。
*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
		if(head==nullptr) return nullptr;
        ListNode *slow=head,*fast=head;
        while(fast!=nullptr && fast->next!=nullptr){  // 仅用考虑fast 
        	fast = fast->next->next;
			slow = slow->next;
			if(fast == slow){
				fast = head;
				while(fast!=slow){
					fast = fast->next;
					slow = slow->next;
				}
				return slow;
			} 
		}
		return nullptr;
    }
};

int main(){
	
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(4);
	ListNode *node5 = new ListNode(5);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node3;
	ListNode *input = node1;
	
	Solution ss;
    auto res = ss.detectCycle(input);
	cout << res->val << endl;
	return 0;
}

/*
* output 1:
* 3
*/