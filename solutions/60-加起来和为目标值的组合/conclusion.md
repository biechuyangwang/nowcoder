# [加起来和为目标值的组合](https://www.nowcoder.com/practice/75e6cd5b85ab41c6a7c43359a74e869a)
[题解](./main_1.cpp)

## 思路
```cpp
/*
* dfs
* 需要保存路径，记得push和pop
*/
```

## dfs
```cpp
class Solution {
public:
    void dfs(vector<int>& num, int target, vector<vector<int> >&res, vector<int>&tmp, int start){
        if(target==0){
            res.push_back(tmp);
            return;
        }
        if(start >= num.size()) return;
        for(int i=start;i<num.size();++i){
            if(i>start && num[i]==num[i-1]) continue;  // 处理i-1的情况
            if(num[i]<=target){  // 边界条件，剪枝
                tmp.push_back(num[i]);
                dfs(num,target-num[i],res,tmp,i+1);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> >res;
        vector<int>tmp;
        if(num.size()==0) return res;
        sort(num.begin(),num.end());
        dfs(num, target, res, tmp, 0);  // 带数组的回溯，加上idx来剪枝
        return res;
    }
};
```