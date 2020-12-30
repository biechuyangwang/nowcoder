# [数据流的中位数](https://www.nowcoder.com/practice/8c5e99acb1fa4bc3a342cd321100c0cd)
[题解](./main_1.cpp)

## 思路
```cpp
/*
* 用两个优先队列（堆），每个堆存一半的数据
* 一个存小的那半，保证最大的在上面（大顶堆）
* 一个存大的那半，保证最小的在上面（小顶堆）
* 保证小顶堆的大小比大顶堆最多大1个，或者相等
*/
```

## 题解
```cpp
class Solution {
public:
    /**
     * the medians
     * @param operations int整型vector<vector<>> ops
     * @return double浮点型vector
     */
    priority_queue<int,vector<int>,less<int> >l;  // top是最大的
    priority_queue<int,vector<int>,greater<int> >h;  // top是最小的
    vector<double> flowmedian(vector<vector<int> >& operations) {
        // write code here
        vector<double>res;
        for(auto v : operations){
            if(v[0]==1) addNum(v[1]);
            else res.push_back(findMedian());
        }
        return res;
    }
    void addNum(int num){
        l.push(num);
        h.push(l.top());
        l.pop();  // 数据从小到大的一个插入过程，右边的堆大小+1
        if(l.size() < h.size()){  // 当不平衡，则把右边的一个移动到左边
            l.push(h.top());
            h.pop();
        }
    }
    double findMedian(){
        if(!l.size()){
            return -1;
        }
        if(l.size() == h.size())  // 分奇偶算中位数
            return (double)(l.top()+h.top())/2;
        else return l.top();
    }
};
```
