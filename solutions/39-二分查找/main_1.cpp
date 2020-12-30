/*
* author： 李俊
* time：2020/12/17
*
* 大数加法 
*/

/*
* 注意事项
*/

/*
* 归并的形式 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 二分查找
     * @param n int整型 数组长度
     * @param v int整型 查找值
     * @param a int整型vector 有序数组
     * @return int整型
     */
    int lower_bound_(int n, int v, vector<int>& a) {  // 题目修正过了
        // write code here
        if(n<0) return 0;
        int l = 0,r = n;
        while(l<r){
        	int m = l+r >> 1;
        	if(a[m]<v) l = m+1;
        	else r = m;
		}
        return l+1;
    }
};

int main(){
	vector<int>input = {1,2,4,4,5};
	
	int n=5;
	int val=4;
	Solution ss;
    auto res = ss.lower_bound_(n,val,input);
    cout << res;
    

	return 0;
}

/*
* output 1:
* 3
*/