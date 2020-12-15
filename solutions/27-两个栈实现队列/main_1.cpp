/*
* author： 李俊
* time：2020/12/14
*
* 栈模拟队列
*/

/*
* 注意事项
*/

/*
* 两个栈模拟队列
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	void push_(int node){
		this->stack1.push(node);
	}
	int pop_(){
		if(this->stack1.empty() && this->stack2.empty()) return -1;
		if(this->stack2.empty()){
			while(!this->stack1.empty()){
				this->stack2.push(this->stack1.top());
				this->stack1.pop();
			}
		}
		int res = this->stack2.top();
		this->stack2.pop();
		return res;
	}
private:
	stack<int>stack1;
	stack<int>stack2;
};

int main(){

	Solution ss;
	ss.push_(1);
	ss.push_(2);
	int res = ss.pop_();
    
    cout << res;

	cout << endl;
	return 0;
}

/*
* output 1:
* 1
*/