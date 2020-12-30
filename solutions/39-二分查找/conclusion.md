# [二分查找](https://www.nowcoder.com/practice/7bc4a1c7c371425d9faa9d1b511fe193)
[题解](./main_1.cpp)

题目的函数名有点问题  
upper_bound应该表示第一个大于val的位置  
lower_bound才是第一个大于等于val的位置  

## 二分查找
```cpp
int lower_bound(int n, int v, vector<int>& a) {  // 第一个大于等于v的位置
    // write code here
    if(n<0) return 0;
    int l = 0,r = n;  // 这里r取n是处理只有一个字符的情况
    while(l<r){ 
        int m = l+r >> 1;  // 移位运算优先级低于加法运算，建议括号
        if(a[m]<v) l = m+1;
        else r = m;
    }
    return l+1;
}

int upper_bound(int n, int v, vector<int>& a) {  // 第一个大于v的位置
    // write code here
    if(n<0) return 0;
    int l = 0,r = n;  // 这里r取n是处理只有一个字符的情况
    while(l<r){ 
        int m = l+r >> 1;  // 移位运算优先级低于加法运算，建议括号
        if(a[m]<=v) l = m+1;
        else r = m;
    }
    return l+1;
}

int binary_search(int n, int v, vector<int>& a) {
    // write code here
    if(n<0) return 0;
    int l = 0,r = n;  // 这里r取n是处理只有一个字符的情况
    while(l<r){
        int m = l+r >> 1;
        if(a[m]==v) return m+1;
        else if(a[m]<v) l = m+1;
        else r = m-1;
    }
    return n;
}
/*
* input 
* 5,4,[1,2,4,4,5]
* output
* 3
*/
```  