# [没有重复项数字的所有排列](https://www.nowcoder.com/practice/4bcf3081067a4d028f95acee3ddcd2b1)
[题解](./main_1.cpp)

双指针问题，逆序交换过程

## 没有重复项数字的所有排列
```cpp
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
```  