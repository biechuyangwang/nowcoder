/*
* author： 李俊
* time：2020/12/07
*
* 堆排序
*/

/*
priority_queue<int, vector<int>, cmp>pq;
使用优先队列和函数对象的方式模拟堆
*/
#include<bits/stdc++.h>
using namespace std;

class cmp{
public:
    bool operator()(int& x, int& y){
        return x > y;
    }
};

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> ret;
        if (k==0 || k > input.size()) return ret;
        priority_queue<int, vector<int>, cmp> pq;
        for (auto val : input) {
            if (pq.size() < k) {
                pq.push(val);
            }
            else {
                if (val < pq.top()) {
                    pq.pop();
                    pq.push(val);
                }
            }
        }

        while (!pq.empty()) {
            ret.push_back(pq.top());
            pq.pop();
        }
        return ret;
    }
};

int main(){
    // input
    vector<int>inputs={4,5,1,6,2,7,3,8};
    int k = 4;

    // fuction
    Solution s;
    vector<int>res = s.GetLeastNumbers_Solution(inputs,k);
    
    // output
    for(auto i : res) cout << i << " ";
    return 0;
}