/*
* author： 李俊
* time：2020/12/18
*
* 数组中未出现的最小正整数
*/

/*
* 注意事项
*/

/*
* 原地hash
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return int整型vector<vector<>>
     */
	int minNumberdisappered(vector<int>& arr){
		int n = arr.size();
		for(int i=0;i<n;++i){
			while(arr[i]>0 && arr[i]<n && arr[i]!=arr[arr[i]-1]) swap(arr[i],arr[arr[i]-1]);
		}
		for(int i=0;i<n;++i)
			if(arr[i]!=arr[arr[i]-1]) return i+1;
		return n+1;
	}
};

int main(){
	vector<int>input = {-1,2,3,4};
	Solution ss;
    auto res = ss.minNumberdisappered(input);
    cout << res;

	return 0;
}

/*
* output 1:
* 1
*/