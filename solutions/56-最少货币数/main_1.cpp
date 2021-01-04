/*
* author： 李俊
* time：2020/12/31
*
* 换钱的最少货币数
*/

/*
* 注意事项
*/

/*
* for i->target:
*   for j->a.size()-1:
*       if i>=a[j]:
*           dp[i] = min(dp[i],dp[i-a[j]]+1)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 最少货币数
     * @param arr int整型vector the array
     * @param aim int整型 the target
     * @return int整型
     */
    int minMoney(vector<int>& arr, int aim) {
        // write code here
        vector<int>dp(aim+1,aim+1);
        dp[0]=0;
        for(int i=1;i<=aim;++i){
            for(int j=0;j<arr.size();++j){
                if(arr[j]<=i)
                dp[i] = min(dp[i],dp[i-arr[j]]+1);
            }
        }
        return dp[aim]==aim+1?-1:dp[aim];
    }
};


int main(){
	vector<int>input = {5,2,3};
	int target = 20; 
	Solution ss;
    auto res = ss.minMoney(input,target);
    cout << res;
	return 0;
}

/*
* output 1:
* 4
*/