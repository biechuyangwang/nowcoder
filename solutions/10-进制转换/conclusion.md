# [进制转换](https://www.nowcoder.com/practice/2cc32b88fff94d7e8fd458b8c7b25ec1)
[题解](./main_1.cpp)


## 进制转换
```cpp
string solve(int M, int N) {
    // write code here
    string t = "0123456789ABCDEF"; 
    string ret = "";
    bool flag = true;
    if((M<0)^(N<0)){  // 用来判断符号位 
        flag = false;
    }
    M = abs(M);
    N = abs(N);
    while(M){
        ret.push_back(t[M%N]);  // 涉及16进制输出问题，查表的方式快
        M = M/N;
    }
    if(!flag) ret.push_back('-');
    reverse(ret.begin(),ret.end());
    return ret;
}
```