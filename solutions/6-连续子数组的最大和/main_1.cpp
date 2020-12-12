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
* f(x) = max{a(x),f(x-1)+a(x)}
* f(x)表示以a(x)结尾的子数组的最大和。子数组不能为空。
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e9+7;
class Solution {
public:  // 动态规划
    int FindGreatestSumOfSubArray_1(vector<int> array) {
        int res = array[0];
        int len = array.size();
        vector<int>dp(len);
        dp[0] = array[0];
        for(int i=0;i<len;++i){
            dp[i] = max(array[i], dp[i-1]+array[i]);
            res = res < dp[i] ? dp[i] : res;
        }
        return res;
    }
    int FindGreatestSumOfSubArray_2(vector<int> array) {
        int res = array[0];
        int x,x_1=array[0];
        for(int i=1;i<array.size();++i){
            x = max(array[i], x_1+array[i]);
            res = max(res, x);
            x_1 = x;
        }
        return res;
    }
};

int main(){
	vector<int>input = {1,-2,3,10,-4,7,2,-5};
//	vector<int>input = {-11,-2,-3,-10,-4,-7,-2,-5};
	int res;
	
	Solution s;
	// res = s.FindGreatestSumOfSubArray_1(input);
    res = s.FindGreatestSumOfSubArray_2(input);
	cout << res << endl;
	return 0;
}

/*
* output 1:
* 18
*
* output 2:
* -2
*/