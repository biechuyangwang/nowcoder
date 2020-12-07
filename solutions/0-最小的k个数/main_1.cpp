/*
* author： 李俊
* time：2020/12/07
*
* 排序
*/

/*
sort: 
sort并不是简单的快速排序，它对快速排序进行了优化。
此外，它还结合了插入排序和推排序。
系统会根据数据形式和数据量自动选择合适的排序方法。
它每次排序中不只选择一种方法，比如给一个数据量较大的数组排序，
开始采用快速排序，分段递归，
分段之后每一段的数据量达到一个较小值后它就不继续往下递归，
而是选择插入排序，如果递归的太深，他会选择推排序。
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> ret;
        if (k==0 || k>input.size()) return ret;
        sort(input.begin(), input.end());
        return vector<int>({input.begin(), input.begin()+k});   
    }
};

int main(){
    // input
    vector<int>inputs={4,5,1,6,2,7,3,8};
    int k = 4;

    // fuction
    Solution s;
    vector<int>ret = s.GetLeastNumbers_Solution(inputs,k);
    
    // output
    for(auto i : ret) cout << i << " ";
    return 0;
}