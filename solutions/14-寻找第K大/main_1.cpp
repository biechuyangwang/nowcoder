/*
* author： 李俊
* time：2020/12/12
*
* 堆排 
*/

/*
* 注意事项
*/

/*
* 
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e9+7;

class cmp{
public:
	bool operator()(const pair<int,int> x, const pair<int,int> y){
		return x.first > y.first;
	}
}; 

class Solution {
public:
    int findKth(vector<int> a, int n, int k) {
        // write code here
        int res=-1;
        if(k>n) return res;
//        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
//		for(int i=0;i<n;++i){
//        	if(pq.size() < k) pq.push({a[i],i});
//        	else if(a[i] > pq.top().first){
//        		pq.pop();
//        		pq.push({a[i],i});
//			}
//		}
//		return pq.top().second;
		priority_queue<int, vector<int>, greater<int>>pq;
		for(auto val : a){
			if(pq.size() < k) pq.push(val);
			else if(val >= pq.top()){
				pq.pop();
				pq.push(val);
			}
		}
		return pq.top();
    }
};

int main(){
	vector<int>input = {1,3,5,2,2};
	int n = 5;
	int k = 3; 
//	vector<int>res;
	
	Solution s;
    auto res = s.findKth(input,n,k);
//    for(auto val : res)
//		cout << val << " ";
	cout << res;
	cout << endl;
	return 0;
}

/*
* output 1:
* 2
*/