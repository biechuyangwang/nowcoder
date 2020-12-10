/*
* author： 李俊
* time：2020/12/07
*
* 快排思想
*/

/*
快速排序每次partition就会确定一个位置
void quicksort(vector<int> &input, int l, int r){  // 注意下标
    if(l<r){	
        int pivot = input[r-1];
        int i = l;
        for (int j=l; j<r-1; ++j) {
            if (input[j] < pivot) {
                swap(input[i++], input[j]);
            }
        }
        swap(input[i], input[r-1]);
        partition(input, l, i);
        partition(input, i+1, r);
    }
}
quicksort(inputs, 0, inputs.size());
for(auto i : inputs) cout << i << " ";
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partition(vector<int> &input, int l, int r) {
        int pivot = input[r-1];
        int i = l;
        for (int j=l; j<r-1; ++j) {
            if (input[j] < pivot) {
                swap(input[i++], input[j]);  // 判断成功一次，i往后移动一位，表示pivot的待插入位置
            }
        }
        swap(input[i], input[r-1]);
        return i;  // 返回的是位置
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> ret;
        if (k==0 || k > input.size()) return ret;
        int l = 0, r = input.size();
        while (l < r) {
            int p = partition(input, l, r);
            if (p+1 == k) {  // 位置+1才是序号
                return vector<int>(input.begin(), input.begin()+k);  // 因为不需要有序
            }
            if (p+1 < k) {
                l = p + 1;
            }else {
                r = p;
            }
        }
        return ret;
    }
};

int main(){
    // input
    vector<int>inputs={4,5,1,6,2,7,3,8};
    int k = 4;

    // fuction
    Solution s;
    vector<int>res = s.GetLeastNumbers_Solution(inputs,k);
    
    // output
    for(auto i : res) cout << i << " ";
    return 0;
}