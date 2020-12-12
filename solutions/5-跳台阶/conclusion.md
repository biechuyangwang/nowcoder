# [跳台阶](https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4)
[题解](./main_1.cpp)

扩展：
[动态规划问题]()

## 1 动态方程式

```formula
f(x) = 1                if x=0,1
f(x) = f(x-1) + f(x-2)  if other
```

## 2 递归方法

```cpp
int recursionjumpFloor(int number) {
    if(number==0 || number==1) return 1;
    return jumpFloor(number-2) + jumpFloor(number-1);
}
```

## 3 优化降维(去除重复计算)

```cpp
int jumpFloor(int number) {
    int n_2=1,n_1=1,result=0;
    if(number==0||number==1) return 1;
    else{
        for(int i=2;i<=number;i++){
            result = n_2+n_1;
            n_2 = n_1;
            n_1 = result;
        }
    }
    return result;
}
```