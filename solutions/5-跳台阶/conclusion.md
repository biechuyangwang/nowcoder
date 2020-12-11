# [跳台阶](https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4)
[动态规划问题]()

## 1 动态方程式

![](https://latex.codecogs.com/png.latex?\dpi{400}f(x)=\begin{cases}
1 & \text{ if } x=0,1 \\
f(x-1)+f(x-2) & \text{ if } x=\text{other} 
\end{cases})


```formula
f(x) = 1    (x=0,1)
f(x) = f(x-1) + f(x-2)  other
```
