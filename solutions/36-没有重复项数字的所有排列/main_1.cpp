/*
* author： 李俊
* time：2020/12/15
*
* 没有重复项的数字的所有排列
*/

/*
* 注意事项
*/

/*
* 双指针
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool next_perm(vector<int>& num) {
            int i = num.size()-1, j = num.size()-1;
            while(i-1 >= 0 && num[i] < num[i-1])i--;  // 确定起始点，逆序就降低左边界
            if(i == 0)
                return false;
            i--;
            while(num[j] < num[i])j--;  // 右边界逆序就降低右边界
            std::swap(num[i], num[j]);
            reverse(num.begin()+i+1, num.end());  // 还原后半部分
            return true;
        }
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > ans;
        do {
            ans.push_back(num);
        }while(next_perm(num));
        return ans;
    }
};

int main(){
	vector<int>input = {1,2,3};
	
	Solution ss;
    auto res = ss.permute(input);

	for(auto v : res){
		for(auto val : v) cout << val << " ";
		cout << endl;
	}

	return 0;
}

/*
* output 1:
* [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/