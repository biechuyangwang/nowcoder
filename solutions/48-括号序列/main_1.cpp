/*
* author： 李俊
* time：2020/12/21
*
* 括号序列 
*/

/*
* 注意事项
*/

/*
* 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // write code here
        if(s.size()==0) return true;
        stack<char>st;
        char c;
        for(int i=0;i<s.size();++i){
        	if(st.empty()){
        		st.push(s[i]);
        		continue;
			}
        	c = st.top();
        	if((s[i]==')' && c=='(') || (s[i]==']' && c=='[') || (s[i]=='}' && c=='{')) st.pop();
        	else st.push(s[i]);
		}
		return st.empty();
    }
};

int main(){
	string input = "[()][]";
	Solution ss;
    auto res = ss.isValid(input);
    cout << res;
	return 0;
}

/*
* output 1:
* true
*/