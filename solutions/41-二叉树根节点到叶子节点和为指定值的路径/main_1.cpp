/*
* author： 李俊
* time：2020/12/17
*
* 二叉树根节点到叶子节点和为指定值的路径
*/

/*
* 注意事项
*/

/*
* 典型的先序遍历
* 但是要利用一些中间结果，尽量使用传参的方式而不是返回值的方式
* 模拟栈的时候记得退站
*/

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e9+7;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

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

int main(){
	TreeNode *node1 = new TreeNode(1);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node4 = new TreeNode(4);
	TreeNode *node5 = new TreeNode(5);
	TreeNode *node7 = new TreeNode(7);
	TreeNode *node8 = new TreeNode(8);
	TreeNode *node9 = new TreeNode(9);
	TreeNode *node11 = new TreeNode(11);
	node5->left = node4;
	node5->right = node8;
	node4->left = node1;
	node4->right = node11;
	node8->right = node9;
	node11->left = node2;
	node11->right = node7;
	TreeNode *input = node5;
	
	int val=22;
	Solution ss;
    auto res = ss.pathSum(input,val);

	for(auto v : res){
		for(auto val : v) cout << val << " ";
		cout << endl;
	}

	return 0;
}