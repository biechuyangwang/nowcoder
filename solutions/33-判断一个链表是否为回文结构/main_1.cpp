/*
* author： 李俊
* time：2020/12/14
*
* 回文链表
*/

/*
* 注意事项
*/

/*
* 使用反转一半的链表会节省空间，但是没必要 
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
    /**
     * 
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode* head) {
        // write code here
        vector<int>tmp;
        ListNode *p = head;
        while(p){
        	tmp.push_back(p->val);
        	p = p->next;
		}
		p=head;
		for(int i=tmp.size()-1;i>=0;--i){
			if(p->val != tmp[i]) return false;
			p = p->next;
		}
		return true;
    }
};

int main(){
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(3);
	ListNode *node5 = new ListNode(2);
	ListNode *node6 = new ListNode(1);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	
	Solution ss;
    auto res = ss.isPail(node1);
    cout << res;

	return 0;
}

/*
* output 1:
* 1
*/