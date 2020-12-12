/*
* author： 李俊
* time：2020/12/11
*
* 栈操作
*/

/*
* 注意事项
*/

/*
* 用另一个栈来保存最小元素
*/

#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>

const int MAXN = 1e9+7;
class Solution {
public:
    /**
     * return a array which include all ans for op3
     * @param op int整型vector<vector<>> operator
     * @return int整型vector
     */
    vector<int> getMinStack(vector<vector<int> >& op) {
        // write code here
        vector<int>res;
        if(op.size()==0) return res;
        for(auto pr : op){
        	if(pr[0]==1) this->push_(pr[1]);
        	else if(pr[0]==2) this->pop_();
        	else if(pr[0]==3) res.push_back(this->getMin());
		}
		return res;
    }
    void push_(int val){
    	this->ori_stack.push(val);
    	if(this->min_stack.empty()) this->min_stack.push(val);
    	else if(val <= this->min_stack.top()) this->min_stack.push(val);
	}
	void pop_(){
		int val = this->ori_stack.top();
		this->ori_stack.pop();
		if(val == this->min_stack.top()) this->min_stack.pop();
	}
	int getMin(){
		return this->min_stack.top();
	}
private:
	stack<int>min_stack;
	stack<int>ori_stack;
};

int main(){
	vector<vector<int>>input = {{1,3},{1,2},{1,1},{3},{2},{3}};
	vector<int>res;
	
	Solution s;
    res = s.getMinStack(input);
    for(auto val : res)
		cout << val << " ";
	cout << endl;
	return 0;
}

/*
* output 1:
* 1 2
*/