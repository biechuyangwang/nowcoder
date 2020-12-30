# [数组中未出现的最小正整数](https://www.nowcoder.com/practice/8cc4f31432724b1f88201f7b721aa391)
[题解](./main_1.cpp)

思路：  
```cpp
/*
* 原地hash
*/
```
详见[原地hash](../../ideas/查找.md)

## 题解
```cpp
int minNumberdisappered(vector<int>& arr) {
    // write code here
    // 原地hash
    int n = arr.size();
    for(int i=0;i<n;++i){
        while(arr[i]>0 && arr[i]<n && arr[i]!=arr[arr[i]-1]){  // 前两个保证在1~n范围内
            swap(arr[i],arr[arr[i]-1]); // a[i] = i+1
        }
    }

    for(int i=0;i<n;++i){
        if(arr[i]!=i+1) return i+1;
    }
    return n+1;
}
```