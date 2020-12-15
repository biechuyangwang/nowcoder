/*
* author： 李俊
* time：2020/12/14
*
* 链表反转
*/

/*
* 注意事项
*/

/*
* 需要三个指针，类似于双向链表的操作
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
	ListNode* ReverseList(ListNode* pHead){
		// write code here
		ListNode *pre = nullptr;
		ListNode *cur = pHead, *post = pHead;
		while(cur){
			post = cur->next;
			cur->next = pre;
			pre = cur;
			cur = post;
		} 
		return pre;  // pre已经更新为cur了 
	}
};

int main(){
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	node1->next = node2;
	node2->next = node3;
	ListNode *input = node1;
	
	Solution ss;
    auto res = ss.ReverseList(input);

	while(res){
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;
	return 0;
}

/*
* output 1:
* 3 2 1
*/