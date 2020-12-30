# [括号序列](https://www.nowcoder.com/practice/37548e94a270412c8b9fb85643c8ccc2)
[题解](./main_1.cpp)


## 题解
```cpp
bool isValid(string s) {
    // write code here
    if(s.size()==0) return true;
    stack<char>st;
    char c;
    for(int i=0;i<s.size();++i){
        if(st.empty()){  // 注意边界点就行
            st.push(s[i]);
            continue;
        }
        c = st.top();
        if((s[i]==')' && c=='(') || (s[i]==']' && c=='[') || (s[i]=='}' && c=='{')) st.pop();
        else st.push(s[i]);
    }
    return st.empty();
}
```
