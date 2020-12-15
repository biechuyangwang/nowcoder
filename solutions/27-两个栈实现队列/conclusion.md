# [两个栈实现队列](https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6)
[题解](./main_1.cpp)

## 栈实现队列
```cpp
class Solution {
public:
	void push_(int node){
		this.stack1.push(node);
	}
	int pop_(){
		if(this.stack1.empty() && this.stack2.empty()) return -1;
		if(this.stack2.empty()){
			while(!this.stack1.empty()){
				this.stack2.push(this.stack1.top());
				this.stack1.pop();
			}
		}
		int res = this.stack2.top();
		this.stack2.pop();
		return res;
	}
private:
	stack<int>stack1;
	stack<int>stack2;
};
```