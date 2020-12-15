# [数组中的最长连续子序列](https://www.nowcoder.com/practice/eac1c953170243338f941959146ac4bf)
[题解](./main_1.cpp)

## 最长连续子序列(排序)
```cpp
int MLS(vector<int>& arr) {
    // write code here
    int res = 0;
    if(arr.size()==0) return res;
    sort(arr.begin(),arr.end());
    int tmp = 1;
    for(int i=1;i<arr.size();++i){
        if(arr[i]==arr[i-1]+1) tmp++;
        res = max(res,tmp);
        if(arr[i] > arr[i-1]+1) tmp=1;
    }
    return res;
}
```