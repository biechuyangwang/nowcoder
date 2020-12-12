/*
* author： 李俊
* time：2020/12/11
*
* hash map 
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
    /**
     * 
     * @param numbers int整型vector 
     * @param target int整型 
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        vector<int>res;
        unordered_map<int,int>ump;
        for(int i=0;i<numbers.size();++i){
        	if(ump.count(target-numbers[i])==1){
        		cout << target-numbers[i] << endl;
        		cout << ump.at(target-numbers[i]) << endl; 
        		res.push_back(1+ump.at(target-numbers[i]));
        		res.push_back(1+i);
        		return res; 
			} 
			ump[numbers[i]] = i;
		}
		return res;
    }
};

int main(){
	vector<int>input = {3,1,2,4};
	int target = 6;
	vector<int>res;
	
	Solution s;
	// res = s.FindGreatestSumOfSubArray_1(input);
    res = s.twoSum(input, target);
	cout << res[0] << " " << res[1] << endl;
	return 0;
}

/*
* output 1:
* 3,4 
*/