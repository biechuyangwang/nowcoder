/*
* author： 李俊
* time：2020/12/30
*
* 数据流的中位数 
*/

/*
* 注意事项
*/

/*
* 用两个优先队列（堆），每个堆存一半的数据
* 一个存小的那半，保证最大的在上面（大顶堆）
* 一个存大的那半，保证最小的在上面（小顶堆）
* 保证小顶堆的大小比大顶堆最多大1个，或者相等
*/

#include<bits/stdc++.h>
using namespace std;

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
        l.pop();
        if(l.size() < h.size()){
            l.push(h.top());
            h.pop();
        }
    }
    double findMedian(){
        if(!l.size()){
            return -1;
        }
        if(l.size() == h.size())
            return (double)(l.top()+h.top())/2;
        else return l.top();
    }
};


int main(){
	vector<vector<int>>input = {{2},{1,1},{2}};

	Solution ss;
    auto res = ss.flowmedian(input);
    
    for(auto val : res) cout << val << " ";
	return 0;
}

/*
* output 1:
* -1,1
*/