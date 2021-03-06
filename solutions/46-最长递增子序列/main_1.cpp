/*
* author： 李俊
* time：2020/12/19
*
* 最长递增子序列
*/

/*
* 注意事项
*/

/*
* 求长度动归方程如下：
* dp[0] = 1
* pre[0] = -1;
* path = -1;
* for i -> 1:n-1
*   for j -> 0:i-1
*       if a[i] > a[j] && dp[i] < dp[j]+1
*           dp[i] = dp[j]+1
*           pre[i] = j
*   if manlen < dp[i]
*       maxlen = dp[i]
*       path = i
* 
* while(1)
*   if pre[path]==-1
*       res[--maxlen] = a[path]
*       break
*   res[--maxlen] = a[path]
*   path = pre[path]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * retrun the longest increasing subsequence
     * @param arr int整型vector the array
     * @return int整型vector
     */
//    vector<int> LIS(vector<int>& arr) {
	vector<int> LIS(vector<int>& arr) {
        // write code here
        vector<int>res;
        if(arr.size()==0) return res;
        vector<int>dp(arr.size()+1,0);
        vector<int>maxEnd(1,arr[0]);  // maxEnd[k]表示存放长度为k+1的递增子序列的最后一个元素。(可保证字典排序最小) 
        dp[0]=1;
        int path = -1;
        for(int i=1;i<arr.size();++i){
        	if(arr[i] > maxEnd.back()){
        		dp[i] = maxEnd.size()+1;
        		maxEnd.push_back(arr[i]); 
			}else{
				auto idx = lower_bound(maxEnd.begin(),maxEnd.end(),arr[i])-maxEnd.begin();  // 保证字典排序最小 
				maxEnd[idx] = arr[i];
				dp[i] = idx + 1;
			}
		}
		int maxlen = maxEnd.size();
		res = vector<int>(maxlen);
		vector<int>vres(maxlen);
		for(int i=dp.size()-1;i>=0;--i){
			if(dp[i]==maxlen) {
				res[maxlen-1] = arr[i];
				--maxlen;
			}
		}
		int j=0;
		for(int i=0;i<dp.size();++i){
	        if(dp[i]==j+1){
	            vres[j]  = arr[i];
	            j++;
	        }
    	}
		return res;
    }
};

int main(){
	vector<int>input = {2,1,5,3,6,4,8,9,7};
	Solution ss;
    auto res = ss.LIS(input);
    
    for(auto val : res) cout << val << " ";
	return 0;
}

/*
* res:
* 1,3,4,8,9
* vres:
* 2,3,4,8,9
*/