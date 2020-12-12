/*
* author： 李俊
* time：2020/12/12
*
* 动态规划
*/

/*
* 注意事项
*/

/*
* 动归方程
* i<=j
* 
* dp[i,i] = 1
* if dp[i+1,j-1]=-1
*   dp[i][j] = -1 
* else 
*   if a[i] = a[j]
*       dp[i,j] = dp[i+1,j-1]+1
*   else 
*       dp[i,j] = -1
* 由于dp[i,j]依赖于下左，所以循环要右上(外层向右，也就是j，内层i)
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e9+7;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class cmp1{
public:
	bool operator()(const pair<int,int> x, const pair<int,int> y){
		return x.first > y.first;
	}
}; 

class cmp2{
public:
	bool operator()(const int x, const int y){
		return x > y;
	}
}; 


class Solution {
public:
    int getLongestPalindrome(string A, int n) {
    	int res=0;
    	if(n==0) return res;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;++i) dp[i][i]=1;
        for(int j=1;j<n;++j){
        	for(int i=j-1;i>=0;--i){
				if(dp[i+1][j-1]==-1) dp[i][j]=-1;
				else{
					if(A[i]==A[j]) dp[i][j] = dp[i+1][j-1] + 2;
					else dp[i][j]=-1;
					res = max(res,dp[i][j]);
				}
			}
		}
		for(auto x : dp){
			for(auto val : x)
				cout << val << " ";
			cout << endl;
		}
		return res; 
    }
};


int main(){
//	vector<int>input = {0,1,2,3,4,-1,-1,5}; 
//	string input = "abc1234321ab";
	string input = "babcaaccabab";
	int n = 12; 
//	vector<int>res;
	
	Solution s;
    auto res = s.getLongestPalindrome(input,n);
//    for(auto val : res)
//		cout << val << " ";
	cout << res;
	cout << endl;
	return 0;
}

/*
* output 1:
* 5
*/