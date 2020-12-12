# [容器盛水问题](https://www.nowcoder.com/practice/31c1aed01b394f0b8b7734de0324e00f)
[题解](./main_1.cpp)

扩展：
[双指针]()

本题解法是双指针  
其核心是什么时候更新指针，什么时候做累加操作。  
显然遇到低的需要累加操作，遇到高的需要重新判别动左还是右指针。
## 双指针
```cpp
long long maxWater(vector<int>& arr) {
    // write code here
    if(arr.size()<3) return 0;
    long long res = 0;
    int left=0,right=arr.size()-1;
    int m=min(arr[left], arr[right]);
    while(left < right){
        if(arr[left] < arr[right]){  // 判断操作左边还是右边
            left++;  // 操作左边
            if(arr[left] < m) res += m - arr[left];  // 装水还是调整最小值
            else m = min(arr[left], arr[right]);
        }else{
            right--;
            if(arr[right] < m) res += m - arr[right];
            else m = min(arr[left], arr[right]);
        }
    }
    return res;
}
```

## 暴力解法
```cpp

```