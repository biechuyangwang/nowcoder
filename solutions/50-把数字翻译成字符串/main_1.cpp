/*
* author： 李俊
* time：2020/12/30
*
* 把数字翻译成字符串
*/

/*
* 注意事项
*/

/*
* 
* dp[i] = 0                 if a[i]='0' and a[i-1]='0'
* dp[i] = dp[i-1]+dp[i-2]   if a[i-1]='1' or (a[i-1]='2' and a[i]<='6')
* 因为涉及到i-2的值，所以需要处理i<2的情况，可以单独处理
* dp[i] = dp[i-1]           other
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 解码
     * @param nums string字符串 数字串
     * @return int整型
     */
    int solve(string nums) {
        // write code here
        if(nums.size()==0) return 0;
        if(nums[0]=='0') return 0;
        vector<int>dp(nums.size()+1);
        dp[0] = 1;
        for(int i=1;i<nums.size();++i){
            dp[i] = dp[i-1];
            if(nums[i]=='0'){
                if(nums[i-1]=='0') return 0;
            }else{
                if((nums[i-1]=='1')||(nums[i-1]=='2'&&nums[i]<='6')){
                    dp[i] += i > 1?dp[i-2] :1;  // 区别前两位
                }
            }
        }
        return dp[nums.size()-1];
    }
};


int main(){
	string input = "31717126241541717";

	Solution ss;
    auto res = ss.solve(input);
    cout << res;
	return 0;
}

/*
* output 1:
* 192
*/