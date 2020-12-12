/*
* author： 李俊
* time：2020/12/12
*
* 双指针
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

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
    	vector<vector<int>>res;
    	vector<int>pre;
    	vector<int>cur;
    	sort(num.begin(),num.end());
    	for(int i=0;i<num.size();++i){
    		if(i==0 || num[i]!=num[i-1]){  // 避免第一个值相同导致的重复结果
    			int left = i+1,right = num.size()-1;
	    		while(left < right){
	    			if(num[i]+num[left]+num[right]==0){
	    				cur = {num[i], num[left], num[right]};
	    				if(cur != pre) res.push_back(cur);  // 避免后两个值相同导致的重复结果
	    				pre = cur;
	    				left++;
	    				right--;
					}else if(num[i]+num[left]+num[right]<0) left++;
					else right--;
				}
			}	
		}
		return res;
    }
};


int main(){
	vector<int>input = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
//	vector<int>input = {-3,0,1,1,2,3}; 
//	vector<int>input = {0,0,0}; 
//	string input = "abc1234321ab";
//	string input = "babcaaccabab";
	int n = 12; 
//	vector<int>res;
	
	Solution s;
    auto res = s.threeSum(input);
//    set<vector<int>>ss(res.begin(),res.end());
//    res.assign(ss.begin(),ss.end());
//    for(auto val : res)
//		cout << val << " ";
//	cout << res;
	for(auto v : res){
		for(auto val : v) cout << val << " ";
		cout << endl;
	}
	cout << endl;
	return 0;
}

/*
* output 1:
* [[-4,-2,6],[-4,0,4],[-4,1,3],[-4,2,2],[-2,-2,4],[-2,0,2]]
*/