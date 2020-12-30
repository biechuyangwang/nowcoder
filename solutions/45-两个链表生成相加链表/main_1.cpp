/*
* author： 李俊
* time：2020/12/18
*
* 链表大数相加
*/

/*
* 注意事项
*/

/*
* 不用在乎空间，就用栈存
* 在乎空间，使用反转链表的方式
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
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here
        stack<int>s1;
        stack<int>s2;
        stack<int>s3;
        ListNode *p = head1;
        int len1=0,len2=0;
		while(p){
			s1.push(p->val);
			len1++;
			p = p->next;
		}
		p=head2;
		while(p){
			s2.push(p->val);
			len2++;
			p = p->next;
		}
		int flag = 0;
		int a,b,x;
		while(!s1.empty() && !s2.empty()){
			a = s1.top();
			b = s2.top();
			s1.pop();
			s2.pop();
			x = (a+b+flag)%10;
			flag = (a+b+flag)/10;
			s3.push(x);
		}
		while(!s1.empty()){
			a = s1.top();
			s1.pop();
			x = (a+flag)%10;
			flag = (a+flag)/10;
			s3.push(x);
			len1++;
		}
		while(!s2.empty()){
			b = s2.top();
			s2.pop();
			x = (b+flag)%10;
			flag = (b+flag)/10;
			s3.push(x);
			len2++;
		}
		if(len2>len1){
			head1 = head2;
		}
		if(flag==1){
			ListNode *node = new ListNode(1);
			s3.push(1);
			node->next = head1;
			head1 = node;
		}
		p=head1;
		while(!s3.empty()){
			p->val = s3.top();
			s3.pop();
			p = p->next;
		}
		return head1;
    }
};

int main(){

	ListNode *nodea9 = new ListNode(9);
	ListNode *nodea3 = new ListNode(3);
	ListNode *nodea7 = new ListNode(7);
	ListNode *nodeb6 = new ListNode(6);
	ListNode *nodeb3 = new ListNode(3);
	nodea9->next = nodea3;
	nodea3->next = nodea7;
	nodeb6->next = nodeb3;
	ListNode *input1 = nodea9;
	ListNode *input2 = nodeb6;

	Solution ss;
    auto res = ss.addInList(input1,input2);

	while(res){
		cout << res->val << " ";
		res = res->next;
	}
	return 0;
}

/*
* output 1:
* 100
*/