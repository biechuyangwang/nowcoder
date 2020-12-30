# [求平方根](https://www.nowcoder.com/practice/09fbfb16140b40499951f55113f2166c)
[题解](./main_1.cpp)

## 二分法
```cpp
int sqrt(int x) {
    if(x < 0)
        return -1;
    long low = 0;
    long high = x;
    long mid = 0;
    while(low <= high) {
        mid = ((high + low) >> 1);
        if((mid * mid <= x && (mid + 1) * (mid + 1) > x))
            return mid;
        else if(mid * mid > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}
```  
## 牛顿法(收敛快)
```cpp
int sqrt(int x) {
    long r = x;
    while(r*r > x) r = (r + x/r)>>1;
    return r;
}
```