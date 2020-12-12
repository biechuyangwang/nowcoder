/*
* author： 李俊
* time：2020/12/11
*
* 动态规划
*/

/*
* 注意事项
*/

/*
* 动归方程
* f(x) = max{a(x)-a(x-1),f(x-1)+a(x)-a(x-1)}
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e9+7;
class Solution {
public:
    /**
     * 
     * @param prices int整型vector 
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        // write code here
        int x_1 = 0;
        int x = 0;
        int res = 0;
        for(int i=1;i<prices.size();++i){
            x = max(prices[i]-prices[i-1],x_1+prices[i]-prices[i-1]);
            res = max(res, x);
            x_1 = x;
        }
        return res;
    }
};

int main(){
	vector<int>input = {1,4,2};
//	vector<int>input = {4,3,2};
	int res;
	
	Solution s;
	// res = s.FindGreatestSumOfSubArray_1(input);
    res = s.maxProfit(input);
	cout << res << endl;
	return 0;
}

/*
* output 1:
* 3 
*/