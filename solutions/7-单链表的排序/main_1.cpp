/*
* author： 李俊
* time：2020/12/11
*
* 链表排序
*/

/*
* 注意事项
* 使用辅助的空间排序，减少麻烦
* 使用纯链表操作可能会超时
*/

/*
* sortInList1是借助vector去排序
* sortInList2是链表的冒泡排序
*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

const int MAXN = 1e9+7;
class Solution {
public:
    /**
     * 
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode* sortInList1(ListNode* head) {
        // write code here
        ListNode *p = head;
        vector<int>input;
        while(p){
            input.push_back(p->val);
            p = p->next;
        }
        sort(input.begin(),input.end());
        p = head;
        int i=0;
        while(p){
            p->val = input[i++];
            p = p->next;
        }
        return head;
    }
    ListNode* sortInList2(ListNode* head) {
        // write code here
        if(head==nullptr) return head;
        ListNode *vhead = new ListNode(0);
        vhead->next = head;
        ListNode *pre = vhead, *cur=head, *p=head;
        while(p->next!=nullptr){
        	pre = vhead;
			cur = head;
        	while(cur->next!=nullptr){
	        	if(cur->val > cur->next->val){
	        		pre->next = cur->next;
	        		cur->next = cur->next->next;
	        		pre->next->next = cur;
				}
				pre = cur;
				cur = cur->next;
			}
			p = p->next;
		}
        return head;
    }
};

int main(){
	ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(2);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
	ListNode *res;
	
	Solution s;
	// res = s.FindGreatestSumOfSubArray_1(input);
    res = s.sortInList1(node1);
	while(res!=nullptr){
        cout << res->val << " ";
        res = res->next;
    }
	return 0;
}

/*
* output 1:
* 1,2,3,4,5
*/