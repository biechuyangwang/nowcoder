/*
* author： 李俊
* time：2020/12/13
*
* 归并k路链表
*/

/*
* 注意事项
*/

/*
* 归并链表
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

int main(){
	vector<ListNode *>input;
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	node1->next = node2;
	node2->next = node3;
	input.push_back(node1);
	
	ListNode *node4 = new ListNode(4);
	ListNode *node5 = new ListNode(5);
	ListNode *node6 = new ListNode(6);
	node4->next = node5;
	node5->next = node6;
	input.push_back(node4);
	
	Solution ss;
    auto res = ss.mergeKLists(input);

	while(res){
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;
	return 0;
}

/*
* output 1:
* 1 2 3 4 5 6
*/