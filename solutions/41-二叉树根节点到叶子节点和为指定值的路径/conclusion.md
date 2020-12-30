# [二叉树根节点到叶子节点和为指定值的路径](https://www.nowcoder.com/practice/840dd2dc4fbd4b2199cd48f2dadf930a)
[题解](./main_1.cpp)

思路：  
```cpp
/*
* 典型的先序遍历
* 但是要利用一些中间结果，尽量使用传参的方式而不是返回值的方式
* 模拟栈的时候记得退站
*/
```

## 题解
```cpp
class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return int整型vector<vector<>>
     */
    void dfs(TreeNode *root,vector<vector<int>>&res,vector<int>&cur_path,int sum,int cur_sum){
    	if(!root) return;
    	cur_sum += root->val;
    	cur_path.push_back(root->val);
    	if(!root->left && !root->right && sum == cur_sum) res.push_back(cur_path);
		if(root->left) dfs(root->left, res, cur_path, sum, cur_sum);
		if(root->right) dfs(root->right, res, cur_path, sum, cur_sum); 
    	cur_path.pop_back();
	}
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        // write code here
        vector<vector<int>>res;
        if(!root) return res;
        vector<int>cur_path;
        dfs(root,res,cur_path,sum,0);
        return res;
    }
};
```