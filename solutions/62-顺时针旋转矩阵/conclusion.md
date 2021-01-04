# [顺时针旋转矩阵](https://www.nowcoder.com/practice/2e95333fbdd4451395066957e24909cc)
[题解](./main_1.cpp)

## 思路
```cpp
/*
* mat[j][n-i-1] = mat[i][j];
* 如果对空间复杂度有要求，则使用高位暂存结果
*/
```

## 题解
```cpp
vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
    // write code here
    // 原地交换的一种策略（位运算）
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            mat[j][n-i-1] += ((mat[i][j] & 0b111111111) << 9);  // 寄存器思想
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            mat[i][j] >>= 9;
        }
    }
    return mat;
}
```