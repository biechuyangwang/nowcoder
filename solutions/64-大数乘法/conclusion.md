# [大数乘法](https://www.nowcoder.com/practice/c4c488d4d40d4c4e9824c3650f7d5571)
[题解](./main_1.cpp)

## 题解
```cpp
string solve(string s, string t) {
    // write code here
    int m = s.size();
    int n = t.size();
    if(m==0 || n==0) return "";
    vector<int>res(m+n,0);
    string ans="";
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            res[i+j] += (s[i]-'0')*(t[j]-'0');  // 模拟手工乘法
        }
    }
    int len = res.size()-1;
    int carry=0;
    for(int i=0;i<=len;++i){
        res[i] += carry;
        carry = res[i]/10;
        res[i] %= 10;
    }
    while(res[len]==0) len--;
    if(len<0) return "0";
    for(int i=len;i>=0;--i) ans += to_string(res[i]);
    return ans;
}
```