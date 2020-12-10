/*
* author： 李俊
* time：2020/12/10
*
* 滑动窗口(用unordered_map)
*/

/*
* 注意事项
* 滑动窗口需要控制每次最多+1或者窗口收缩
*/

/*
*
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr) {
        // write code here
        int res = 0, tmp = 0, left = -1;
        unordered_map<int, int>umap;
        for(int right=0;right<arr.size();++right){
            // 这里可以使用自己查找的方式，从right-1查找第一个与right相同的index，
            // 但是效率没有map中的at效率高
            /*
            left = right-1;
            while(left>=0 && arr[right]!=arr[left]) left--;
            tmp  = tmp < right-left ? tmp+1 : right-left;  // 一次最多+1，或者变小
            res = max(res, tmp);
            */
            if(umap.count(arr[right])>0){
                left = max(left, umap.at(arr[right]));  // 不能查到left左边去
            }
            umap[arr[right]] = right;
            res = max(res, right-left);
        }
        return res;
    }
};

int main(){
    vector<int>input={2,2,3,4,3};
    int res;

    Solution s;
    res = s.maxLength(input);
    cout << res << endl;
    return 0;
}