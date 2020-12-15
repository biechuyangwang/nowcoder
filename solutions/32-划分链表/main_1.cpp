/*
* author： 李俊
* time：2020/12/14
*
* 划分链表
*/

/*
* 注意事项
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param x int整型 
     * @return ListNode类
     */
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
};

int main(){
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(4);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(2);
	ListNode *node5 = new ListNode(5);
	ListNode *node6 = new ListNode(2);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	int x = 3;
	
	Solution ss;
    auto res = ss.partition(node1,x);

	while(res){
		cout << res->val << " ";
		res = res->next;
	}

	return 0;
}

/*
* output 1:
* 1 2 2 4 3 5
*/