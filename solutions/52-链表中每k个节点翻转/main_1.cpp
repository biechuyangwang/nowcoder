/*
* author： 李俊
* time：2020/12/30
*
* 链表中每k个节点翻转
*/

/*
* 注意事项
*/

/*
* 
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
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverse(ListNode* first, ListNode* last){  // last是不在k范围内
        ListNode* pre = nullptr;
        while(first!=last){
            ListNode* tmp = first->next;
            first->next = pre;
            pre = first;
            first = tmp;
        }
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
        if(!head) return nullptr;
        ListNode* node = head;
        for(int i=0;i<k;++i){
            if(!node) return head;  // 链表长度小于k不处理
            node = node->next;
        }
        ListNode *newHead = reverse(head,node);  // 正常的链表反转
        head->next = reverseKGroup(node, k);  // 递归处理每一段
        return newHead;  // 第一段的表头
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
	ListNode *input = node1;
	int k=2; 

	Solution ss;
    auto res = ss.reverseKGroup(input,k);
    while(res!=nullptr){
    	cout << res->val << " ";
		res = res->next; 
	}
	return 0;
}

/*
* output 1:
* 2 1 4 3 5
*/