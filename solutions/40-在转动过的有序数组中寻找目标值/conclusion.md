# [在转动过的有序数组中寻找目标值](https://www.nowcoder.com/practice/7cd13986c79d4d3a8d928d490db5d707)
[题解](./main_1.cpp)

思路：  
```cpp
/*
* a[m]>=a[l]
*   a[l]<=t<a[m] -> r = m-1
*   other -> l = m+1
* a[m]<=a[r]
*   a[m]<=t<a[r] -> l= m+1
*   other -> r=m-1
* 可以通过一些方法去合并使代码简洁，但是逻辑就不简洁了，没有必要。
*/
```

## 题解
```cpp
int search(int* A, int n, int target) {
    // write code here
    int l = 0,r = n-1;  // 如果后续要和r比较，则选择n-1赋值
    while(l<=r){
        int m = l+r >> 1;
        cout << A[l] << " " << A[m] << " " << A[r] << endl; 
        if(A[m]==target) return m;
        if(A[m]>=A[l]){
            if(A[l]<=target && target < A[m]) r=m-1;
            else l=m+1;
        }else if(A[m]<=A[r]){
            if(A[m]<=target && target<A[r]) l=m+1;
            else r=m-1;
        }
    }
    return -1;
}
```

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