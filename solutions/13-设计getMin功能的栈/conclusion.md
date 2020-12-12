# [设计getMin功能的栈](https://www.nowcoder.com/practice/c623426af02d4c189f92f2a99647bd34)
[题解](./main_1.cpp)

知识点[栈操作]()

用一个额外的栈来维护最小值

## getMin的栈
```cpp
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
```