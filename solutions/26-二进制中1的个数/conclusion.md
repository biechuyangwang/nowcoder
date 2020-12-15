# [二进制中1的个数](https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8)
[题解](./main_1.cpp)

通过掩码的位运算得到每位的结果  

位运算：  
0x0A=10=0101  
0x02=2=010  
0x0A&0x02=2  

1&1=1    
0&1=0  
0&0=0  
1|1=1  
0|1=1  
0|0=0  
1^1=0  
0^1=1  
0^0=0  

## 二进制中1的个数
```cpp
int  NumberOf1(int n) {
    int res=0;
    int mask=0x01;
    while(mask!=0){
        if(mask&n) res++;
        mask = mask << 1;
    }
    return res;
}
```